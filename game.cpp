#include "game.h"
#include "renderer.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <ctime>

Game::Game(int width, int height) : width(width), height(height), score(0) {
    crosshairX = width / 2;
    crosshairY = height / 2;
    srand(static_cast<unsigned>(time(0)));
}

void Game::init() {
    spawnTargets();
}

void Game::update() {
    checkCollisions();
}

void Game::render() {
    Renderer::drawCrosshair(crosshairX, crosshairY);
    for (const auto& target : targets) {
        Renderer::drawTarget(target.x, target.y, target.size, target.isHit);
    }
}

void Game::handleMouseMovement(double xpos, double ypos) {
    crosshairX = static_cast<float>(xpos);
    crosshairY = static_cast<float>(ypos);
}

void Game::handleMouseClick() {
    for (auto& target : targets) {
        if (!target.isHit &&
            crosshairX > target.x - target.size && crosshairX < target.x + target.size &&
            crosshairY > target.y - target.size && crosshairY < target.y + target.size) {
            target.isHit = true;
            score++;
        }
    }
}

void Game::spawnTargets() {
    for (int i = 0; i < 5; ++i) {
        targets.push_back({rand() % width, rand() % height, 20.0f, false});
    }
}

void Game::checkCollisions() {
    // Placeholder for future collision logic
}
