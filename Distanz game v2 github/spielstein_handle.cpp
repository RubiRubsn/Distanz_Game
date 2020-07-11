#include<iostream>
#include"spielstein_handle.h"
#include"Engine.h"
#include"Design.h"
#include"struct_src.h"
#include"Ki_src.h"

using namespace std;

/*
	fuer mehr Infos siehe spielstein_handle.h
*/

bool spielstein_handle::reset;

koordinate spielstein_handle::neue_pos(engine& engine,koordinate schritte[]) {
	bool help = false;
	koordinate erg;
	while (help == false) {
		//falls waehrend eines Zuges das Spiel beendet wird
		if (engine.tick_helper()) { break; }
		if (engine.maus.klickbehandlung()) {
			erg = engine.maus.spielfeld_klick(engine.maus.mausposition());
			for (int i = 0; i < 24; i++) {
				if (schritte[i].x == erg.x && schritte[i].y == erg.y) {
					help = true;
				}
				if (erg.x == 100 || erg.y == 100) {
					help = false;
				}
			}
		}
	}
	return erg;
}

void spielstein_handle::ki_zug(stein_src& steine_schwarz, stein_src& steine_weiss, koordinate neue_pos, int stein_id) {
	koordinate old_help;
	old_help = steine_schwarz.spiel_stein[stein_id].koord;
	steine_schwarz.spiel_stein[stein_id].koord = { 100,100 };
	if (stein_id == 3) {
		tausch_option(neue_pos, old_help, steine_schwarz, steine_weiss, false, true);
	}
	else {
		tausch_option(neue_pos, old_help, steine_schwarz, steine_weiss, false, false);
	}
	steine_schwarz.spiel_stein[stein_id].koord = neue_pos;
}

void spielstein_handle::neue_pos_berechner_helper(int beginn,int stein_id, stein_src steine, koordinate schritte[], koordinate schritte_help) {
	schritte[beginn].x = steine.spiel_stein[stein_id].koord.x + schritte_help.x;	
	schritte[beginn].y = steine.spiel_stein[stein_id].koord.y + schritte_help.y;

	schritte[beginn + 1].x = steine.spiel_stein[stein_id].koord.x + schritte_help.y;
	schritte[beginn + 1].y = steine.spiel_stein[stein_id].koord.y + schritte_help.x;

	schritte[beginn + 2].x = steine.spiel_stein[stein_id].koord.x - schritte_help.x;	
	schritte[beginn + 2].y = steine.spiel_stein[stein_id].koord.y + schritte_help.y;

	schritte[beginn + 3].x = steine.spiel_stein[stein_id].koord.x + schritte_help.y;
	schritte[beginn + 3].y = steine.spiel_stein[stein_id].koord.y - schritte_help.x;

	schritte[beginn + 4].x = steine.spiel_stein[stein_id].koord.x + schritte_help.x;	
	schritte[beginn + 4].y = steine.spiel_stein[stein_id].koord.y - schritte_help.y;

	schritte[beginn + 5].x = steine.spiel_stein[stein_id].koord.x - schritte_help.y;
	schritte[beginn + 5].y = steine.spiel_stein[stein_id].koord.y + schritte_help.x;

	schritte[beginn + 6].x = steine.spiel_stein[stein_id].koord.x - schritte_help.x;	
	schritte[beginn + 6].y = steine.spiel_stein[stein_id].koord.y - schritte_help.y;

	schritte[beginn + 7].x = steine.spiel_stein[stein_id].koord.x - schritte_help.y;
	schritte[beginn + 7].y = steine.spiel_stein[stein_id].koord.y - schritte_help.x;
}

