#include "gba.h"
#include "print.h"
#include "player.h"
#include "bomb.h"
#include "terrain.h"

// prototypes
void initialize();
void game();
void end();
void goToGame();
void goToEnd();

// extern vars
extern int remainingBlocks;
unsigned short buttons;
unsigned short oldButtons;

// state enum
enum STATE {
    GAME,
    END
} state;

int main() {

    initialize();

    while (1) {
        oldButtons = buttons;
        buttons = REG_BUTTONS;

        // state machine
        switch (state) {
            case GAME:
                game();
                break;
            case END:
                end();
                break;
        }
        
    }
    return 0;

}

void initialize() {
    
    mgba_open();
    REG_DISPCTL = MODE(3) | BG2_ENABLE;

    oldButtons = 0;
    buttons = REG_BUTTONS;

    drawBackground();
    initPlayer();
    initBomb();
    initTerrain();

    goToGame();

}

void goToGame() {
    state = GAME;
}

void goToEnd() {
    state = END;
}

void game() {
    updatePlayer();
    updateBomb();
    updateTerrain();

    waitForVBlank();

    drawPlayer();
    drawBomb();
    drawTerrain();
    
    if (remainingBlocks == 0) {
        goToEnd();
    }
}

void end() {
    fillScreen(BLACK);
}