#ifndef IO_H
#define IO_H

#include <GLFW/glfw3.h>
#include <stdbool.h>

// Declare the keyboard array as extern because its definition is in io.c
extern int keyboard[16];

// InputManager struct definition
typedef struct {
    bool keys[1024];
} InputManager;

// Function prototypes
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
int keyToDegree(int key);

#endif // IO_H
