#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtx/component_wise.hpp>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace glm;

struct Vertex
{
    vec3 position;
    vec2 texcoord;
    vec3 normal;
};

struct VertRef
{
    VertRef( int v, int vt, int vn )
        : v(v), vt(vt), vn(vn)
    { }
    int v, vt, vn;
};

vector< Vertex > LoadOBJ( istream& in )
{
    vector< Vertex > verts;

    vector< vec4 > positions( 1, vec4( 0, 0, 0, 0 ) );
    vector< vec3 > texcoords( 1, vec3( 0, 0, 0 ) );
    vector< vec3 > normals( 1, vec3( 0, 0, 0 ) );
    string lineStr;
    while( getline( in, lineStr ) )
    {
        istringstream lineSS( lineStr );
        string lineType;
        lineSS >> lineType;

        // vertex
        if( lineType == "v" )
        {
            float x = 0, y = 0, z = 0, w = 1;
            lineSS >> x >> y >> z >> w;
            positions.push_back( vec4( x, y, z, w ) );
        }

        // texture
        if( lineType == "vt" )
        {
            float u = 0, v = 0, w = 0;
            lineSS >> u >> v >> w;
            texcoords.push_back( vec3( u, v, w ) );
        }

        // normal
        if( lineType == "vn" )
        {
            float i = 0, j = 0, k = 0;
            lineSS >> i >> j >> k;
            normals.push_back( normalize( vec3( i, j, k ) ) );
        }

        // polygon
        if( lineType == "f" )
        {
            vector< VertRef > refs;
            string refStr;
            while( lineSS >> refStr )
            {
                istringstream ref( refStr );
                string vStr, vtStr, vnStr;
                getline( ref, vStr, '/' );
                getline( ref, vtStr, '/' );
                getline( ref, vnStr, '/' );
                int v = atoi( vStr.c_str() );
                int vt = atoi( vtStr.c_str() );
                int vn = atoi( vnStr.c_str() );
                v  = (  v >= 0 ?  v : positions.size() +  v );
                vt = ( vt >= 0 ? vt : texcoords.size() + vt );
                vn = ( vn >= 0 ? vn : normals.size()   + vn );
                refs.push_back( VertRef( v, vt, vn ) );
            }

            if( refs.size() < 3 )
            {
                // error, skip
                continue;
            }

            // triangulate, assuming n>3-gons are convex and coplanar
            VertRef* p[3] = { &refs[0], NULL, NULL };
            for( size_t i = 1; i+1 < refs.size(); ++i )
            {
                p[1] = &refs[i+0];
                p[2] = &refs[i+1];

                // http://www.opengl.org/wiki/Calculating_a_Surface_Normal
                vec3 U( positions[ p[1]->v ] - positions[ p[0]->v ] );
                vec3 V( positions[ p[2]->v ] - positions[ p[0]->v ] );
                vec3 faceNormal = normalize( cross( U, V ) );

                for( size_t j = 0; j < 3; ++j )
                {
                    Vertex vert;
                    vert.position = vec3( positions[ p[j]->v ] );
                    vert.texcoord = vec2( texcoords[ p[j]->vt ] );
                    vert.normal   = ( p[j]->vn != 0 ? normals[ p[j]->vn ] : faceNormal );
                    verts.push_back( vert );
                }
            }
        }
    }

    return verts;
}

int btn;
ivec2 startMouse;
ivec2 startRot, curRot;
ivec2 startTrans, curTrans;
void mouse(int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        btn = button;
        startMouse = ivec2( x, glutGet( GLUT_WINDOW_HEIGHT ) - y );
        startRot = curRot;
    }
    if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
    {
        btn = button;
        startMouse = ivec2( x, glutGet( GLUT_WINDOW_HEIGHT ) - y );
        startTrans = curTrans;
    }
}

