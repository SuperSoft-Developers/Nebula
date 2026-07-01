#include "../core/nebula.h"
#include "../core/input.h"
#include "../core/renderer.h"
#include "../core/entity.h"

/*
    🧱 Sprite do player
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

static NebulaSprite playerSprite;

static NebulaEntity player;
static NebulaEntity box;

void game_init() {
    nebula_init(400, 240);
    renderer_init(400, 240);
    input_init();

    playerSprite.w = 8;
    playerSprite.h = 8;
    playerSprite.pixels = playerSpriteData;

    entity_init(&player, 100, 100, 8, 8);
    entity_init(&box, 200, 120, 16, 16);
}

void game_update() {

    input_update();

    player.vx = 0;
    player.vy = 0;

    if (nebulaInput.left)  player.vx = -2;
    if (nebulaInput.right) player.vx =  2;
    if (nebulaInput.up)    player.vy = -2;
    if (nebulaInput.down)  player.vy =  2;

    entity_move(&player);

    // colisão com box
    if (entity_collides(&player, &box)) {
        // simples: volta posição
        player.x -= player.vx;
        player.y -= player.vy;
    }

    nebula_update();
}

void game_draw() {

    renderer_clear();

    // desenha player
    nebula_draw_sprite(&playerSprite, player.x, player.y);

    // desenha box (reuse sprite como bloco sólido branco)
    nebula_draw_sprite(&playerSprite, box.x, box.y);

    renderer_present();
}
