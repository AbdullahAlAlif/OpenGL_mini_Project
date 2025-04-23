#include <GLFW/glfw3.h>
#include "renderer.h"
#include "game.h"

// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

Game game(WINDOW_WIDTH, WINDOW_HEIGHT);

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shooting Gallery", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set mouse callback
    glfwSetCursorPosCallback(window, mouse_callback);

    // Initialize game and renderer
    Renderer::init();
    game.init();

    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Update and render the game
        game.update();
        game.render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    game.handleMouseMovement(xpos, ypos);
}
