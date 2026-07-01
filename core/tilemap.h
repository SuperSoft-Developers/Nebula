#pragma once

#define TILE_SIZE 8
#define MAP_W 50
#define MAP_H 30

typedef struct {
    int width;
    int height;
    int tiles[MAP_W][MAP_H];
} NebulaTilemap;

void tilemap_init(NebulaTilemap* map);
int tilemap_get(NebulaTilemap* map, int x, int y);
void tilemap_set(NebulaTilemap* map, int x, int y, int value);

int tilemap_is_solid(int tile);
