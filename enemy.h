
#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct Enemy
{
    SDL_Surface *spriteSheet;
    SDL_Rect posScreen, posSprite;
    int direction;
    SDL_Rect posmin, posmax;
    int frame;
} Enemy;

SDL_Rect initSDL_Rect(int x, int y, int w, int h);
void initEnemy(Enemy *e);
void afficherEnemy(Enemy *e, SDL_Surface *screen);
void animerEnemy(Enemy *e);
void move(Enemy *e, int dist);
int collisionBB(SDL_Rect posp, SDL_Rect pos);
void moveIA(Enemy *e, SDL_Rect posPlayer);

#endif