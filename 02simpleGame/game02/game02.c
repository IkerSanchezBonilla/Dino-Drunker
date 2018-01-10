#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "menu.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define ONGI_ETORRI_MEZUA "Sakatu return =)"
#define JOKOA_PLAYER_IMAGE ".\\img\\dinobruno.bmp"
#define JOKOA_PLAYER_IMAGE2 ".\\img\\bruno.bmp"
#define JOKOA_FONDO_IMAGE ".\\img\\fondo.bmp"
#define JOKOA_ENEMY_IMAGE ".\\img\\invader.bmp"
#define LURRA ".\\img\\LURRA.bmp"
#define JOKO_MUSIKA ".\\sound\\jokoamusika.wav"

void jokoaMarraztu();
int JOKOA_jokalariaIrudiaSortu();
int JOKOA_fondoIrudiaSortu();




void jokoaMarraztu() {
	int x = 0, jump=0, ebentu=0 , k=120 ;
	
	JOKO_ELEMENTUA jokalaria, fondo, enemy,enemy2, lurra;
	
	enemy.pos.y = 330;
	enemy.pos.x = 600;
	enemy2.pos.y = 290;
	enemy2.pos.x = 600;
	jokalaria.pos.y = 272;
	jokalaria.pos.x = 100;
	lurra.pos.y = 372;
	lurra.pos.x = 0;

	fondo.id = JOKOA_fondoIrudiaSortu();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE);
	enemy.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
	enemy2.id = irudiaKargatu(JOKOA_ENEMY_IMAGE);
	lurra.id = irudiaKargatu(LURRA);

	//audioInit();
	loadTheMusic(JOKO_MUSIKA);
	playMusic();

	clock_t ts,t;
	int denbora = 0;
	ts = clock() + CLOCKS_PER_SEC;
	
	do {
		Sleep(4);
		//enemy.pos.x -= 2;
		enemy2.pos.x -= 2;
		lurra.pos.x -= 1;
		jokalaria.pos.y += jump;
		//irudiaMugitu(enemy.id, enemy.pos.x, enemy.pos.y);
		irudiaMugitu(enemy2.id, enemy2.pos.x, enemy2.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiaMugitu(lurra.id, lurra.pos.x, lurra.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
		ebentu = ebentuaJasoGertatuBada();
		jump = salto(jokalaria.pos.y, ebentu, jump);
		x=talka(jokalaria.pos.y, enemy.pos.x, k, enemy2.pos.x);
		//jokalaria.id=agacharse(jokalaria.id, ebentu);

		if ((ebentu == TECLA_DOWN)&&(k>20)) {
			irudiaKendu(jokalaria.id);
			jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE2);
			k = 0;
		}
		else if(k==120) {
			irudiaKendu(jokalaria.id);
			jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE);
		}
		if(k<150)k++;
	
		
		if (denbora >= 0)
		{
			if ((t = clock()) >= ts)
			{
				denbora++;
				ts = t + CLOCKS_PER_SEC;
			}
		}
		
		if (enemy.pos.x < 0)enemy.pos.x = 600;
		if (enemy2.pos.x < 0)enemy2.pos.x = 600;
		if (lurra.pos.x < -640) lurra.pos.x = 0;

	
 	} while (x == 0);
}


int JOKOA_fondoIrudiaSortu()
{
	int fondoId;
	fondoId = irudiaKargatu(JOKOA_FONDO_IMAGE);
	irudiaMugitu(fondoId, 0, 0);

	return fondoId;

}

int salto(int y, int ebentu, int jump) {

 	if ((ebentu == TECLA_SPACE) && (y == 272))
		jump = -2;
	if (jump != 0) {
		if (y == 150)jump = 2;
		else if (jump == -2) jump = -2;
		else if(y == 272) jump = 0;
		
	}
  	return jump;
}

int agacharse(int id, int ebentu) {
	if (ebentu == TECLA_DOWN) {
			irudiaKendu(id);
			id = irudiaKargatu(JOKOA_PLAYER_IMAGE2);
	}
	else {
		irudiaKendu(id);
		id = irudiaKargatu(JOKOA_PLAYER_IMAGE);
	}
	return id;
}

int talka(int jok_y, int enem_x , int k , int enem2_x) {
	int x = 0;

	if ((jok_y > 232) && (enem_x <= 162) && (enem_x > 102)) 
		x = 1;
	if ((k>120)&& (enem2_x <= 140) && (enem2_x > 102))  //k>120 esan nahi du zutik dagoela.
		x = 1;
	if ((k < 120) && (jok_y != 272) && (enem2_x <= 140) && (enem2_x > 102))//
		x = 1;
	return x;
}

/*enemy.pos.y = 330;
enemy.pos.x = 600;
enemy2.pos.y = 290;
enemy2.pos.x = 600;
jokalaria.pos.y = 272;
jokalaria.pos.x = 100;
lurra.pos.y = 372;
lurra.pos.x = 0;*/