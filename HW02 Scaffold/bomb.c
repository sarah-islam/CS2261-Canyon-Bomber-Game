#include "bomb.h"
#include "player.h"
#include "gba.h"
#include "print.h"

#define BG_COLOR (RGB(0, 5, 10))

// initializes bomb
void initBomb() {
    bomb1.bX = 0;
    bomb1.bY = 0;
    bomb1.oldBX = 0;
    bomb1.oldBY = 0;
    bomb1.bWidth = 4;
    bomb1.bHeight = 4;
    bomb1.bColor = WHITE;
    bomb1.isActive = 0;
    bomb1.bVelocity = 0;

    bomb = &bomb1;
}

// updates bomb if active
void updateBomb() {
    if (bomb->isActive) {
        bomb->oldBX = bomb->bX;
        bomb->oldBY = bomb->bY;

        bomb->bX += bomb->bVelocity;
        bomb->bY += 4;

        if (bomb->bX < 0 || bomb->bX >= SCREENWIDTH || bomb->bY >= SCREENHEIGHT) {
            bomb->isActive = 0;
            drawRectangle(bomb->oldBX, bomb->oldBY, bomb->bWidth, bomb->bHeight, BG_COLOR);
        }
    }
}

// draws bomb if active
void drawBomb() {
    if (bomb->isActive) {
        drawRectangle(bomb->oldBX, bomb->oldBY, bomb->bWidth, bomb->bHeight, BG_COLOR);
        drawRectangle(bomb->bX, bomb->bY, bomb->bWidth, bomb->bHeight, bomb->bColor);
    }
}

// drops bomb if not already active, stays consistent with players speed and direction
void dropBomb() {
    if (!bomb->isActive) {
        bomb->bX = player->pX;
        bomb->bY = player->pY;
        
        if (player->movingRight) {
            bomb->bVelocity = player->pVelocity;
        }
        if (!player->movingRight) {
            bomb->bVelocity = -(player->pVelocity);
        }
        
        bomb->isActive = 1;
    }
}