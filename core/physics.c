#include "physics.h"
#include "input.h"
#include "tilemap.h"

NebulaPhysics nebulaPhysics;

/* =========================
   INIT
========================= */

void physics_init() {
    nebulaPhysics.gravity = 0.4f;
    nebulaPhysics.jump_strength = -6.5f;
    nebulaPhysics.max_fall_speed = 8.0f;
}

/* =========================
   INTERNAL HELPERS
========================= */

static int is_solid_at(NebulaTilemap* map, int x, int y) {
    return tilemap_is_solid(tilemap_get(map, x, y));
}

/* =========================
   MAIN PHYSICS UPDATE
========================= */

void physics_apply(NebulaEntity* e, NebulaTilemap* map) {

    /* =========================
       GRAVIDADE
    ========================= */
    e->vy += nebulaPhysics.gravity;

    if (e->vy > nebulaPhysics.max_fall_speed)
        e->vy = nebulaPhysics.max_fall_speed;

    /* =========================
       PULO
    ========================= */
    if (nebulaInput.a) {

        int footX1 = e->x / TILE_SIZE;
        int footX2 = (e->x + e->w - 1) / TILE_SIZE;
        int footY  = (e->y + e->h + 1) / TILE_SIZE;

        if (is_solid_at(map, footX1, footY) ||
            is_solid_at(map, footX2, footY)) {

            e->vy = nebulaPhysics.jump_strength;
        }
    }

    /* =========================
       MOVIMENTO VERTICAL
    ========================= */
    float newY = e->y + e->vy;

    int top    = newY / TILE_SIZE;
    int bottom = (newY + e->h) / TILE_SIZE;
    int left   = e->x / TILE_SIZE;
    int right  = (e->x + e->w - 1) / TILE_SIZE;

    /* colisão com chão */
    if (is_solid_at(map, left, bottom) ||
        is_solid_at(map, right, bottom)) {

        e->y = bottom * TILE_SIZE - e->h;
        e->vy = 0;
    }
    else if (is_solid_at(map, left, top) ||
             is_solid_at(map, right, top)) {

        /* colisão com teto */
        e->y = (top + 1) * TILE_SIZE;
        e->vy = 0;
    }
    else {
        e->y = newY;
    }

    /* =========================
       MOVIMENTO HORIZONTAL (COLISÃO SIMPLES)
       (pode evoluir depois)
    ========================= */
    float newX = e->x;

    if (nebulaInput.left)  newX -= 2;
    if (nebulaInput.right) newX += 2;

    int lx = newX / TILE_SIZE;
    int ly1 = e->y / TILE_SIZE;
    int ly2 = (e->y + e->h - 1) / TILE_SIZE;

    if (!is_solid_at(map, lx, ly1) &&
        !is_solid_at(map, lx, ly2)) {
        e->x = newX;
    }
}
