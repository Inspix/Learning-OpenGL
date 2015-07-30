#include <iostream>
#include <GLFW/glfw3.h>
#include <GLEW/glew.h>

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

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.69f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	std::cin.ignore();
	return 0;
}
