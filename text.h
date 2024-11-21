#ifndef TEXTE_H
#define TEXTE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfaceTexte;
	SDL_Color textColor;
	char texte[50];
}Text;


void inittext(Text *t);
void inittext1(Text *t1);
void inittext2(Text *t2);
void freetext(Text A);
void displaytext(Text t,SDL_Surface *screen);
void displaytext1(Text t1,SDL_Surface *screen);
void displaytext2(Text t2,SDL_Surface *screen);


#endif
