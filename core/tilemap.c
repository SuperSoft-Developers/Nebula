#include "tilemap.h"

void tilemap_init(NebulaTilemap* map) {
    map->width = MAP_W;
    map->height = MAP_H;

    // limpa mapa
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            map->tiles[x][y] = 0;
        }
    }

    // chão básico
    for (int x = 0; x < MAP_W; x++) {
        map->tiles[x][MAP_H - 1] = 1;
    }

    // plataforma simples
    for (int x = 10; x < 20; x++) {
        map->tiles[x][20] = 1;
    }
}

int tilemap_get(NebulaTilemap* map, int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
        return 1; // fora = parede

    return map->tiles[x][y];
}

void tilemap_set(NebulaTilemap* map, int x, int y, int value) {
    if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
        return;

    map->tiles[x][y] = value;
}

int tilemap_is_solid(int tile) {
    return tile == 1;
}
