#include "image.h"
#include "text.h"
#include <SDL/SDL_mixer.h>
#include "jeu.h"
int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	/*INITItoALISATION IMAGE*/
	TTF_Init();
	SDL_Surface *screen = NULL;
	int done = 0, done1 = 0;
	int i = 1;
	int m = 8;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;
	int bg = 1;
	int i6 = 0, i7 = 0, i8 = 0;
	int re;
	image Backg, Backg1, Backg2, home, Backgr;
	image B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, B11, B12, B13, B14, B15, B16, B17, B18, B19, B20, B21;
	SDL_Event event;
	SDL_Event event1;
	Text t, t1, t2;
	atexit(SDL_Quit);
	/*CREATION D'UNE FENETRE*/

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (!screen)
	{
		printf("Unable to set video %s\n", SDL_GetError());
		return 1;
	}

	initBackground(&Backg, "background.jpg");
	initBackground(&Backg1, "backsettings.jpg");
	initBackground(&Backg2, "startingsoon.jpg");
	initbouton(&B1, "start1.png", 50, 200);
	initbouton(&B2, "settings1.png", 50, 350);
	initbouton(&B3, "quit1.png", 50, 500);
	initbouton(&B4, "start2.png", 50, 200);
	initbouton(&B6, "settings2.png", 50, 350);
	initbouton(&B7, "quit2.png", 50, 500);
	initbouton(&B8, "logo.png", 700, -100);
	initbouton(&B9, "v12.png", 200, 400);
	initbouton(&B10, "home1.png", 1070, 700);
	initbouton(&B11, "home2.png", 1070, 700);
	initbouton(&B12, "v1.png", 190, 385);
	initbouton(&B13, "plus1.png", 380, 407);
	initbouton(&B14, "moins1.png", 180, 407);
	initbouton(&B15, "plus2.png", 380, 407);
	initbouton(&B16, "moins2.png", 180, 407);
	initbouton(&B17, "v2.png", 215, 385);
	initbouton(&B18, "v3.png", 250, 385);
	initbouton(&B19, "v4.png", 285, 385);
	initbouton(&B20, "v5.png", 320, 385);
	inittext(&t);
	inittext1(&t1);
	inittext2(&t2);
	/*GAME LOOP*/

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}
	Mix_Music *music;
	Mix_Chunk *son;
	music = Mix_LoadMUS("music.mp3");
	son = Mix_LoadWAV("sound.wav");
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(MIX_MAX_VOLUME / m);

	while (!done)
	{

		afficher(Backg, screen);
		afficher(B1, screen);
		afficher(B2, screen);
		afficher(B3, screen);
		afficher(B8, screen);
		SDL_Flip(screen);

		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			done = 1;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				done = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:

			if ((event.motion.x > 163) && (event.motion.x <= 535) && (event.motion.y > 486) && (event.motion.y <= 570))
			{

				while (bg)
				{
					afficher(Backg1, screen);

					afficher(B10, screen);
					afficher(B12, screen);
					afficher(B17, screen);
					afficher(B13, screen);
					afficher(B14, screen);
					afficher(B18, screen);
					afficher(B19, screen);
					afficher(B20, screen);
					SDL_Flip(screen);

					SDL_WaitEvent(&event1);
					switch (event1.type)
					{
					case SDL_MOUSEMOTION:
						printf("position x = %d,\n posisition y = %d", event1.motion.x, event1.motion.y);
						if (event1.motion.x > 1070 && event1.motion.x <= 1144 && event1.motion.y > 700 && event1.motion.y <= 777)
						{
							i6 = 1;
							afficher(B11, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						if (event1.motion.x > 387 && event1.motion.x <= 422 && event1.motion.y > 412 && event1.motion.y <= 443)
						{
							i7 = 1;
							afficher(B15, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						if (event1.motion.x > 189 && event1.motion.x <= 212 && event1.motion.y > 420 && event1.motion.y <= 431)
						{
							i8 = 1;
							afficher(B16, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (event1.motion.x > 1070 && event1.motion.x <= 1144 && event1.motion.y > 700 && event1.motion.y <= 777)
						{

							bg = 0;
							SDL_Flip(screen);
						}

						else if (event1.motion.x > 325 && event1.motion.x <= 400 && event1.motion.y > 450 && event1.motion.y <= 500)
						{

							screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						else if (event1.motion.x > 189 && event1.motion.x <= 212 && event1.motion.y > 420 && event1.motion.y <= 431)
						{
							if (B18.pos1.x >= 0)
							{
								B18.pos1.x = B18.pos1.x - 25;
								m = m + 5;
								Mix_VolumeMusic(MIX_MAX_VOLUME / m);
							}
							B18.pos1.y = 385;
							B18.pos2.x = 0;
							B18.pos2.y = 0;
							B18.pos2.w = 1200;
							B18.pos2.h = 800;
							SDL_Flip(screen);
						}
						else if (event1.motion.x > 387 && event1.motion.x <= 422 && event1.motion.y > 412 && event1.motion.y <= 443)
						{
							if (B18.pos1.x >= -100)
							{
								B18.pos1.x = B18.pos1.x + 25;
								m = m - 5;
								Mix_VolumeMusic(MIX_MAX_VOLUME / m);
							}
							B18.pos1.y = 385;
							B18.pos2.x = 0;
							B18.pos2.y = 0;
							B18.pos2.w = 1200;
							B18.pos2.h = 800;
							SDL_Flip(screen);
						}
						break;
					}
				}
			}
			bg = 1;
			i = 1;
			SDL_Flip(screen);
			if ((event.motion.x > 325) && (event.motion.x <= 425) && (event.motion.y > 525) && (event.motion.y <= 550))
			{
				done = 1;
			}
			if ((event.motion.x > 325) && (event.motion.x <= 425) && (event.motion.y > 450) && (event.motion.y <= 475))
			{
				while (bg)
				{
					afficher(Backg1, screen);
					afficher(B10, screen);
					displaytext1(t1, screen);
					displaytext2(t2, screen);
					SDL_Flip(screen);
					SDL_WaitEvent(&event1);
					switch (event1.type)
					{
					case SDL_MOUSEMOTION:
						if (event1.motion.x > 400 && event1.motion.x <= 450 && event1.motion.y > 675 && event1.motion.y <= 710)
						{
							i6 = 1;
							afficher(B11, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (event1.motion.x > 400 && event1.motion.x <= 450 && event1.motion.y > 675 && event1.motion.y <= 710)
						{

							bg = 0;
							SDL_Flip(screen);
						}
						break;
					}
				}
				bg = 1;
				SDL_Flip(screen);
			}

			/************************* module perso  ********************************/
			//bouton start 
			if (event.motion.x > 163 && event.motion.x <= 535 && event.motion.y > 330 && event.motion.y <= 425)
			{
					//afficher le jeux + perso 
				perso(); 
			}
			bg = 1;
			i = 1;
			SDL_Flip(screen);
			if ((event.motion.x > 1063) && (event.motion.x <= 1146) && (event.motion.y > 690) && (event.motion.y <= 778))
			{
				done = 1;
			}
			if ((event.motion.x > 1068) && (event.motion.x <= 1146) && (event.motion.y > 690) && (event.motion.y <= 778))
			{
				while (bg)
				{
					afficher(Backg1, screen);
					afficher(B10, screen);
					displaytext1(t1, screen);
					displaytext2(t2, screen);
					SDL_Flip(screen);
					SDL_WaitEvent(&event);
					switch (event.type)
					{
					case SDL_MOUSEMOTION:
						printf("home");
						if (event.motion.x > 1070 && event.motion.x <= 1144 && event.motion.y > 700 && event.motion.y <= 777)
						{
							i6 = 1;
							afficher(B11, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (event1.motion.x > 1070 && event1.motion.x <= 1144 && event1.motion.y > 700 && event1.motion.y <= 777)
						{

							bg = 0;
							SDL_Flip(screen);
						}
						break;
					}
				}
				bg = 1;
				SDL_Flip(screen);
			}

			//**********************************************************
			if ((event.motion.x > 163) && (event.motion.x <= 535) && (event.motion.y > 640) && (event.motion.y <= 721))

			{
				while (bg)
				{
					afficher(Backg2, screen);
					afficher(B10, screen);
					afficher(B12, screen);
					afficher(B17, screen);
					afficher(B13, screen);
					afficher(B14, screen);
					displaytext2(t2, screen);
					SDL_Flip(screen);
					SDL_WaitEvent(&event1);
					switch (event1.type)
					{
					case SDL_MOUSEMOTION:
						if ((event.motion.x > 163) && (event.motion.x <= 535) && (event.motion.y > 640) && (event.motion.y <= 721))
						{
							i6 = 1;
							afficher(B11, screen);
							Mix_PlayChannel(-1, son, 0);
							SDL_Flip(screen);
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (event1.motion.x > 400 && event1.motion.x <= 450 && event1.motion.y > 675 && event1.motion.y <= 710)
						{

							bg = 0;
							SDL_Flip(screen);
						}
						break;
					}
				}
				bg = 1;
				SDL_Flip(screen);
			}
			break;

		case SDL_MOUSEMOTION:
			printf("posisiton x = %d  \n position y =  %d", event.motion.x, event.motion.y);
			if (event.motion.x > 163 && event.motion.x <= 535 && event.motion.y > 330 && event.motion.y <= 425)
			{
				i1 = 1;
				afficher(B4, screen);
				Mix_PlayChannel(-1, son, 0);
				SDL_Flip(screen);
			}
			else

				if ((event.motion.x > 163) && (event.motion.x <= 535) && (event.motion.y > 486) && (event.motion.y <= 570))
			{
				i3 = 1;
				afficher(B6, screen);
				Mix_PlayChannel(-1, son, 0);
				SDL_Flip(screen);
			}
			else
				i3 = 0;
			if ((event.motion.x > 163) && (event.motion.x <= 535) && (event.motion.y > 640) && (event.motion.y <= 721))
			{
				i4 = 1;
				afficher(B7, screen);
				Mix_PlayChannel(-1, son, 0);
				SDL_Flip(screen);
			}
			else
				i4 = 0;
			break;
		}
	}

	liberer(Backg);
	liberer(Backg1);
	liberer(Backg2);
	liberer(Backgr);
	liberer(B10);
	liberer(B1);
	liberer(B2);
	liberer(B3);
	liberer(B4);
	liberer(B5);
	liberer(B6);
	liberer(B7);
	liberer(B8);
	liberer(B9);
	liberer(B10);
	liberer(B11);
	liberer(B12);
	liberer(B13);
	liberer(B14);
	liberer(B15);
	liberer(B16);
	liberer(B17);
	liberer(B18);
	liberer(B19);
	liberer(B20);
	freetext(t);
	freetext(t1);
	freetext(t2);
	Mix_FreeMusic(music);
	Mix_FreeChunk(son);
	return 0;
}