void spielstein_handle::neue_pos_berechner(koordinate schritte[], stein_src steine, int stein_id) {
	koordinate schritte_help;
	int auswahl_help[6];
	switch (stein_id) {
	case 0:
		/*erste auswahl*/ auswahl_help[0] = 1; auswahl_help[1] = 2; /*zweite auswahl*/ auswahl_help[2] = 1; auswahl_help[3] = 3; /*dritte auswahl*/ auswahl_help[4] = 3; auswahl_help[5] = 2;
		break;
	case 1:
		/*erste auswahl*/ auswahl_help[0] = 0; auswahl_help[1] = 2; /*zweite auswahl*/ auswahl_help[2] = 0; auswahl_help[3] = 3; /*dritte auswahl*/ auswahl_help[4] = 3; auswahl_help[5] = 2;
		break;
	case 2:
		/*erste auswahl*/ auswahl_help[0] = 0; auswahl_help[1] = 1; /*zweite auswahl*/ auswahl_help[2] = 0; auswahl_help[3] = 3; /*dritte auswahl*/ auswahl_help[4] = 3; auswahl_help[5] = 1;
		break;
	case 3:
		/*erste auswahl*/ auswahl_help[0] = 0; auswahl_help[1] = 1; /*zweite auswahl*/ auswahl_help[2] = 0; auswahl_help[3] = 2; /*dritte auswahl*/ auswahl_help[4] = 1; auswahl_help[5] = 2;
		break;
	}
	if (steine.spiel_stein[auswahl_help[0]].aktiv && steine.spiel_stein[auswahl_help[1]].aktiv) {
		schritte_help = steine.spiel_stein[auswahl_help[0]].koord - steine.spiel_stein[auswahl_help[1]].koord;
		if (schritte_help.x < 0) { schritte_help.x* (-1); }
		if (schritte_help.y < 0) { schritte_help.y* (-1); }
		neue_pos_berechner_helper(0, stein_id, steine, schritte, schritte_help);
	}
	else { for (int a = 0; a < 8; a++) { schritte[a] = { 100,100 }; } }
	if (steine.spiel_stein[auswahl_help[2]].aktiv && steine.spiel_stein[auswahl_help[3]].aktiv) {
		schritte_help = steine.spiel_stein[auswahl_help[2]].koord - steine.spiel_stein[auswahl_help[3]].koord;
		if (schritte_help.x < 0) { schritte_help.x* (-1); }
		if (schritte_help.y < 0) { schritte_help.y* (-1); }
		neue_pos_berechner_helper(8, stein_id, steine, schritte, schritte_help);
	}
	else { for (int a = 8; a < 16; a++) { schritte[a] = { 100,100 }; } }
	if (steine.spiel_stein[auswahl_help[5]].aktiv && steine.spiel_stein[auswahl_help[4]].aktiv) {
		schritte_help = steine.spiel_stein[auswahl_help[4]].koord - steine.spiel_stein[auswahl_help[5]].koord;
		if (schritte_help.x < 0) { schritte_help.x* (-1); }
		if (schritte_help.y < 0) { schritte_help.y* (-1); }
		neue_pos_berechner_helper(16, stein_id, steine, schritte, schritte_help);
	}
	else { for (int a = 16; a < 24; a++) { schritte[a] = { 100,100 }; } }
	koordinate help_koord;
	koordinate err = { 100,100 };
	for (int x = 0; x < 24; x++) {
		if (schritte[x] != err) {
			for (int a = 0; a < 24; a++) {
				if (schritte[x] == schritte[a] && x != a) {
					schritte[a] = { 100,100 };
				}
			}
		}
	}
	for (int i = 0; i < 24; i++) {
		if (schritte[i].x > 7 || schritte[i].y > 7 || schritte[i].x < 0 || schritte[i].y < 0) { schritte[i] = { 100,100 }; }
	}
}

void spielstein_handle::tausch_option( koordinate neue_pos_help, koordinate alte_pos, stein_src&  steine_schwarz, stein_src& steine_weiss, bool spieler, bool koenig) {
	for (int x = 0; x < 4; x++) {
		if (neue_pos_help == steine_schwarz.spiel_stein[x].koord) {
			steine_schwarz.spiel_stein[x].koord = alte_pos;
			if (spieler) {
				steine_schwarz.spiel_stein[x].aktiv = false;
			}
			else if (koenig && x!=3) {
				steine_schwarz.spiel_stein[x].aktiv = true;
			}
		}
		if (neue_pos_help == steine_weiss.spiel_stein[x].koord) {
			steine_weiss.spiel_stein[x].koord = alte_pos;
			if (!spieler) {
				steine_weiss.spiel_stein[x].aktiv = false;
			}
			else if (koenig && x!=3) {
				steine_weiss.spiel_stein[x].aktiv = true;
			}
		}
	}
}

void spielstein_handle::vorschau_print(engine& engine, stein_src steine_schwarz, stein_src steine_weiss, koordinate schritte[],bool spieler, bool steine_typ ) {
	Design design;
	design.InGame(engine, steine_schwarz, steine_weiss);
	for (int a = 0; a < 24; a++) {
		design.Spielstein_grayed(engine, schritte[a], steine_typ, spieler);
	}
	engine.tick_helper();
}

