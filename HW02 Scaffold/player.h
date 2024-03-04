#ifndef PLAYER_H
#define PLAYER_H

// bg function prototype
void drawBackground();

// player struct
typedef struct {
	int pX;
	int pY; // constant
    int oldPX;
    int pWidth; 
    int pHeight;
    unsigned short pColor;
    int movingRight; // 1 if moving right, 0 if not
    int pVelocity;
} PLAYER;

// player and pointer
PLAYER player1;
PLAYER* player;

// player function prototypes
void initPlayer(); 
void drawPlayer(); 
void updatePlayer(); 
void dropBomb();

#endif