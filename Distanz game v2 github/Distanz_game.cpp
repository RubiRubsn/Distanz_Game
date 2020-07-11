/*
 SIEHE README!!!!
*/
#include<iostream>
#include<windows.h>
#include"Engine.h"
#include"spielstein_handle.h"
#include"Design.h"
#include"struct_src.h"
#include"Ki_src.h"
#include"save.h"
#include"Hauptmenue.h"

/*abfragen ob Debug-Version oder Release-Version um Konsole- und ausgabe zu deaktivieren */
#ifdef _DEBUG
bool DEBUG = true;
#else
bool DEBUG = false;
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

/*spiel Initialisierung, Laden aller daten*/
void Spiel_Initialisierung(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss, Design& design, bool& reset, save_dat &daten, ki_daten &KI_daten, ki &Ki, save_manager &save_mgr ) {
	//erste init phase
		//Ladebildschirm in graka laden und displayen
		engine.Textur_init_first();
		//einstellungen laden
		daten = save_mgr.load();
		//ki Belohnungs und Verjuengungswerte einstellen
		Ki.werte_change(2, 6, 6, 10, 2);
		//texturen vom Hauptmenue einbinden
		engine.Textur_init_Hauptmenue();
	//zweite init phase
		//layout init
		//spieler weiss beginnt
		engine.spieler = true;
		//soundengine initialisieren
		engine.sound.sound_init();
		//steinpos festlegen
		steine_schwarz.spiel_stein[0] = { 1,0 }, true;
		steine_schwarz.spiel_stein[1] = { 4,0 }, true;
		steine_schwarz.spiel_stein[2] = { 5,0 }, true;
		steine_schwarz.spiel_stein[3] = { 2,0 }, true;
		steine_weiss.spiel_stein[0] = { 6,7 }, true ;
		steine_weiss.spiel_stein[1] = { 3,7 }, true;
		steine_weiss.spiel_stein[2] = { 2,7 }, true;
		steine_weiss.spiel_stein[3] = { 5,7 }, true;
		engine.ende = 0;
	//dritte init phase
		//restliche texturen laden
		engine.tex_init_ingame();
		engine.tex_init_settings();
		//einmaliges aufrufen der Klickabfrage um gecacheden klick vom programmstart zu verwerfen
		engine.maus.klickbehandlung();
		//refresh aufrufen
		engine.tickhandling();
		//ki mit daten füttern
		KI_daten.steine[0] = steine_weiss;
		KI_daten.steine[1] = steine_schwarz;
		KI_daten.spieler = true;
		reset = false;
		//einstellungen aus gespeichrten werten festlegen
		engine.ki_lvl = daten.ki_lvl;
		engine.zugvorschau_lvl = daten.zugvorschau_lvl;
		engine.sound.fx_lvl = daten.fx_lvl;
		engine.sound.music_lvl = daten.music_lvl;
		//start im Hauptmenue
		engine.menue = 3;
		//musik initialisierung
		engine.sound.fx_lvl = daten.fx_lvl;
		engine.sound.music_lvl = daten.music_lvl;
		engine.sound.mute = daten.muted;
		engine.sound.play_music(1);
		engine.sound.sound_tick_check(true);
		engine.sound.sound_tick_check(false);


}

/*Funktion zum einzelspieler*/
void singleplayer_game(engine &engine, stein_src &steine_schwarz, stein_src &steine_weiss, Design &design, spielstein_handle &stein_handler, ki& Ki, ki_daten& KI_daten, timer_dat &timer_dat, ki_feed& ki_feed) {
	//aufruf zum zeichnen des Spielfelds, der steine und des layouts 
	design.InGame(engine, steine_schwarz, steine_weiss);
	//abfrage ob das Programm beendet wurde um ein rechnen der Ki trotz beendung zu vermeiden
	if (engine.ende == 0) {
		//aufruf zur steinbehandlung also züge aber auch die Hover ueber steine funktion für mehr information->siehe spielstein_handle.cpp / .h
		stein_handler.tick_check_steine(engine, steine_schwarz, steine_weiss);
		//timer zur zugvorschau der ki
		if (timer_dat.timer_zustand && timer_dat.timer == 0) {
			timer_dat.timer = time(0);
		}
		//wenn spieler==schwarz, dann wird Ki aufgerufen
		if (!engine.spieler) {
			/*
				da diese funktion so ausgelegt ist, dass sie immer wieder aufgerufen wird müssen für den zwei sekunden print des neuen zuges ein Timer genutzt werden.
				dieser bestimmt auch, das die Ki nicht mehrfach aufgerufen wird wenn der neuzug noch angezeigt wird.
			*/
			if (!timer_dat.timer_zustand) {
				//um die bewegung des steins des spielers noch vorm rechnen der Ki zu printen wird das InGame Layout geprintet um naeheres zu erfahren siehe Design.cpp / .h
				design.InGame(engine, steine_schwarz, steine_weiss);
				engine.tickhandling();
				//laden des aktuellen spielstands in die Ki
				KI_daten.steine[0] = steine_weiss;
				KI_daten.steine[1] = steine_schwarz;
				KI_daten.spieler = false;
				if (DEBUG) std::cout << "loading\n";
				//aufruf der Ki um Naeheres zu erfahren siehe KI_src.cpp / .h
				Ki.ki_iter(engine, 0, KI_daten, ki_feed.nichts, ki_feed.end_pos, ki_feed.stein);
				if (DEBUG) std::cout << " --- Ende\n";
			}
			//printen der zugvorschau der Ki
			if (time(0) - timer_dat.timer < 2 || !timer_dat.timer_zustand) {
				if (ki_feed.stein != 3){
					design.Spielstein_grayed(engine, ki_feed.end_pos, false, false);
				}
				else {
					design.Spielstein_grayed(engine, ki_feed.end_pos, true, false);
				}
				timer_dat.timer_zustand = true;
			}
			else {
				/*beenden des Ki zugs*/
				//zug der Ki ausführen
				stein_handler.ki_zug(steine_schwarz, steine_weiss, ki_feed.end_pos, ki_feed.stein);
				//spieler wechsel
				engine.spieler = true;
				//bewegungs sound spielen
				engine.sound.play_sfx(2);
				//zuruecksetzen von variablen
				timer_dat.timer = 0;
				timer_dat.timer_zustand = false;
				ki_feed.end_pos = { 0,0 };
				ki_feed.nichts[0] = 0;
				ki_feed.nichts[1] = 0;
				ki_feed.stein = 0;
			}
		}
	}
}

