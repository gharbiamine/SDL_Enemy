
#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#define POSMIN 2000
#define POSMAX 3000

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct Enemy
{
    SDL_Surface *spriteSheet;
    // Sprite Sheet is 400*216
    SDL_Rect posScreen, posSprite;
    int direction;
} Enemy;

SDL_Rect initSDL_Rect(int x, int y, int w, int h);
void initEnemy(Enemy *e);
void afficherEnemy(Enemy *e, SDL_Surface *screen);
void animerEnemy(Enemy *e);
void move(Enemy *e);
int collisionBB(SDL_Rect posp, SDL_Rect pos);
void moveIA(Enemy *e, SDL_Rect posPlayer);

#endif