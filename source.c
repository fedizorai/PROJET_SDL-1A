/**
* @file perso.c
* @brief Testing Program.
* @author fallega team
* @version 0.1
* @date avr 27,2022
*
* Testing program for background scrollilng
*
*/
#include "fichier.h"
/**
* @brief pour afficher le perso.
* @param  p perso 
* @param  screen the screen
* @return Nothing
*/
void afficherPerso(Perso p,SDL_Surface *screen){

	
	displayscore(p.score,screen);
	afficherImg(p.vie,screen);
	SDL_BlitSurface(p.perso,&(p.posSprite),screen,&(p.posScreen)); 
	    
}
 /**
* @brief pour afficher l'image
* @param im image  
* @param  screen the screen
* @return Nothing
*/
void afficherImg(image2 im,SDL_Surface *screen){
SDL_BlitSurface(im.img,&im.pos2,screen,&im.pos1);
}
/**
* @brief pour afficher le background.
* @param  im image 
* @param  screen the screen
* @return Nothing
*/
void affbackground(image2 im,SDL_Surface*screen){
SDL_BlitSurface(im.img,NULL,screen,&im.pos1);}
/**
* @brief pour afficher le score
* @param  s text 
* @param  screen the screen
* @return Nothing
*/
void displayscore(Text2 s,SDL_Surface *screen){
s.surfacetexte=TTF_RenderText_Solid(s.font,"SCORE ",s.textcolor);
SDL_BlitSurface(s.surfacetexte,NULL,screen,&s.position);
}
/**
* @brief pour afficher un text.
* @param  p perso 
* @param  screen the screen
* @return Nothing
*/
void freeTextscore(Text2 s)
{
    TTF_CloseFont(s.font); 
    TTF_Quit();    
}
/**
* @brief pour intialiser le perso
* @param  p perso 
* @return Nothing
*/
void initPerso1(Perso *p) {
p->perso=IMG_Load("char.png");
p->posSprite.x=0;
p->posSprite.y=0;
p->posSprite.w=1500/15;
p->posSprite.h=400/4;
p->posScreen.x=0;
p->posScreen.y=860;
p->vitesse=1;
p->acceleration=0;
p->direction=0;
p->currentframe=0;
p->vx = 4;
p->grav = 1;
p->saut = -14.5;
p->vy = p->saut;
initimgvie1(&p->vie);
initTextscore1(&p->score);
}/**
* @brief pour intialiser le backg.
* @param  image background
* @return Nothing
*/

void initbackground(image2* backg){
backg->img=IMG_Load("backgroundJeu.jpg");
if (backg->img==NULL ){
      printf("Unable to load image: %s\n",SDL_GetError());
    
     }
	
	backg->pos1.x = 0;
	backg->pos1.y = 0;
	backg->pos2.x=0;
	backg->pos2.y=0;
	backg->pos2.w=1920;
	backg->pos2.h=960;
	}
	/**
* @brief pour initialiser une image
* @param  v image
* @return Nothing
*/
void initimgvie1(image2*v){
v->img=IMG_Load("health.png");
if (v->img==NULL ){
      printf("Unable to load image: %s\n",SDL_GetError());
    
     }
     v->pos1.x=1420;
     v->pos1.y=-20;
     v->pos2.x=0;
     v->pos2.y=0;
     v->pos2.w=224;
     v->pos2.h=224;
}
/**
* @brief pour initialiser le score
* @param  s text 
* @return Nothing
*/


void initTextscore1(Text2 *s){
s->position.x=120;
s->position.y=0;

SDL_Color ColeurOlive={0,0,0};
s->textcolor=ColeurOlive;
s->font=TTF_OpenFont("angelina.ttf",60);
}
/**
* @brief pour le movement du personnage
* @param  p perso  
* @param  screen the screen
* @return Nothing
*/	
void movePerso(Perso*p,SDL_Surface *screen,int mv,int dt,Uint32 Dt){

if (dt==0&&mv==1&&p->posScreen.x<1620){if (p->acceleration<=5){p->acceleration+=0.05;}
p->posScreen.x+=((0.5*p->acceleration)*((Dt^2)*0.3))+((p->vitesse)*(Dt*0.3));}

if (dt==1&&mv==1&&p->posScreen.x>=0){if (p->acceleration>=-5){p->acceleration-=0.05;}
p->posScreen.x-=((0.5*-p->acceleration)*((Dt^2)*0.3))+((p->vitesse)*(Dt*0.3));}

}
/**
* @brief pour lanimation du perso
* @param  p perso 
* @param  mv mouvement
* @param differance
* @return Nothing
*/

void animatePerso(Perso *p,int mv,int dt){
SDL_Delay(10);
p->direction=dt;
if (p->direction==0&&mv==1){
p->posSprite.x=0;
p->posSprite.y=0;
if (p->currentframe<=14) {
p->posSprite.x=p->currentframe*100;
p->currentframe++;}

else p->currentframe=0;
}

else if (p->direction==1&&mv==1){
p->posSprite.x=1400;
p->posSprite.y=100;
if (p->currentframe<=14&&p->currentframe>=0) {
p->posSprite.x=p->currentframe*100;
p->currentframe--;}

else p->currentframe=14;}


else if (p->direction==0&&mv==0){
SDL_Delay(10);
p->posSprite.x=0;
p->posSprite.y=200;
if (p->currentframe<=14) {
p->posSprite.x=p->currentframe*100;
p->currentframe++;}

else p->currentframe=0;
}
else if (p->direction==1&&mv==0){
SDL_Delay(10);
p->posSprite.x=1400;
p->posSprite.y=300;
if (p->currentframe<=14&&p->currentframe>=0) {
p->posSprite.x=p->currentframe*100;
p->currentframe--;}

else p->currentframe=14;
}
}
/**
* @brief pour le saut
* @param p perso
* @param dt difference
* @return Nothing
*/
void jump(Perso *p,int dt){
	if (dt==0){
	if(p->posScreen.y<860){
   	p->posScreen.x += p->vx;
   	p->posScreen.y+= p->vy;
   	p->vy += p->grav;
   }
  	if (p->posScreen.y>860)
    	p->vy = p->saut;
}
else {
if(p->posScreen.y<860){
   	p->posScreen.x -= p->vx;
   	p->posScreen.y+= p->vy;
   	p->vy += p->grav;
   }
  	if (p->posScreen.y>860)
    	p->vy = p->saut;
}
}