/*Funktion zum Mehrspieler*/
void multiplayer_game(engine& engine, stein_src &steine_schwarz, stein_src &steine_weiss, Design &design, spielstein_handle &stein_handler) {
	//printen des InGames layouts siehe Design.cpp Design.cpp / .h
	design.InGame(engine, steine_schwarz, steine_weiss);
	if (engine.ende == 0) {
		//spielstein behandlung siehe spielstein_handle.cpp /.h
		stein_handler.tick_check_steine(engine, steine_schwarz, steine_weiss);
	}
}

/*Funktion zum Reset bei einem Game neustart*/
void steine_reset(engine &engine, stein_src &steine_schwarz, stein_src &steine_weiss, ki_daten &KI_daten) {
	//weiß beginnt
	engine.spieler = true;
	//steinpositionen festlegen
	steine_schwarz.spiel_stein[0] = { 1,0 }, true;
	steine_schwarz.spiel_stein[1] = { 4,0 }, true;
	steine_schwarz.spiel_stein[2] = { 5,0 }, true;
	steine_schwarz.spiel_stein[3] = { 2,0 }, true;
	steine_weiss.spiel_stein[0] = { 6,7 }, true;
	steine_weiss.spiel_stein[1] = { 3,7 }, true;
	steine_weiss.spiel_stein[2] = { 2,7 }, true;
	steine_weiss.spiel_stein[3] = { 5,7 }, true;
	//ki mit daten füttern
	KI_daten.steine[0] = steine_weiss;
	KI_daten.steine[1] = steine_schwarz;
	KI_daten.spieler = true;
	//engine variablen zuruecksetzen
	engine.reset = false;
	engine.ende = 0;
}

/*Funktion zum speichern von einstellungen*/
void speicher_aufruf(save_dat &daten, engine &engine, save_manager &save_mgr) {
	//einstellungen in daten kopieren
	daten.muted = engine.sound.mute;
	daten.ki_lvl = engine.ki_lvl;
	daten.zugvorschau_lvl = engine.zugvorschau_lvl;
	daten.music_lvl = engine.sound.music_lvl;
	daten.fx_lvl = engine.sound.fx_lvl;
	//daten speichern
	save_mgr.save(daten);
}

int main() {
	//erstellen aller daten
	engine engine;
	Design design;
	stein_src steine_schwarz, steine_weiss;
	spielstein_handle stein_handler;
	ki Ki;
	ki_daten KI_daten;
	ki_feed ki_feed;
	save_manager save_mgr;
	save_dat daten;
	Hauptmenue Hauptmenue;
	timer_dat timer_dat;
	//spiele initialisierung 
	Spiel_Initialisierung(engine, steine_schwarz, steine_weiss, design, stein_handler.reset, daten, KI_daten, Ki, save_mgr);
	/*
		die Nachfolgende funktion wiederholt sich so oft sie kann. die wiederholung dieser Funktion bestimmt die Framerate, fuer naehere infos siehe engine.cpp / engine.h ->tickhandling
	*/
	while (!engine.tickhandling()) {

		/*spiel zurueck setzen*/
		if (engine.reset) {
			steine_reset(engine, steine_schwarz, steine_weiss, KI_daten);
		}
		switch (engine.gamestate) {
		case 0:
			/*Hauptmenue*/
			Hauptmenue.Hauptmenue_handle(engine, design);
			break;
		case 1:
			/*Singleplayer*/
			singleplayer_game(engine, steine_schwarz, steine_weiss, design, stein_handler, Ki, KI_daten, timer_dat, ki_feed);
			break;
		case 2:
			/*Multiplayer*/
			multiplayer_game(engine, steine_schwarz, steine_weiss, design, stein_handler);
			break;
		}
	}
	
	//speichern der Einstellungen
	speicher_aufruf(daten, engine, save_mgr);

	return 0;
}