//
#include <cstdio>
//
GLuint LoadTexture_test(const char * filename, int width = 160, int height = 160) {

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

GLuint LoadTexture(const char * filename, int width, int height)
{
//стандартный bmp 24 бит
GLuint tex;
unsigned char * data;
unsigned char R,G,B;
FILE * file;

//загрузка изображения из .bmp файла
file = fopen(filename, "rb");

if(file == NULL)return 0;
//выделяем память под переменную data
data =(unsigned char *)malloc(width * height * 3);
//смещение для пропуска служебных данных
fseek(file,128,0);
//читаем весь файл file в одну переменную data
fread(data, width * height * 3, 1, file);
//закрываем файл
fclose(file);

//переставляем местами R,G,B значения для правильного отображения цвета
int index;
for(int i = 0; i < width * height ; ++i)
	{
	index = i*3;
	B = data[index]; G = data[index+1]; R = data[index+2];
	data[index] = R; data[index+1] = G; data[index+2] = B;
	}

//создаем текстуру из загруженного изображения
glGenTextures(1, &tex);
glBindTexture(GL_TEXTURE_2D, tex);

// фильтрация текстуры

gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

//текстура создана и поэтому теперь можно
//освобождить память от загруженного изображения
free(data);
return tex;
}
