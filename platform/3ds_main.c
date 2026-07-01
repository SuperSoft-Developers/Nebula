#include <3ds.h>
#include "../core/nebula.h"

void game_init();
void game_update();
void game_draw();

int main() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    game_init();

    while (aptMainLoop() && nebula.running) {
        hidScanInput();

        game_update();
        game_draw();

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
