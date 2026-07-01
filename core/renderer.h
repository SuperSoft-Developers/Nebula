#pragma once

#include "tilemap.h"
#include "renderer.h"
#include "renderer.h"

typedef struct {
    int x;
    int y;
    int w;
    int h;

    const unsigned short* pixels;
} NebulaSprite;

/* sprites */
void renderer_init(int width, int height);
void renderer_clear();
void renderer_present();
void nebula_draw_sprite(NebulaSprite* sprite, int x, int y);

/* 💥 ADICIONE ISSO */
void nebula_draw_tilemap(NebulaTilemap* map, NebulaSprite* tileSprite);
