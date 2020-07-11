#include"engine.h";
#include<iostream>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#define	GLEW_STATIC
#include<GL/glew.h>
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include "SDL_syswm.h"
#include"struct_src.h"
#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"glew32s.lib")
#pragma comment(lib,"opengl32.lib")
#include <ctime>
#include"ki_src.h"

/*
	fuer naehere Infos siehe Engine.h
*/

using namespace std;

int engine::gamestate = 0;
bool engine::reset = false;

SDL_Window* window;
bool close = false;
HWND handle;


engine::engine() {
	Fenster();
}

/*Erstellung des Fensters*/
void engine::Fenster() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//festlegen des Programmtitels und der Groeße
	/*32 Bit*/ //window = SDL_CreateWindow("Distanz - Game 32BIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_OPENGL);
	/*64 Bit*/ window = SDL_CreateWindow("Distanz - Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	SDL_SysWMinfo systemInfo;
	SDL_VERSION(&systemInfo.version);
	SDL_GetWindowWMInfo(window, &systemInfo);
	//handle des fensters weitergeben
	handle = systemInfo.info.win.window;
}

/*Abfrage ob Programm beendet und Bild aus Bildbuffer printen*/
bool engine::tickhandling() {
	SDL_GL_SwapWindow(window);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			close = true;
		}
	}
	if (ende == -10) { close = true; }
	//zeichnen.hintergrund();
	pos_mgr();
	return close;

}

/*abfrage ob Programm beendet wurde*/
bool engine::tick_helper() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			close = true;
		}
	}
	return close;
}

