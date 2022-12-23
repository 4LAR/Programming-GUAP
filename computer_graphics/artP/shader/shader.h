/*
  Здесь реализуются функции для ШЕЙДЕРОВ
*/

#include <GL/freeglut.h>
#include <vector>

GLuint frag_shader, prog;
bool shader_flag = false;

int utime_vareble = 0;

void switch_shader() {
  if (shader_flag) {
    glUseProgram(0);
  } else {
    glUseProgram(prog);
  }
  shader_flag = !shader_flag;
}

bool make_shader(GLenum type, std::string f_shader_str) {
  const char* f_shader_char = f_shader_str.c_str();

	frag_shader = glCreateShader(type);
	glShaderSource(frag_shader, 1, &f_shader_char, 0);
  glCompileShader(frag_shader);

  GLint isCompiled = 0;
  glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &isCompiled);

  // если шейдер не скомпилировался
  if(isCompiled == GL_FALSE) {
  	GLint maxLength = 0;
  	glGetShaderiv(frag_shader, GL_INFO_LOG_LENGTH, &maxLength);

  	std::vector<GLchar> errorLog(maxLength);
  	glGetShaderInfoLog(frag_shader, maxLength, &maxLength, &errorLog[0]);

    // вывод ошибок
    for (int i = 0; i < errorLog.size(); i++)
      std::cout << errorLog.at(i);

  	glDeleteShader(frag_shader);
  	return false;
  }

	prog = glCreateProgram();
	glAttachShader(prog, frag_shader);
	glLinkProgram(prog);

  return true;
}
