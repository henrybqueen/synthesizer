#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h> // GLFW library for window management and OpenGL context

#include "io.h"

GLFWwindow* initWindow(void);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // WINDOW_H
