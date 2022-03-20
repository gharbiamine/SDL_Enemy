#include "enemy.h"

SDL_Rect initSDL_Rect(int x, int y, int w, int h)
{
    SDL_Rect R;
    R.x = x;
    R.y = y;
    R.w = w;
    R.h = h;
    return R;
}

void initEnemy(Enemy *e)
{
    e->spriteSheet = IMG_Load("assets/images/image.jpg");
    e->frame = 0;
    e->direction = 0; // 0 facing right | 1 facing left
    e->posScreen = initSDL_Rect(1000, 1000, 0, 0);
    e->posSprite = initSDL_Rect(0, 0, 100, 100);
    e->posmax.x = 3000;
    e->posmin.x = 2000;
}

void afficherEnemy(Enemy *e, SDL_Surface *screen)
{
    if (e->posScreen.x > 0 && e->posScreen.x < screen->w)
    {
        SDL_BlitSurface(e->spriteSheet, &e->posSprite, screen, &e->posScreen);
    }
}

void animerEnemy(Enemy *e)
{
    e->posSprite.y = e->direction * 100;
    // loop back if the sprite sheet edge is reached
    e->posSprite.x = (e->posSprite.x == e->spriteSheet->w - e->posSprite.w) ? 0 : e->posSprite.x + 100;
}

void move(Enemy *e, int dist)
{
    // Should turn if movement will overflow
    if (e->posScreen.x + dist > e->posmax.x || e->posScreen.x - dist < e->posmin.x)
    {
        e->direction = 1 - e->direction;
    }
    e->posScreen.x = (e->direction == 0) ? e->posScreen.x + dist : e->posScreen.x - dist;
}

int collisionBB(SDL_Rect posp, SDL_Rect pos)
{
    int flag = 1;
    if ((posp.x + posp.y < pos.x) || (posp.x > pos.x + pos.y) || (posp.y + posp.h < pos.y) || (posp.y > pos.y + pos.h))
    {
        flag = 0;
    }
    return flag;
}

void moveIA(Enemy *e, SDL_Rect posPlayer)
{
    if (((e->posScreen.x - posPlayer.x) < 200) && ((e->posScreen.x - posPlayer.x) > 80))
    {
        e->direction = 1;
        e->posScreen.x -= 10;
    }
    else if (((e->posScreen.x - posPlayer.x) < -80) && ((e->posScreen.x - posPlayer.x) > -400))
    {
        e->direction = 0;
        e->posScreen.x += 10;
    }
}
