#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static GLFWwindow* window;
void InitWindow(int MAJOR_VERSION_OPENGL, int MINOR_VERSION_OPENGL, int width, int height, const char* windowname, float R, float G, float B);
void updatewindow();
void drawVertices(GLenum drawingmode, GLint first, GLsizei count);
void End();

