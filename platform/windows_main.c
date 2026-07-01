#include "../core/nebula.h"

void game_init();
void game_update();
void game_draw();

int main() {
    game_init();

    while (nebula.running) {
        game_update();
        game_draw();
    }

    return 0;
}
