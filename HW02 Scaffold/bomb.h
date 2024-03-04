#ifndef BOMB_H
#define BOMB_H

// bomb struct
typedef struct {
    int bX;
    int bY;
    int oldBX;
    int oldBY;
    int bWidth;
    int bHeight;
    unsigned short bColor;
    int isActive; // 1 if active, 0 if not
    int bVelocity;
} BOMB;

// bomb and pointer
BOMB bomb1;
BOMB* bomb;

// bomb function prototypes
void initBomb();
void drawBomb();
void updateBomb();

#endif