#include "../core/nebula.h"
#include "../core/input.h"
#include "../core/renderer.h"
#include "../core/entity.h"
#include "../core/tilemap.h"

/* =========================
   SPRITES
========================= */

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

static const unsigned short tileSpriteData[64] = {
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,
    0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF,0x7BEF
};

/* =========================
   GLOBALS
========================= */

static NebulaEntity player;
static NebulaTilemap map;

static NebulaSprite playerSprite;
static NebulaSprite tileSprite;

/* =========================
   INIT
========================= */

void game_init() {

    nebula_init(400, 240);
    renderer_init(400, 240);
    input_init();

    tilemap_init(&map);

    playerSprite.w = 8;
    playerSprite.h = 8;
    playerSprite.pixels = playerSpriteData;

    tileSprite.w = 8;
    tileSprite.h = 8;
    tileSprite.pixels = tileSpriteData;

    entity_init(&player, 40, 40, 8, 8);
}

/* =========================
   UPDATE
========================= */

void game_update() {

    input_update();

    int nextX = player.x;
    int nextY = player.y;

    // movimento base
    if (nebulaInput.left)  nextX -= 2;
    if (nebulaInput.right) nextX += 2;
    if (nebulaInput.up)    nextY -= 2;
    if (nebulaInput.down)  nextY += 2;

    // colisão simples por tile
    int tileX = nextX / TILE_SIZE;
    int tileY = nextY / TILE_SIZE;

    if (!tilemap_is_solid(tilemap_get(&map, tileX, tileY))) {
        player.x = nextX;
        player.y = nextY;
    }

    nebula_update();
}

/* =========================
   DRAW
========================= */

void game_draw() {

    renderer_clear();

    nebula_draw_tilemap(&map, &tileSprite);

    nebula_draw_sprite(&playerSprite, player.x, player.y);

    renderer_present();
}
