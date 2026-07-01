#include "renderer.h"
#include "nebula.h"

#ifdef _3DS
#include <3ds.h>
#endif

// buffer simples (3DS usa framebuffer direto)
static int screenW;
static int screenH;

void renderer_init(int width, int height) {
    screenW = width;
    screenH = height;
}

void renderer_clear() {
#ifdef _3DS
    // 3DS limpa via gfxFlushBuffers normalmente
#else
    // Windows: nada por enquanto
#endif
}

void nebula_draw_sprite(NebulaSprite* sprite, int x, int y) {

#ifdef _3DS
    // 🎮 DRAW REAL NO 3DS (framebuffer top screen)
    u16* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);

    for (int j = 0; j < sprite->h; j++) {
        for (int i = 0; i < sprite->w; i++) {

            int sx = x + i;
            int sy = y + j;

            if (sx < 0 || sy < 0 || sx >= screenW || sy >= screenH)
                continue;

            fb[sy * screenW + sx] = sprite->pixels[j * sprite->w + i];
        }
    }

#else
    // 🪟 WINDOWS (placeholder)
    // Depois você troca por SDL/OpenGL
    (void)sprite;
    (void)x;
    (void)y;
#endif
}

void renderer_present() {
#ifdef _3DS
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
#else
    // Windows: swap buffer depois
#endif
}
