#include "../core/nebula.h"
#include "../core/input.h"
#include "../core/renderer.h"

/*
    🧱 Sprite simples (8x8 RGB565)
    Quadrado com "olhos" pra teste visual
*/
static const unsigned short playerSpriteData[64] = {
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0x0000,0x0000,0xFFFF,0xFFFF,0x0000,0x0000,0xFFFF,
    0xFFFF,0x0000,0x0000,0xFFFF,0xFFFF,0x0000,0x0000,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
    0xFFFF,0xFFFF,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,
    0xFFFF,0x0000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,0xFFFF,
    0xFFFF,0x0000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,0xFFFF,
    0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF
};

static NebulaSprite player;

static int playerX = 100;
static int playerY = 100;

void game_init() {
    nebula_init(400, 240);
    renderer_init(400, 240);

    input_init();

    player.w = 8;
    player.h = 8;
    player.pixels = playerSpriteData;
}

void game_update() {

    input_update();

    // 🎮 movimento
    if (nebulaInput.left)  playerX -= 2;
    if (nebulaInput.right) playerX += 2;
    if (nebulaInput.up)    playerY -= 2;
    if (nebulaInput.down)  playerY += 2;

    // 🔒 limites simples da tela
    if (playerX < 0) playerX = 0;
    if (playerY < 0) playerY = 0;
    if (playerX > 392) playerX = 392;
    if (playerY > 232) playerY = 232;

    nebula_update();
}

void game_draw() {

    renderer_clear();

    nebula_draw_sprite(&player, playerX, playerY);

    renderer_present();
}
