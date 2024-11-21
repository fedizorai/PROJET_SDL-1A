#ifndef Fichier_H
#define Fichier_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
/**
* @struct image
* @brief struct for image
*/
typedef struct {
SDL_Rect pos1;/*!< Rectangle*/
SDL_Rect pos2;/*!< Rectangle*/
SDL_Surface * img;/*!< Surface. */
}image2;
/**
* @struct text
* @brief struct for text
*/
typedef struct {
SDL_Rect position;/*!< Rectangle*/
TTF_Font *font;
SDL_Surface *surfacetexte;/*!< Surface. */
SDL_Color textcolor;
char text [50];
}Text2;
/**
* @struct perso
* @brief struct for perso
*/
typedef struct {
SDL_Surface *perso;/*!< Surface. */
SDL_Rect posScreen;/*!< Rectangle*/
SDL_Rect posSprite;/*!< Rectangle*/
double vitesse,acceleration;
int direction, currentframe, vy,vx,saut,grav;//0:droite 1:gauche
Text2 score; 
image2 vie,img;
}Perso;


//vie:
void initimgvie1(image2* v);
void afficherImg(image2 v,SDL_Surface *screen);
void freeimgvie(image2 v);
//background
void initbackground(image2* backg);
void affbackground(image2 im,SDL_Surface*screen);
//score:
void initTextscore1(Text2* T);
void displayscore(Text2 T,SDL_Surface *screen);
void freeTextscore(Text2 T);
int loadFontscore(Text2* T, char* path);

//perso
void initPerso1(Perso* p);
void afficherPerso(Perso p, SDL_Surface * screen);
void movePerso(Perso *p, SDL_Surface *screen,int mv,int dt,Uint32 Dt);
void animatePerso (Perso* p,int mv,int dt);
void jump (Perso*p,int dt);
#endif

