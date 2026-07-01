#pragma once

typedef struct {
    int running;
    int width;
    int height;
} Nebula;

extern Nebula nebula;

void nebula_init(int w, int h);
void nebula_update();
void nebula_draw();
void nebula_quit();
