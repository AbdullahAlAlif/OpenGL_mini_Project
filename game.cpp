#include "game.h"
#include "renderer.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <ctime>

Game::Game(int width, int height) : width(width), height(height), score(0), timer(60.0f), isGameOver(false) {
    crosshairX = width / 2;
    crosshairY = height / 2;
    srand(static_cast<unsigned>(time(0)));
}

void Game::init() {
    spawnTargets();
}

void Game::update() {
    if (isGameOver) return;

    timer -= 0.016f; // Assuming 60 FPS
    if (timer <= 0) {
        isGameOver = true;
    }

    for (auto& target : targets) {
        if (!target.isHit) {
            target.x += (rand() % 3 - 1) * 2.0f; // Random horizontal movement
            target.y += (rand() % 3 - 1) * 2.0f; // Random vertical movement

            // Keep targets within bounds
            if (target.x < 0) target.x = 0;
            if (target.x > width) target.x = width;
            if (target.y < 0) target.y = 0;
            if (target.y > height) target.y = height;
        }
    }

    checkCollisions();
}

void Game::render() {
    if (isGameOver) {
        Renderer::drawText("Game Over!", width / 2 - 50, height / 2);
        return;
    }

    Renderer::drawCrosshair(crosshairX, crosshairY);
    for (const auto& target : targets) {
        Renderer::drawTarget(target.x, target.y, target.size, target.isHit);
    }

    // Display score
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    Renderer::drawText(scoreText, 10, 10);

    // Display timer
    char timerText[20];
    sprintf(timerText, "Time: %.1f", timer);
    Renderer::drawText(timerText, 10, 30);
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
    int numTargets = 5 + score / 10; // Increase targets as score increases
    targets.clear();
    for (int i = 0; i < numTargets; ++i) {
        targets.push_back({rand() % width, rand() % height, 20.0f, false});
    }
}

void Game::checkCollisions() {
    // Placeholder for future collision logic
}
