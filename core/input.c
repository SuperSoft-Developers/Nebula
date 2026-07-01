#include "input.h"

NebulaInput nebulaInput;

void input_init() {
    input_reset();
}

void input_reset() {
    nebulaInput.up = 0;
    nebulaInput.down = 0;
    nebulaInput.left = 0;
    nebulaInput.right = 0;

    nebulaInput.a = 0;
    nebulaInput.b = 0;
    nebulaInput.start = 0;
}

void input_update() {
    // 🔴 IMPORTANTE:
    // Aqui é "stub" (base).
    // Cada plataforma vai sobrescrever isso depois.

    // Windows → você vai mapear teclado depois
    // 3DS → vamos usar hidKeysDown / hidKeysHeld depois

    input_reset();
}
