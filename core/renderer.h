#pragma once

typedef struct {
    int x;
    int y;
    int w;
    int h;

    const unsigned short* pixels; // formato 3DS (RGB565)
} NebulaSprite;

void renderer_init(int width, int height);
void renderer_clear();

void nebula_draw_sprite(NebulaSprite* sprite, int x, int y);
void renderer_present();
