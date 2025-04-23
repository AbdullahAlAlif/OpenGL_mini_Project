#ifndef GAME_H
#define GAME_H

#include <vector>

struct Target {
    float x, y, size;
    bool isHit;
};

class Game {
public:
    Game(int width, int height);
    void init();
    void update();
    void render();
    void handleMouseMovement(double xpos, double ypos);
    void handleMouseClick();

private:
    int width, height;
    float crosshairX, crosshairY;
    int score;
    std::vector<Target> targets;
    float timer; // Add a timer
    bool isGameOver;

    void spawnTargets();
    void checkCollisions();
};

#endif
