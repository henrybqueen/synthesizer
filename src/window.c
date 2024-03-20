#include <GLFW/glfw3.h>

#include <string.h>

#include "../include/io.h"



GLFWwindow* initWindow(void) {

    
    if (glfwInit() == GLFW_FALSE) {
        printf("Failed to initialize GLFW\n");
        return;
    }


    GLFWwindow* window = glfwCreateWindow(800, 600, "Sound", NULL, NULL);

    if (!window) {
        printf("Failed to create window\n");
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    InputManager inputManager;
    memset(inputManager.keys, 0, sizeof(inputManager.keys));

    glfwSetWindowUserPointer(window, &inputManager);
    

    // Set the key callback
    glfwSetKeyCallback(window, keyCallback);

    return window;

}