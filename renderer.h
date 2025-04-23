#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    static void init();
    static void drawCrosshair(float x, float y);
    static void drawTarget(float x, float y, float size, bool isHit);
    static void drawText(const char* text, float x, float y);
};

#endif
