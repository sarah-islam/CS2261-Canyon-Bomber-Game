#include "player.h"
#include "gba.h"
#include "print.h"

#define BG_COLOR (RGB(0, 5, 10))

// speed vars
#define NORMAL_SPEED 1
#define FAST_SPEED   2

// draws background
void drawBackground() {
    fillScreen(BG_COLOR);
}

// initializes player
initPlayer() {
    player1.pX = 0;
    player1.pY = 30;
    player1.oldPX = 0;
    player1.pWidth = 20;
    player1.pHeight = 10;
    player1.pColor = RGB(10, 20, 10);
    player1.movingRight = 1;
    player1.pVelocity = NORMAL_SPEED;

    player = &player1;
}

// updates player speed, directional bounds, bomb drop
updatePlayer() {
    player->oldPX = player->pX;

    if (BUTTON_HELD(BUTTON_SELECT)) {
        player->pVelocity = FAST_SPEED;
    }
    else {
        player->pVelocity = NORMAL_SPEED;
    }

    if (player->pX < (SCREENWIDTH - player->pWidth) && player->pX > 0) {
        if (player->movingRight) {
            player->pX += player->pVelocity;
        }
        else {
            player->pX -= player->pVelocity;
        }
    }
    else if (player->pX >= (SCREENWIDTH - player->pWidth)) {
        player->movingRight = 0;
        player->pX -= player->pVelocity;
    }
    else if (player->pX <= 0) {
        player->movingRight = 1;
        player->pX += player->pVelocity;
    }

    if (BUTTON_PRESSED(BUTTON_B)) {
        dropBomb();
    }
}

// draws player + a cloud behind player if going fast
drawPlayer() {
    // removes cloud
    if (player-> movingRight) {
        drawRectangle(player->oldPX - 5, player->pY, 5, 10, BG_COLOR);
    }
    else {
        drawRectangle(player->oldPX + player->pWidth, player->pY, 5, 10, BG_COLOR);
    }
    // draws player
    drawRectangle(player->oldPX, player->pY, player->pWidth, player->pHeight, BG_COLOR);
    drawRectangle(player->pX, player->pY, player->pWidth, player->pHeight, player->pColor);

    // draws a cloud behind player if going fast
    if (BUTTON_HELD(BUTTON_SELECT) && player->movingRight) {
        drawRectangle(player->pX - 5, player->pY, 5, 10, WHITE);
    }
    else if (BUTTON_HELD(BUTTON_SELECT) && !player->movingRight) {
        drawRectangle(player->pX + player->pWidth, player->pY, 5, 10, WHITE);
    }
}