void motion( int x, int y )
{
    ivec2 curMouse( x, glutGet( GLUT_WINDOW_HEIGHT ) - y );
    if( btn == GLUT_LEFT_BUTTON )
    {
        curRot = startRot + ( curMouse - startMouse );
    }
    else if( btn == GLUT_RIGHT_BUTTON )
    {
        curTrans = startTrans + ( curMouse - startMouse );
    }
    glutPostRedisplay();
}

vector< Vertex > model;
void display()
{
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    glTranslatef( curTrans.x / w * 2, curTrans.y / h * 2, 0 );
    gluPerspective( 60, ar, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0, 0, -10 );

    glPushMatrix();
    {
        glRotatef( curRot.x % 360, 0, 1, 0 );
        glRotatef( -curRot.y % 360, 1, 0, 0 );

        // object
        glColor3ub( 255, 191, 0 );
        glEnableClientState( GL_VERTEX_ARRAY );
        glEnableClientState( GL_TEXTURE_COORD_ARRAY );
        glEnableClientState( GL_NORMAL_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(Vertex), &model[0].position );
        glTexCoordPointer( 2, GL_FLOAT, sizeof(Vertex), &model[0].texcoord );
        glNormalPointer( GL_FLOAT, sizeof(Vertex), &model[0].normal );
        glDrawArrays( GL_TRIANGLES, 0, model.size() );
        glDisableClientState( GL_VERTEX_ARRAY );
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );
        glDisableClientState( GL_NORMAL_ARRAY );

        // bounding cube
        glDisable( GL_LIGHTING );
        glColor3ub( 255, 255, 255 );
        glutWireCube( 7 );
        glEnable( GL_LIGHTING );
    }
    glPopMatrix();

    glutSwapBuffers();
}

// return the min/max points of pts
template< typename Vec >
pair< Vec, Vec > GetExtents( const Vec* pts, size_t stride, size_t count )
{
    unsigned char* base = (unsigned char*)pts;
    Vec pmin( *(Vec*)base );
    Vec pmax( *(Vec*)base );
    for( size_t i = 0; i < count; ++i, base += stride )
    {
        const Vec& pt = *(Vec*)base;
        pmin = glm::min( pmin, pt );
        pmax = glm::max( pmax, pt );
    }

    return make_pair( pmin, pmax );
}

// centers geometry around the origin
// and scales it to fit in a size^3 box
template< typename Vec >
void CenterAndScale( Vec* pts, size_t stride, size_t count, const typename Vec::value_type& size )
{
    typedef typename Vec::value_type Scalar;

    // get min/max extents
    pair< Vec, Vec > exts = GetExtents( pts, stride, count );

    // center and scale
    const Vec center = ( exts.first * Scalar( 0.5 ) ) + ( exts.second * Scalar( 0.5f ) );

    const Scalar factor = size / glm::compMax( exts.second - exts.first );
    unsigned char* base = (unsigned char*)pts;
    for( size_t i = 0; i < count; ++i, base += stride )
    {
        Vec& pt = *(Vec*)base;
        pt = ( ( pt - center ) * factor );
    }
}

int main( int argc, char **argv )
{
    ifstream ifile( "monkey.obj" );
    model = LoadOBJ( ifile );
    CenterAndScale( &model[0].position, sizeof( Vertex ), model.size(), 7 );

    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "OBJ" );
    glutDisplayFunc( display );
    glutMouseFunc( mouse );
    glutMotionFunc( motion );

    glEnable( GL_DEPTH_TEST );

    // set up "headlamp"-like light
    glShadeModel( GL_SMOOTH );
    glEnable( GL_COLOR_MATERIAL );
    glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    GLfloat position[] = { 0, 0, 1, 0 };
    glLightfv( GL_LIGHT0, GL_POSITION, position );

    glPolygonMode( GL_FRONT, GL_FILL );
    glPolygonMode( GL_BACK, GL_LINE );
    glutMainLoop();
    return 0;
}