void spielstein_handle::stein_bewegungs_aufruf(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss) {
	koordinate schritte[24];
	if (engine.cursor_klick_pos.x>-1 && engine.cursor_klick_pos.x < 8 && engine.cursor_klick_pos.y>-1 && engine.cursor_klick_pos.y > 8) {
		cout << "--- Position nicht geaendert ---\n";
	}else if (!engine.spieler) {
		for (int x = 0; x < 4; x++) {
			if (engine.cursor_klick_pos == steine_schwarz.spiel_stein[x].koord && steine_schwarz.spiel_stein[x].aktiv) {
				neue_pos_berechner(schritte, steine_schwarz, x);
				int zaehler = 0;
				for (int x = 0; x < 24; x++) {
					if (schritte[x].x != 100) { zaehler++; }
				}
				if (zaehler != 0) {
					engine.sound.play_sfx(2);
					if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, engine.spieler,  0); }
					else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, engine.spieler, 1); }
					koordinate new_help = neue_pos(engine, schritte);
					koordinate old_help = steine_schwarz.spiel_stein[x].koord;
					steine_schwarz.spiel_stein[x].koord = { 100,100 };
					if (x != 3) { tausch_option(new_help, old_help, steine_schwarz, steine_weiss, engine.spieler, false); }
					else { tausch_option(new_help, old_help, steine_schwarz, steine_weiss, engine.spieler, true); }
					steine_schwarz.spiel_stein[x].koord = new_help;
					engine.spieler = true;
					engine.sound.play_sfx(2);
					cout << "--- Position geaendert ---\n\n";
				}
				break;
			}
		}
	}
	else{
		for (int x = 0; x < 4; x++) {
			if (engine.cursor_klick_pos == steine_weiss.spiel_stein[x].koord && steine_weiss.spiel_stein[x].aktiv) {
				neue_pos_berechner(schritte, steine_weiss, x);
				int zaehler = 0;
				for (int x = 0; x < 24; x++) {
					if (schritte[x].x != 100) { zaehler++; }
				}				
				if (zaehler != 0) {
					engine.sound.play_sfx(2);
					if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, engine.spieler, 0); }
					else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, engine.spieler,1); }
					koordinate new_help = neue_pos(engine, schritte);
					koordinate old_help = steine_weiss.spiel_stein[x].koord;
					steine_weiss.spiel_stein[x].koord = { 100,100 };
					if (x != 3) { tausch_option(new_help, old_help, steine_schwarz, steine_weiss, engine.spieler, false); }
					else { tausch_option(new_help, old_help, steine_schwarz, steine_weiss, engine.spieler, true); }
					steine_weiss.spiel_stein[x].koord = new_help;
					engine.spieler = false;
					engine.sound.play_sfx(2);
					cout << "--- Position geaendert ---\n\n";
					break;
				}
			}
		}
	}
}

void spielstein_handle::hover(engine& engine, stein_src steine_schwarz,stein_src steine_weiss) {
	koordinate hover_pos = engine.cursor_hover_pos;
	if (engine.menue == 0) {
		if (engine.zugvorschau_lvl != 0) {
			if (hover_pos.x < 8 && hover_pos.x >= 0 && hover_pos.y >= 0 && hover_pos.y < 8) {
				for (int x = 0; x < 4; x++) {
					if (engine.zugvorschau_lvl == 1) {
						if (engine.spieler) {
							if (hover_pos == steine_weiss.spiel_stein[x].koord && steine_weiss.spiel_stein[x].aktiv) {
								koordinate schritte[24];
								neue_pos_berechner(schritte, steine_weiss, x);
								if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, true, 0); }
								else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, true, 1); }
							}
						}
						else {
							if (hover_pos == steine_schwarz.spiel_stein[x].koord && steine_schwarz.spiel_stein[x].aktiv) {
								koordinate schritte[24];
								neue_pos_berechner(schritte, steine_schwarz, x);
								if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, false, 0); }
								else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, false, 1); }
							}
						}
					}
					else {
						if (hover_pos == steine_schwarz.spiel_stein[x].koord && steine_schwarz.spiel_stein[x].aktiv) {
							koordinate schritte[24];
							neue_pos_berechner(schritte, steine_schwarz, x);
							if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, false, 0); }
							else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, false, 1); }
						}
						if (hover_pos == steine_weiss.spiel_stein[x].koord && steine_weiss.spiel_stein[x].aktiv) {
							koordinate schritte[24];
							neue_pos_berechner(schritte, steine_weiss, x);
							if (x != 3) { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, true, 0); }
							else { vorschau_print(engine, steine_schwarz, steine_weiss, schritte, true, 1); }
						}
					}
				}
			}
		}
	}
}

void spielstein_handle::gewinncheck(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss) {
	if (!steine_schwarz.spiel_stein[3].aktiv) {
		engine.ende = 1;
		engine.menue = 5;
	}
	if (!steine_weiss.spiel_stein[3].aktiv) {
		engine.ende = 2;
		engine.menue = 5;
	}
	int zaehler = 3;
	for (int i = 0; i < 3; i++) {
		if (!steine_schwarz.spiel_stein[i].aktiv) {
			zaehler--;
		}
	}
	if (zaehler < 2) {
		engine.ende = 1;
		engine.menue = 5;
	}
	zaehler = 3;
	for (int i = 0; i < 3; i++) {
		if (!steine_weiss.spiel_stein[i].aktiv) {
			zaehler--;
		}
	}
	if (zaehler < 2) {
		engine.ende = 2;
		engine.menue = 5;
	}
}

void spielstein_handle::tick_check_steine(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss) {
	hover(engine, steine_schwarz, steine_weiss);
	stein_bewegungs_aufruf(engine, steine_schwarz, steine_weiss);
	gewinncheck(engine, steine_schwarz, steine_weiss);
}