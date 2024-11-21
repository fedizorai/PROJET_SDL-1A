#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define SCREEN_W 1200
#define SCREEN_H 800
struct image
{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface * img;
};
typedef struct image image;
void initPlayer (image *A);
void initbouton(image *B,char name[],int x,int y);
void initBackground (image *Backg, char name []);
void liberer(image A);
void afficher (image P, SDL_Surface *screen);

#endif
