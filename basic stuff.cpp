#include "basic stuff.h"


void InitWindow(int MAJOR_VERSION_OPENGL, int MINOR_VERSION_OPENGL, int width, int height, const char* windowname, float R, float G, float B)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION_OPENGL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION_OPENGL);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, windowname, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window has failed to initialize" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, width, height);

	glad_glClearColor(R, G, B, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}
void updatewindow()
{
	glfwSwapBuffers(window);
}
void drawVertices(GLenum drawingmode, GLint first, GLsizei count) {
	glDrawArrays(drawingmode, first, count);
}

void End()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}