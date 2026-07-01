#pragma once

#include "entity.h"
#include "tilemap.h"

typedef struct {
    float gravity;
    float jump_strength;
    float max_fall_speed;
} NebulaPhysics;

extern NebulaPhysics nebulaPhysics;

void physics_init();
void physics_apply(NebulaEntity* e, NebulaTilemap* map);
