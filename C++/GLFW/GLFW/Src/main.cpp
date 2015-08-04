#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Graphics/shader.h>
#include <Graphics/ShaderProgram.h>
#include <Maths/Vec2.h>
#include <vector>


#define WIDTH 800
#define HEIGHT 600
#define Log(x) std::cout << x << std::endl;

using namespace OpenGL::Graphics;
using namespace OpenGL::Maths;
int main(int argc, char** argv) {
	GLFWwindow* window;
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW!" << std::endl;
		return EXIT_FAILURE;
	}
	window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);

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

	Vec2 size = Vec2(800, 600);
	std::cout << size << std::endl;
	Log(size.Length());
	Log(size.Normalize());

	std::vector<Vec2> verticies;
	verticies.push_back(Vec2(-1, 1));
	verticies.push_back(Vec2(1, 1));
	verticies.push_back(Vec2(-1, -1));
	verticies.push_back(Vec2(1, -1));
	Vec2 test;
	test = test.Normalize(verticies[0]);

	Log(test);
	Log(test.AngleRadians());
	Log(test.AngleDegrees());

	GLint sizeID = glGetUniformLocation(program.ID(), "uSize");
	glUniform2f(sizeID, WIDTH, HEIGHT);
	GLint offset = glGetUniformLocation(program.ID(), "offset");
	glUniform2f(offset, 0,0);
	GLint scale = glGetUniformLocation(program.ID(), "scale");
	glUniform1f(scale, 2.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLE_STRIP);
		for (size_t i = 0; i < verticies.size(); i++)
		{
			glVertex2f(verticies[i].X,verticies[i].Y);
		}
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	std::cin.ignore();
	return 0;

}
