/*
  Здесь реализуются функции для ШЕЙДЕРОВ
*/

#include <GL/freeglut.h>

GLuint frag_shader, prog;
bool shader_flag = false;

void switch_shader() {
  if (shader_flag) {
    glUseProgram(0);
  } else {
    glUseProgram(prog);
  }
  shader_flag = !shader_flag;
}

void make_shader(std::string f_shader_str) {
  const char* f_shader_char = f_shader_str.c_str();

  // std::cout << f_shader_char << std::endl;
	frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, &f_shader_char, 0);
  glCompileShader(frag_shader);
	prog = glCreateProgram();
	glAttachShader(prog, frag_shader);
	glLinkProgram(prog);
}