/*Festlegung, der Buttonkonsequenzen*/
void engine::pos_mgr() {
	/*Ingame*/
	if (menue == 0) {
		if (maus.klickbehandlung()) {
			cursor_klick_pos = maus.spielfeld_klick(maus.mausposition());
		}
		else {
			cursor_klick_pos = { 100,100 };
		}
		cursor_hover_pos = maus.spielfeld_klick(maus.mausposition());
		//Hauptmenue button
		if (cursor_klick_pos.x == 40) {
			gamestate = 0;
			menue = 3;
			reset = true;
			sound.music_stop(2);
			sound.play_music(1);
			sound.play_sfx(1);
		}
		//Einstellungen
		if (cursor_klick_pos.x == 41) {
			menue = 1;
			timer_help = time(0) - zeit_beginn;
			sound.play_sfx(1);
		}
		//Musik pausieren
		if (cursor_klick_pos.x == 42) {
			sound.music_pause();
			sound.play_sfx(1);
		}
		//Hover sound
		if (cursor_hover_pos.x != 100 && cursor_hover_pos.x > 8 && hover_einmalig) {
			sound.play_sfx(3);
			hover_einmalig = false;
		}
		if (cursor_hover_pos.x == 100 && !hover_einmalig) {
			hover_einmalig = true;
		}
	}
	else if (menue == 1 || menue == 4) {
		/*Einstellungen*/
		if (maus.klickbehandlung()) {
			cursor_klick_pos = maus.settings_klick(maus.mausposition());
		}
		else {
			cursor_klick_pos = { 100,100 };
		}
		//Zurueck_button
		if (cursor_klick_pos.x == 1) {
			if (menue == 1) {
				menue = 0;
			}
			else {
				menue = 3;
			}
			zeit_beginn = time(0) - timer_help;
			sound.play_sfx(1);
		}
		//ki_lvl_button
		if (cursor_klick_pos.x == 2) {
			if (ki_lvl == 0) ki_lvl = 1; else ki_lvl = 0;
			sound.play_sfx(1);
		}
		//zugvorschau_button
		if (cursor_klick_pos.x == 3) {
			if (zugvorschau_lvl == 0) {
				zugvorschau_lvl = 1;
			}
			else if (zugvorschau_lvl == 1) {
				zugvorschau_lvl = 2;
			}
			else {
				zugvorschau_lvl = 0;
			}
			sound.play_sfx(1);
		}
		/*5-9 Musik slider*/
		if (cursor_klick_pos.x == 5) {
			sound.music_lvl = 0;
			sound.sound_tick_check(true);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 6) {
			sound.music_lvl = 1;
			sound.sound_tick_check(true);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 7) {
			sound.music_lvl = 2;
			sound.sound_tick_check(true);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 8) {
			sound.music_lvl = 3;
			sound.sound_tick_check(true);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 9) {
			sound.music_lvl = 4;
			sound.sound_tick_check(true);
			sound.play_sfx(1);
		}
		/*10-140 sfx slider*/
		if (cursor_klick_pos.x == 10) {
			sound.fx_lvl = 0;
			sound.sound_tick_check(false);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 11) {
			sound.fx_lvl = 1;
			sound.sound_tick_check(false);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 12) {
			sound.fx_lvl = 2;
			sound.sound_tick_check(false);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 13) {
			sound.fx_lvl = 3;
			sound.sound_tick_check(false);
			sound.play_sfx(1);
		}
		if (cursor_klick_pos.x == 14) {
			sound.fx_lvl = 4;
			sound.sound_tick_check(false);
			sound.play_sfx(1);
		}
		cursor_hover_pos = maus.settings_klick(maus.mausposition());
		/*Hover sound*/
		if (cursor_hover_pos.x != 100 && hover_einmalig) {
			if (cursor_hover_pos.x < 5 || cursor_hover_pos.x>14) {
				sound.play_sfx(3);
				hover_einmalig = false;
			}
		}
		if (cursor_hover_pos.x == 100 &&!hover_einmalig) {
			hover_einmalig = true;
		}
	}
	/*Hauptmenue*/
	else if (menue==3){
		if (maus.klickbehandlung()) {
			cursor_klick_pos = maus.Hauptmenue_klick(maus.mausposition());
		}
		else {
			cursor_klick_pos = { 100,100 };
		}
		cursor_hover_pos= maus.Hauptmenue_klick(maus.mausposition());
		//Singleplayer button
		if (cursor_klick_pos.x == 1) {
			gamestate = 1;
			menue = 0;
			sound.music_stop(1);
			sound.play_music(2);
			sound.play_sfx(1);
			zeit_setzen(time(0));
		}
		//multiplayer button
		if (cursor_klick_pos.x == 2) {
			gamestate = 2;
			menue = 0;
			sound.music_stop(1);
			sound.play_music(2);
			sound.play_sfx(1);
			zeit_setzen(time(0));
		}
		//Einstellungen button
		if (cursor_klick_pos.x == 3) {
			menue = 4;
			sound.play_sfx(1);
		}
		//Credits button
		if (cursor_klick_pos.x == 4) {
			sound.play_sfx(1);
			menue = 7;
		}
		//beenden button
		if (cursor_klick_pos.x == 5) {
			ende = -10;
			sound.play_sfx(1);
		}
		/*Hover sounds*/
		if (cursor_hover_pos.x != 100 && hover_einmalig) {
			sound.play_sfx(3);
			hover_einmalig = false;
		}
		if (cursor_hover_pos.x == 100 && !hover_einmalig) {
			hover_einmalig = true;
		}
	}
	/*gewonnen / verloren screen*/
	else if (menue == 5) {
		if (maus.klickbehandlung()) {
			cursor_klick_pos = maus.endscreen_klick(maus.mausposition());
		}
		else {
			cursor_klick_pos = { 100,100 };
		}
		cursor_hover_pos = maus.endscreen_klick(maus.mausposition());
		//Hauptmenue Button
		if (cursor_klick_pos.x == 1) {
			gamestate = 0;
			menue = 3;
			reset = true;
			sound.music_stop(2);
			sound.play_music(1);
			sound.play_sfx(1);
		}
		//Nochmal Button
		if (cursor_klick_pos.x == 2) {
			menue = 0;
			reset = true;
			zeit_setzen(time(0));
			sound.play_sfx(1);
		}
		/*hover sounds*/
		if (cursor_hover_pos.x != 100 && hover_einmalig) {
			sound.play_sfx(3);
			hover_einmalig = false;
		}
		if (cursor_hover_pos.x == 100 && !hover_einmalig) {
			hover_einmalig = true;
		}
	}
	/*Credits*/
	else if (menue == 7) {
		if (maus.klickbehandlung()) {
			//Irgndwo klicken
			menue = 3;
			sound.play_sfx(1);
		}
	}
}

