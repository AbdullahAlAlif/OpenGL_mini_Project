#include "renderer.h"
#include <GLFW/glfw3.h>

void Renderer::init() {
    glOrtho(0, 800, 600, 0, -1, 1); // Set orthographic projection
}

void Renderer::drawCrosshair(float x, float y) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x - 10, y);
    glVertex2f(x + 10, y);
    glVertex2f(x, y - 10);
    glVertex2f(x, y + 10);
    glEnd();
}

void Renderer::drawTarget(float x, float y, float size, bool isHit) {
    glColor3f(isHit ? 0.0f : 0.0f, isHit ? 1.0f : 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glEnd();
}
