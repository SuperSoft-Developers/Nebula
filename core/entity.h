#pragma once

typedef struct {
    int x, y;
    int w, h;

    int vx, vy;

    int active;
} NebulaEntity;

void entity_init(NebulaEntity* e, int x, int y, int w, int h);
void entity_move(NebulaEntity* e);
int entity_collides(NebulaEntity* a, NebulaEntity* b);