void engine::zeit_setzen(time_t zeit) {
	zeit_beginn = zeit;
}

/*Umwandlung der zeit (in s) in vier Ziffern im MM:SS Format*/
void engine::zeitberechnung(int ziffern[]) {
	if (menue == 0) {
		int z_help = time(0) - zeit_beginn;
		int minuten = z_help / 60;
		int sekunden = z_help - (minuten * 60);
		if (minuten < 10) { ziffern[0] = 0; ziffern[1] = minuten; }
		if (minuten < 20 && minuten > 9) { ziffern[0] = 1; ziffern[1] = minuten - 10; }
		if (minuten < 30 && minuten > 19) { ziffern[0] = 2; ziffern[1] = minuten - 20; }
		if (minuten < 40 && minuten > 29) { ziffern[0] = 3; ziffern[1] = minuten - 30; }
		if (minuten < 50 && minuten > 39) { ziffern[0] = 4; ziffern[1] = minuten - 40; }
		if (minuten < 60 && minuten > 49) { ziffern[0] = 5; ziffern[1] = minuten - 50; }

		if (sekunden < 10) { ziffern[3] = 0; ziffern[4] = sekunden; }
		if (sekunden < 20 && sekunden > 9) { ziffern[3] = 1; ziffern[4] = sekunden - 10; }
		if (sekunden < 30 && sekunden > 19) { ziffern[3] = 2; ziffern[4] = sekunden - 20; }
		if (sekunden < 40 && sekunden > 29) { ziffern[3] = 3; ziffern[4] = sekunden - 30; }
		if (sekunden < 50 && sekunden > 39) { ziffern[3] = 4; ziffern[4] = sekunden - 40; }
		if (sekunden < 60 && sekunden > 49) { ziffern[3] = 5; ziffern[4] = sekunden - 50; }
		ziffern[2] = 12;
	}
}

/*Funktion zum zeichnen einer Linie*/
void engine::Zeichnen::linie(GL_koordinate Punkt[], Color Farbe) {
	glBegin(GL_LINES);
	glColor3f(Farbe.R, Farbe.G, Farbe.B);
	glVertex2f(Punkt[0].x,Punkt[0].y);
	glVertex2f(Punkt[1].x, Punkt[1].y);
	glEnd();
}

