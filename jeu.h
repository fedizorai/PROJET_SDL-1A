#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "fichier.h"
#include <time.h>


void perso(){
int continuer=1,ch=0,dt=0,mv=0,prev=0,dt2=1,mv2=0,prev2=0;
        	
	SDL_Event event;
	Text2 sc;
	image2 v;
	TTF_Init();
	
	SDL_Init(SDL_INIT_VIDEO);
//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        exit(0);
    }
 	screen=SDL_SetVideoMode(1720,960,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        exit(0);
    }
  
	SDL_WM_SetCaption("Game", NULL); 
// creation background
 	image2 backg ;
	initbackground(&backg);

 //initialisation 
 Uint32 Dt2,Dt,t_prev,t_prev2;
	Perso p1,p2;
initimgvie1(&p1.vie);
initimgvie1(&p2.vie);
initTextscore1(&p2.score);
	initTextscore1(&p1.score);
	initPerso1(&p1);
	initPerso1(&p2);
	


	SDL_EnableKeyRepeat(200, 0);
	
	 while(continuer)
    {  
    t_prev=SDL_GetTicks();
    mv=0;
    t_prev2=SDL_GetTicks();
    
    mv2=0;
    
    if (prev==0) {dt=0;}
    if(prev2==0){dt2=0;}
    	SDL_PollEvent(&event);
    int keysheld[323]={0};

     switch(event.type)

     {  
     	case SDL_QUIT: 
		continuer=0;
		break;
	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {  
		
		case SDLK_RIGHT: 
		if (prev==1){p1.acceleration=0;}
		
               	dt=0;
               	mv=1;
               	movePerso(&p1 ,screen,mv,dt,Dt);
               	animatePerso(&p1,mv,dt);
               	SDL_Flip(screen);
               	prev=0;
		break;
			
		case SDLK_LEFT: 
		if (prev==0){p1.acceleration=0;}
		
               	dt=1;
               	mv=1;
               	movePerso(&p1 ,screen,mv,dt,Dt);
               	animatePerso(&p1,mv,dt);
               	SDL_Flip(screen);
               	prev=1;
		break;
		case SDLK_UP:
		 p1.posScreen.y-=2;
		
		
               break;
		case SDLK_ESCAPE: 
              		continuer=0;
              		
              	break;
		//2eme joueur
		case SDLK_d: 
		if (prev2==1){p2.acceleration=0;}
		
               	dt2=0;
               	mv2=1;
               	movePerso(&p2 ,screen,mv2,dt2,Dt2);
               	animatePerso(&p2,mv2,dt2);
               	SDL_Flip(screen);
               	prev2=0;
		break;

		case SDLK_q: 
		if (prev2==0){p2.acceleration=0;}
		
               	dt2=1;
               	mv2=1;
               	movePerso(&p2 ,screen,mv2,dt2,Dt2);
               	animatePerso(&p2,mv2,dt2);
               	SDL_Flip(screen);
               	prev2=1;
		break;
		
		case SDLK_z:
		 p2.posScreen.y-=2;
		
		
               break;
		
		}
		}
		

	affbackground(backg,screen);
	
		afficherPerso (p1,screen);
		afficherPerso(p2,screen);
		animatePerso(&p1,mv,dt);
		animatePerso(&p2,mv2,dt2);
		jump(&p1,dt);
		jump(&p2,dt2);
		SDL_Flip(screen);
	
    Dt=SDL_GetTicks()-t_prev;
    Dt2=SDL_GetTicks()-t_prev2;
	}
	
        freeTextscore(p1.score);
       
	SDL_FreeSurface(backg.img);
	SDL_Quit();
}