//
#include <cstdio>
//
GLuint LoadTexture(const char * filename, int width = 160, int height = 160) {

  GLuint texture;

  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

  for(int i = 0; i < width * height; ++i) {
    int index = i*3;
    unsigned char B,R;
    B = data[index];
    R = data[index+2];

    data[index] = R;
    data[index+2] = B;

  }


  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );

  return texture;
}

// GLuint LoadTexture(const char *FileName)
// {
//   GLuint textura_id;
//
//   FILE *F;
//   /* Открываем файл */
//   if ((F = fopen(FileName, "rb")) == NULL)
//     return 0;
//   /*Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну */
//   fseek(F, 18, SEEK_SET);
//   fread(&(get_textura.W), 2, 1, F);
//   fseek(F, 2, SEEK_CUR);
//   fread(&(get_textura.H), 2, 1, F);
//
//   printf("%d x %d\n", get_textura.W, get_textura.H);
//
//   /* Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой */
//   if ((get_textura.Image = (unsigned char *) malloc(sizeof(unsigned char)*3*get_textura.W * get_textura.H)) == NULL)
//   {
//     fclose(F);
//     return NULL;
//   }
//   /* Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя */
//   fseek(F, 30, SEEK_CUR);
//   fread(get_textura.Image, 3, get_textura.W * get_textura.H, F);
//
//   glGenTextures(1, &textura_id);
//   glBindTexture(GL_TEXTURE_2D, textura_id);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//   gluBuild2DMipmaps(GL_TEXTURE_2D, 3, get_textura.W, get_textura.H, GL_RGB, GL_UNSIGNED_BYTE, get_textura.Image);
//   free(get_textura.Image);
//   fclose(F);
//
//   return textura_id;
// }

// GLuint LoadTexture(GLuint tex, const char * filename, int width, int height)
// {
// //bmp 24 bit
// unsigned char * data;
// unsigned char R,G,B;
// FILE * file;
//
// //open .bmp
// file = fopen(filename, "rb");
//
// if(file == NULL)return 0;
// //get memory for data
// data =(unsigned char *)malloc(width * height * 3);
// //data skip offset
// fseek(file,128,0);
// //read file to data
// fread(data, width * height * 3, 1, file);
// //close file
// fclose(file);
//
// //transpose R,G,B values
// int index;
// for(int i = 0; i < width * height ; ++i)
//     {
//     index = i*3;
//     B = data[index]; G = data[index+1]; R = data[index+2];
//     data[index] = R; data[index+1] = G; data[index+2] = B;
//     }
//
// //create a texture
// glGenTextures(1, &tex);
// glBindTexture(GL_TEXTURE_2D, tex);
// gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data);
//
// //texture filtering
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
// glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
// //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//
// //free memory
// free(data);
// return tex;
// }
