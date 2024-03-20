
#include <GLFW/glfw3.h>
#include <stdbool.h>

extern int keyboard[18] = {
    GLFW_KEY_A, GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_E, GLFW_KEY_D, GLFW_KEY_F, GLFW_KEY_T, GLFW_KEY_G, 
    GLFW_KEY_Y, GLFW_KEY_H, GLFW_KEY_U, GLFW_KEY_J, GLFW_KEY_K, GLFW_KEY_O, GLFW_KEY_L, GLFW_KEY_P,
    GLFW_KEY_SEMICOLON, GLFW_KEY_APOSTROPHE
};

typedef struct {
    bool keys[1024];
} InputManager;


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);

    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            inputManager->keys[key] = true;
        } else if (action == GLFW_RELEASE) {
            inputManager->keys[key] = false;
        }
    }
}

int keyToDegree(int key) {
    switch(key) {
        case GLFW_KEY_A:
            return 0;
        case GLFW_KEY_W:
            return 1;
        case GLFW_KEY_S:
            return 2;
        case GLFW_KEY_E:
            return 3;
        case GLFW_KEY_D:
            return 4;
        case GLFW_KEY_F:
            return 5;
        case GLFW_KEY_T:
            return 6;
        case GLFW_KEY_G:
            return 7;
        case GLFW_KEY_Y:
            return 8;
        case GLFW_KEY_H:
            return 9;
        case GLFW_KEY_U:
            return 10;
        case GLFW_KEY_J:
            return 11;
        case GLFW_KEY_K:
            return 12;
        case GLFW_KEY_O:
            return 13;
        case GLFW_KEY_L:
            return 14;
        case GLFW_KEY_P:
            return 15;
        case GLFW_KEY_SEMICOLON:
            return 16;
        case GLFW_KEY_APOSTROPHE:
            return 17; 
        default:
            return -1;
    }
}