/*Funktion um Hintergrund zu printen*/
void engine::Zeichnen::hintergrund() {
	glClearColor(BK_color.R, BK_color.G, BK_color.B, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void engine::Zeichnen::BK_color_wechseln(Color farbe) {
	BK_color = farbe;
}

/*berechnen der Mausposition und umwandlung in GL-Koordinaten form*/
GL_koordinate engine::Maus::mausposition() {
	GL_koordinate erg;
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(handle, &pos);
	erg.x = (pos.x*0.0025) - 1; erg.y = ((pos.y * 0.0025) - 1)* (-1);
	return erg;
}

/*Funktion um Klicks einmalig zu machen*/
bool engine::Maus::klickbehandlung() {
	if (GetAsyncKeyState(VK_LBUTTON)) {
		click = true;
	}
	else if (click) {
		click = false;
		return true;
	}
	else { return false; }
	return false;
}


/*
Die Funktionen spielfeld_klick, settings_klick, hauptmenue_klick, endscreen_klick rechnen die Mauspostion von GL_Koordinaten in eine für uns besser handlebare Position um die nurnoch aus einer x und y Koordinate bestehen.
Diese kann durch eine einfache If-abfrage geklärt werden. Findet ein Klick zwischen den Koordinaten x1 und x2 und y1 und y2 (Hierbei gehört immer die obere und linke Kante mit zum Feld), gibt der Umrechner eine Integer Koordinate
der Form (x,y) zurueck.Diese wird dann im pos_mgr weiter verarbeitet. Ist die Klickpostion bekannt,hat der Klick eine Kosequenz, klickt man hingegen ins Nichts, gibt die Funktion (100,100) zurueck und es geschieht nichts.
Da sich in verschiedenen Interfaces Klickpositionen doppeln würden, hat jedes Interface eine eigene Umrechnungsfunktion. 
*/

/*Funktion zur Umrechnung der GL Koordinate im Ingame-Interface*/
koordinate engine::Maus::spielfeld_klick(GL_koordinate pos) {
	koordinate erg;
		if (pos.x < -0.95 || pos.x >= 0.65 || pos.y <= -0.65 || pos.y>0.95) {

		if(pos.x>=0.705 && pos.x <0.935 && pos.y > 0.603 && pos.y <=0.665) { //Hauptmenue
						erg.x = 40;
			erg.y = 40;																		
		}else if(pos.x>=0.705 && pos.x <0.935 && pos.y > 0.483 && pos.y <=0.545) { //einstellungen
						erg.x = 41;
			erg.y = 41;
		}else if(pos.x>=0.705 && pos.x <0.935 && pos.y > 0.363 && pos.y <=0.425) { //Mute
						erg.x = 42;
			erg.y = 42;
		}else {
			erg = { 100,100 };
		}
	}
	else {
		if (pos.x >= -0.95 && pos.x < -0.75) {									//Spalte 0
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 0;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 0;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 0;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 0;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 0;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 0;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 0;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 0;
				erg.y = 7;
			}
		}
		else if (pos.x >= -0.75 && pos.x < -0.55) {								//Spalte 1
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 1;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 1;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 1;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 1;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 1;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 1;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 1;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 1;
				erg.y = 7;
			}
		}
		else if (pos.x >= -0.55 && pos.x < -0.35) {								//Spalte 2
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 2;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 2;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 2;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 2;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 2;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 2;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 2;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 2;
				erg.y = 7;
			}
		}
		else if (pos.x >= -0.35 && pos.x < -0.15) {								//Spalte 3
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 3;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 3;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 3;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 3;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 3;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 3;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 3;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 3;
				erg.y = 7;
			}
		}
		else if (pos.x >= -0.15 && pos.x < 0.05) {								//Spalte 4
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 4;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 4;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 4;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 4;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 4;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 4;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 4;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 4;
				erg.y = 7;
			}
		}
		else if (pos.x >= 0.05 && pos.x < 0.25) {								//Spalte 5
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 5;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 5;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 5;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 5;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 5;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 5;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 5;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 5;
				erg.y = 7;
			}
		}
		else if (pos.x >= 0.25 && pos.x < 0.45) {								//Spalte 6
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 6;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 6;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 6;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 6;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 6;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 6;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 6;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 6;
				erg.y = 7;
			}
		}
		else if (pos.x >= 0.45 && pos.x < 0.65) {								//Spalte 7
			if (pos.y <= 0.95 && pos.y > 0.75) {
				erg.x = 7;
				erg.y = 0;
			}
			else if (pos.y <= 0.75 && pos.y > 0.55) {
				erg.x = 7;
				erg.y = 1;
			}
			else if (pos.y <= 0.55 && pos.y > 0.35) {
				erg.x = 7;
				erg.y = 2;
			}
			else if (pos.y <= 0.35 && pos.y > 0.15) {
				erg.x = 7;
				erg.y = 3;
			}
			else if (pos.y <= 0.15 && pos.y > -0.05) {
				erg.x = 7;
				erg.y = 4;
			}
			else if (pos.y <= -0.05 && pos.y > -0.25) {
				erg.x = 7;
				erg.y = 5;
			}
			else if (pos.y <= -0.25 && pos.y > -0.45) {
				erg.x = 7;
				erg.y = 6;
			}
			else if (pos.y <= -0.45 && pos.y > -0.65) {
				erg.x = 7;
				erg.y = 7;
			}
		}
	}
	return erg;
}
/*Funktion zur Umrechnung der GL Koordinate im Einstellungsinterface*/
koordinate engine::Maus::settings_klick(GL_koordinate pos) {
	koordinate erg;
	if(pos.x>=-0.2 && pos.x <0.2 && pos.y <=-0.575 && pos.y > -0.695) { // zurück
			erg.x = 1;
			erg.y = 1;																		
	}else if(pos.x>=-0.65 && pos.x <-0.15 && pos.y <=0.32 && pos.y > 0.2) { // leicht/schwer
			erg.x = 2;
			erg.y = 2;																		
	}else if(pos.x>=-0.65 && pos.x <-0.15 && pos.y <=-0.12 && pos.y > -0.24) { // zugvorschau
			erg.x = 3;
			erg.y = 3;																		
	}else if(pos.x>=0.05 && pos.x <0.75 &&pos.y <=0.105 && pos.y > -0.015) { // musik slider
		if (pos.x >= 0.05 && pos.x < 0.19) {
			erg.x = 5;
			erg.y = 5;
		}
		if (pos.x >= 0.19 && pos.x < 0.33) {
			erg.x = 6;
			erg.y = 6;
		}
		if (pos.x >= 0.33 && pos.x < 0.47) {
			erg.x = 7;
			erg.y = 7;
		}
		if (pos.x >= 0.47 && pos.x < 0.61) {
			erg.x = 8;
			erg.y = 8;
		}
		if (pos.x >= 0.61 && pos.x < 0.75) {
			erg.x = 9;
			erg.y = 9;
		}
	}
	else if (pos.x >= 0.05 && pos.x <0.75 && pos.y <= -0.335 && pos.y > -0.445) { // sfx slider
		if (pos.x >= 0.05 && pos.x < 0.19) {
			erg.x = 10;
			erg.y = 10;
		}
		if (pos.x >= 0.19 && pos.x < 0.33) {
			erg.x = 11;
			erg.y = 11;
		}
		if (pos.x >= 0.33 && pos.x < 0.47) {
			erg.x = 12;
			erg.y = 12;
		}
		if (pos.x >= 0.47 && pos.x < 0.61) {
			erg.x = 13;
			erg.y = 13;
		}
		if (pos.x >= 0.61 && pos.x < 0.75) {
			erg.x = 14;
			erg.y = 14;
		}

	}
	else {
		erg.x = 100; 
		erg.y = 100; 
	}

	return erg;
}
/*Funktion zur Umrechnung der GL Koordinate im Hauptmenueinterface*/
koordinate engine::Maus::Hauptmenue_klick(GL_koordinate pos) {
	koordinate erg;
	if (pos.x >= 0.54 && pos.x <0.755 && pos.y <= 0.58 && pos.y > 0.52) { // Einzelspieler
		erg = { 1,1 };
	}
	else if (pos.x >= 0.53 && pos.x < 0.745 && pos.y <= 0.50 && pos.y >0.44) { // Mehrspieler
		erg = { 2,2 };
	}
	else if (pos.x >= 0.505 && pos.x <0.72 && pos.y <= 0.42 && pos.y > 0.36) { // Einstellungen
		erg = { 3,3 };
	}
	else if (pos.x >= 0.515 && pos.x < 0.73 && pos.y <= 0.34 && pos.y > 0.28) { // Credits
		erg = { 4,4 };
	}
	else if (pos.x >= -0.9 && pos.x < -0.5 && pos.y <= -0.82 && pos.y > -0.94) { // exit
		erg = { 5,5 };
	}
	else {
		erg = { 100,100 };
	}
	return erg;
}
/*Funktion zur Umrechnung der GL Koordinate im Endbldschirm*/
koordinate engine::Maus::endscreen_klick(GL_koordinate pos) {
	koordinate erg;
	if (pos.x >= -0.65 && pos.x <-0.15 && pos.y <= -0.49 && pos.y > -0.62) { // Hauptmenü
		erg = { 1,1 };
	}
	else if (pos.x >= 0.15 && pos.x < 0.65 && pos.y <= -0.49 && pos.y > -0.62){ // Neustart
		erg = { 2,2 };
	}
	else {
		erg = { 100,100 };
	}
	return erg;
}