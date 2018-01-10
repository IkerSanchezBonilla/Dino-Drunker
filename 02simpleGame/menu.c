
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include <windows.h>
#include "ourTypes.h"
#include "game02.h"

void hasierakomenu() {
	POSIZIOA saguPos;
	saguPos = saguarenPosizioa();
	int x = 0;

	int ebentu = 0;
	JOKO_ELEMENTUA menu, kontrolak;

	kontrolak.id = irudiaKargatu(".\\img\\Dino Drunker - controles.bmp");

	menu.id = irudiaKargatu(".\\img\\Menu.bmp");
	irudiaMugitu(menu.id, 0, 0);



	do {
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != SAGU_BOTOIA_EZKERRA);
	if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213))
		jokoaMarraztu();
		Sleep(300);
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

	if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 236) && (saguPos.y < 289)) {
		do {
			irudiaKendu(menu.id);
			menu.id = irudiaKargatu(".\\img\\Dino Drunker - controles.bmp");
			irudiaMugitu(menu.id, 0, 0);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
			ebentu = 0;
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);
	}
	if ((saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 313) && (saguPos.y < 413)) {
		do {
			irudiaKendu(menu.id);
			menu.id = irudiaKargatu(".\\img\\Dino Drunker - creditos.bmp");
			irudiaMugitu(menu.id, 0, 0);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
			ebentu = 0;
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);
	}
}


	

