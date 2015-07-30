#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <shader.h>
#include <ShaderProgram.h>

using namespace OpenGL::Graphics;
int main(int argc, char** argv) {
	GLFWwindow* window;
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW!" << std::endl;
		return EXIT_FAILURE;
	}
	window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);

	if (!window)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewInit();

	Shader vert = Shader(GL_VERTEX_SHADER, "data/shaders/basic.vert");
	Shader frag = Shader(GL_FRAGMENT_SHADER, "data/shaders/fractal.frag");

	ShaderProgram program = ShaderProgram(vert, frag);
	program.Enable();

	GLint size = glGetUniformLocation(program.ID(), "uSize");
	glUniform2f(size, 800, 600);
	GLint offset = glGetUniformLocation(program.ID(), "offset");
	glUniform2f(offset, 0,0);
	GLint scale = glGetUniformLocation(program.ID(), "scale");
	glUniform1f(scale, 2.0f);


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(1.0f, -1.0f);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	std::cin.ignore();
	return 0;

}
