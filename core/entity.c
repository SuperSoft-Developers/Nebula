#include "entity.h"

void entity_init(NebulaEntity* e, int x, int y, int w, int h) {
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;

    e->vx = 0;
    e->vy = 0;

    e->active = 1;
}

void entity_move(NebulaEntity* e) {
    e->x += e->vx;
    e->y += e->vy;
}

int entity_collides(NebulaEntity* a, NebulaEntity* b) {
    return (
        a->x < b->x + b->w &&
        a->x + a->w > b->x &&
        a->y < b->y + b->h &&
        a->y + a->h > b->y
    );
}
