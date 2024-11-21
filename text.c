#include <SDL/SDL.h>
#include "text.h"
#include <SDL/SDL_image.h>

//liberer la memoire

void inittext(Text *A)
{
  A->position.x=825;
  A->position.y=200;
//couleur
  A->textColor.r=255;
  A->textColor.g=255;
  A->textColor.b=255;


 A->font = TTF_OpenFont("pricedown bl.otf" ,32);
}
void inittext1(Text *A)
{
  A->position.x=75;
  A->position.y=100;
//couleur
  A->textColor.r=255;
  A->textColor.g=255;
  A->textColor.b=255;


 A->font = TTF_OpenFont("pricedown bl.otf" ,25);
}
void inittext2(Text *A)
{
  A->position.x=240;
  A->position.y=685;
//couleur
  A->textColor.r=255;
  A->textColor.g=0;
  A->textColor.b=0;


 A->font = TTF_OpenFont("pricedown bl.otf" ,22);
}
void freetext(Text A)
{ 			
		SDL_FreeSurface(A.surfaceTexte);
}
void displaytext(Text t,SDL_Surface *screen)
{
t.surfaceTexte = TTF_RenderText_Solid(t.font, "it's all about honor" , t.textColor );
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
void displaytext1(Text t1,SDL_Surface *screen)
{
t1.surfaceTexte = TTF_RenderText_Solid(t1.font," if need any help contact as on instagram :@legacy_guardians.tn " , t1.textColor );
SDL_BlitSurface(t1.surfaceTexte, NULL, screen,&t1.position);
}

void displaytext2(Text t2,SDL_Surface *screen)
{
t2.surfaceTexte = TTF_RenderText_Solid(t2.font," back to home " , t2.textColor );
SDL_BlitSurface(t2.surfaceTexte, NULL, screen,&t2.position);
}

