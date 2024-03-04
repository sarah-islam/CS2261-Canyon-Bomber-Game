#ifndef TERRAIN_H
#define TERRAIN_H

// block struct (for terrain)
typedef struct {
    int blX;
    int blY;
    int oldBLX;
    int oldBLY;
    int blWidth;
    int blHeight;
    unsigned short blColor;
    int isHit;  // 1 if hit, 0 if not

} BLOCK;

// terrain function prototypes
void initTerrain();
void updateTerrain();
void drawTerrain();
#endif