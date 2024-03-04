#include "terrain.h"
#include "bomb.h"
#include "gba.h"
#include "print.h"

#define BG_COLOR (RGB(0, 5, 10))

// terrain vars
BLOCK blocks[60];
remainingBlocks = 60;

// initializes terrain of 60 blocks
void initTerrain() {
    int j = 0;
    for (int i = 0; i < 60; i++) {
        blocks[i].blColor = RGB(15, 0, 2 + j);
        blocks[i].blWidth = 10;
        blocks[i].blHeight = 10;
        blocks[i].isHit = 0;
        j += 12;
    }

    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20; j++) {
            blocks[count].blY = 150 - (10 * i);
            blocks[count].blX = 20 + (10 * j);
            count++;
        }
    }
}

// draws terrain, if block is hit then it is not drawn
void drawTerrain() {
    for (int i = 0; i < 60; i++) {
        if (!blocks[i].isHit) {
            drawRectangle(blocks[i].blX, blocks[i].blY, blocks[i].blWidth, blocks[i].blHeight, blocks[i].blColor);
        }
    }
}

// updates terrain, if bomb hits block then block disappears, bomb also disappears after passing through terrain
void updateTerrain() {
    for (int i = 0; i < 60; i++) {
        if (!blocks[i].isHit && collision(bomb->bX, bomb->bY, bomb->bWidth, bomb->bHeight, blocks[i].blX, blocks[i].blY, blocks[i].blWidth, blocks[i].blHeight)) {
            blocks[i].isHit = 1;
            remainingBlocks--;
            drawRectangle(blocks[i].blX, blocks[i].blY, blocks[i].blWidth, blocks[i].blHeight, BG_COLOR);
            drawRectangle(bomb->oldBX, bomb->oldBY, bomb->bWidth, bomb->bHeight, BG_COLOR);
        }
    }
}