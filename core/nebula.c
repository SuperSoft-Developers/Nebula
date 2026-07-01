#include "nebula.h"

Nebula nebula;

void nebula_init(int w, int h) {
    nebula.running = 1;
    nebula.width = w;
    nebula.height = h;
}

void nebula_update() {
    // lógica do engine
}

void nebula_draw() {
    // render base (por plataforma)
}

void nebula_quit() {
    nebula.running = 0;
}
