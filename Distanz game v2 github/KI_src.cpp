#include"KI_src.h"
#include"struct_src.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;

/*
	fuer eine genaue beschreibung der Ki siehe ki_src.h!!!!!
*/

int ki::ganz_leicht;
int ki::leicht;
int ki::stark;
int ki::end;
float ki::belohnungs_verringerung;

ki::ki() {
}

ki::~ki() {
}


int ki::anzahl_bauern(stein_src stein) {
	int erg = 3;
	if (!stein.spiel_stein[0].aktiv) { erg--; }
	if (!stein.spiel_stein[1].aktiv) { erg--; }
	if (!stein.spiel_stein[2].aktiv) { erg--; }
	return erg;
}

void ki::werte_change(int g_l, int l, int s, int e, float b ) {
	ganz_leicht = g_l;
	leicht = l;
	stark = s;
	end = e;
	belohnungs_verringerung = b;
	cout << "werte geaendert auf:" << ganz_leicht << " " << leicht << " " << stark << " " << end <<" belohnungs_verringerung: "<<belohnungs_verringerung<< endl;
}

void ki::belohnung(stein_src spielstein, stein_src spielstein_gegner, koordinate neu, int belohnungs_lvl[], bool koenig) {
	int anzahl_bauern_gegner = anzahl_bauern(spielstein_gegner);
	/*eigentausch*/
	if (spielstein.spiel_stein[0].koord == neu && spielstein.spiel_stein[0].aktiv && !koenig) {
		//bestrafung
		belohnungs_lvl[0] -= stark;
	}
	if (spielstein.spiel_stein[1].koord == neu && spielstein.spiel_stein[1].aktiv && !koenig) {
		//bestrafung
		belohnungs_lvl[0] -= stark;
	}
	if (spielstein.spiel_stein[2].koord == neu && spielstein.spiel_stein[2].aktiv && !koenig) {
		//bestrafung
		belohnungs_lvl[0] -= stark;
	}
	if (spielstein.spiel_stein[0].koord == neu && spielstein.spiel_stein[0].aktiv && koenig) {
		//bestrafung
		belohnungs_lvl[0] -= ganz_leicht;
	}
	if (spielstein.spiel_stein[1].koord == neu && spielstein.spiel_stein[1].aktiv && koenig) {
		//bestrafung
		belohnungs_lvl[0] -= ganz_leicht;
	}
	if (spielstein.spiel_stein[2].koord == neu && spielstein.spiel_stein[2].aktiv && koenig) {
		//bestrafung
		belohnungs_lvl[0] -= ganz_leicht;
	}
	/*gefangennahme*/
	if (spielstein_gegner.spiel_stein[0].koord == neu && spielstein_gegner.spiel_stein[0].aktiv) {
		if (anzahl_bauern_gegner == 3) {
			belohnungs_lvl[0] = belohnungs_lvl[0] + leicht;
		}
		else {
			belohnungs_lvl[0] = belohnungs_lvl[0] + end;
		}
	}
	if (spielstein_gegner.spiel_stein[1].koord == neu && spielstein_gegner.spiel_stein[1].aktiv) {
		if (anzahl_bauern_gegner == 3) {
			belohnungs_lvl[0] = belohnungs_lvl[0] + leicht;
		}
		else {
			belohnungs_lvl[0] = belohnungs_lvl[0] + end;
		}
	}
	if (spielstein_gegner.spiel_stein[2].koord == neu && spielstein_gegner.spiel_stein[2].aktiv) {
		if (anzahl_bauern_gegner == 3) {
			belohnungs_lvl[0] = belohnungs_lvl[0] + leicht;
		}
		else {
			belohnungs_lvl[0] = belohnungs_lvl[0] + end;
		}
	}
	if (spielstein_gegner.spiel_stein[3].koord == neu) {
		belohnungs_lvl[0] = belohnungs_lvl[0] + end;
	}
	/*befreiung*/
	if (spielstein.spiel_stein[0].koord == neu && !spielstein.spiel_stein[0].aktiv && koenig ) {
		belohnungs_lvl[0] = belohnungs_lvl[0] + stark;
	}
	if (spielstein.spiel_stein[1].koord == neu && !spielstein.spiel_stein[1].aktiv && koenig ) {
		belohnungs_lvl[0] = belohnungs_lvl[0] + stark;
	}
	if (spielstein.spiel_stein[2].koord == neu && !spielstein.spiel_stein[2].aktiv && koenig ) {
		belohnungs_lvl[0] = belohnungs_lvl[0] + stark;
	}
}

void ki::ki_iter(engine& engine, int hoehe, ki_daten daten, int belohnungs_lvl[], koordinate& neue_pos_ki, int& stein) {
	int lvl_hoehe;
	if (engine.ki_lvl == 0) {
		lvl_hoehe = 1;
	}
	else {
		lvl_hoehe = 3; 
	}
	bool close = false;
	int zaehler=0;
	int zaehler_belohnungs_lvl[2] = { 0,0 };
	if(hoehe==0){
		for (int r = 0; r < 4; r++) {
			for (int h = 0; h < 24; h++) {
				belohnungs_lvl_entscheidung[r][h][0] = -1000;
				belohnungs_lvl_entscheidung[r][h][1] = -1000;
			}
		}
	}
	hoehe++;
	if (daten.spieler) {
		int anzahl_bauern_help = anzahl_bauern(daten.steine[0]);
		if (daten.steine[0].spiel_stein[0].aktiv) { handler.neue_pos_berechner(daten.zuege[0], daten.steine[0], 0); } else { for (int x = 0; x < 24; x++) { daten.zuege[0][x] = { 100,100 }; } }
		if (daten.steine[0].spiel_stein[1].aktiv) { handler.neue_pos_berechner(daten.zuege[1], daten.steine[0], 1); } else { for (int x = 0; x < 24; x++) { daten.zuege[1][x] = { 100,100 }; } }
		if (daten.steine[0].spiel_stein[2].aktiv) { handler.neue_pos_berechner(daten.zuege[2], daten.steine[0], 2); } else { for (int x = 0; x < 24; x++) { daten.zuege[2][x] = { 100,100 }; } }
		if (daten.steine[0].spiel_stein[3].aktiv) { handler.neue_pos_berechner(daten.zuege[3], daten.steine[0], 3); }
		else { 
			for (int a = 0; a < 4; a++) { 
				for (int x = 0; x < 24; x++) { 
					daten.zuege[a][x] = { 100,100 }; 
				} 
			} 
		}
		if (anzahl_bauern_help < 2) {
			for (int a = 0; a < 4; a++) { 
				for (int x = 0; x < 24; x++) { 
					daten.zuege[a][x] = { 100,100 }; 
				} 
			}
		}
	}
	else {
		int anzahl_bauern_help = anzahl_bauern(daten.steine[1]);
		if (daten.steine[1].spiel_stein[0].aktiv) { handler.neue_pos_berechner(daten.zuege[0], daten.steine[1], 0); } else { for (int x = 0; x < 24; x++) { daten.zuege[0][x] = { 100,100 }; } }
		if (daten.steine[1].spiel_stein[1].aktiv) { handler.neue_pos_berechner(daten.zuege[1], daten.steine[1], 1); } else { for (int x = 0; x < 24; x++) { daten.zuege[1][x] = { 100,100 }; } }
		if (daten.steine[1].spiel_stein[2].aktiv) { handler.neue_pos_berechner(daten.zuege[2], daten.steine[1], 2); } else { for (int x = 0; x < 24; x++) { daten.zuege[2][x] = { 100,100 }; } }
		if (daten.steine[1].spiel_stein[3].aktiv) { handler.neue_pos_berechner(daten.zuege[3], daten.steine[1], 3); }
		else {
			for (int a = 0; a < 4; a++) { for (int x = 0; x < 24; x++) { daten.zuege[a][x] = { 100,100 }; } }
		}
		if (anzahl_bauern_help < 2) {
			for (int a = 0; a < 4; a++) { for (int x = 0; x < 24; x++) { daten.zuege[a][x] = { 100,100 }; } }
		}
	}

	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 24; b++) {
			close = engine.tick_helper();
			if (daten.spieler && !close) {
				if (daten.zuege[a][b] != error && daten.steine[0].spiel_stein[a].aktiv) {
					//daten erzeuegen
					koordinate new_help;
					koordinate old_help;
					ki_daten copy_daten;
					int copy_belohnungs_lvl[2];

					//daten beschreiben
					new_help = daten.zuege[a][b];
					copy_daten = daten;
					old_help = copy_daten.steine[0].spiel_stein[a].koord;
					copy_belohnungs_lvl[0] = belohnungs_lvl[0];
					copy_belohnungs_lvl[1] = belohnungs_lvl[1];
					//ki erneut aufruf und Belohnungs verteilung
					if (a == 3) {
						belohnung(copy_daten.steine[0], copy_daten.steine[1], new_help, copy_belohnungs_lvl, true);
					}
					else {
						belohnung(copy_daten.steine[0], copy_daten.steine[1], new_help, copy_belohnungs_lvl,false);
					}
					handler.tausch_option(new_help, old_help, copy_daten.steine[0], copy_daten.steine[1], copy_daten.spieler, false);
					copy_daten.steine[0].spiel_stein[a].koord = new_help;
					copy_daten.spieler = false;
					if (hoehe < lvl_hoehe) {
						ki_iter(engine, hoehe, copy_daten, copy_belohnungs_lvl, new_help, stein);
					}
					if (copy_belohnungs_lvl[0] != 0) {
						zaehler++;
						zaehler_belohnungs_lvl[0] = zaehler_belohnungs_lvl[0] + copy_belohnungs_lvl[0];
						zaehler_belohnungs_lvl[1] = zaehler_belohnungs_lvl[1] + copy_belohnungs_lvl[1];
					}
					if (hoehe == 1) {
						belohnungs_lvl_entscheidung[a][b][0] = copy_belohnungs_lvl[0];
						belohnungs_lvl_entscheidung[a][b][1] = copy_belohnungs_lvl[1];
					}
				}
			}
			else if(!close){
				if (daten.zuege[a][b] != error && daten.steine[1].spiel_stein[a].aktiv) {
					//daten erzeuegen
					koordinate new_help;
					koordinate old_help;
					ki_daten copy_daten;
					int copy_belohnungs_lvl[2];
					//daten beschreiben
					new_help = daten.zuege[a][b];
					copy_daten = daten;
					old_help = copy_daten.steine[1].spiel_stein[a].koord;
					copy_belohnungs_lvl[0] = belohnungs_lvl[1];
					copy_belohnungs_lvl[1] = belohnungs_lvl[0];
					//ki erneut aufruf und Belohnungs verteilung
					if (a == 3) {
						belohnung(copy_daten.steine[1], copy_daten.steine[0], new_help, copy_belohnungs_lvl, true);
					}
					else {
						belohnung(copy_daten.steine[1], copy_daten.steine[0], new_help, copy_belohnungs_lvl, false);
					}
					int help = copy_belohnungs_lvl[0];
					copy_belohnungs_lvl[0] = copy_belohnungs_lvl[1];
					copy_belohnungs_lvl[1] = help;
					handler.tausch_option(new_help, old_help, copy_daten.steine[0], copy_daten.steine[1], copy_daten.spieler, false);
					copy_daten.steine[1].spiel_stein[a].koord = new_help;
					copy_daten.spieler = true;
					if (hoehe < lvl_hoehe) {
						ki_iter(engine, hoehe, copy_daten, copy_belohnungs_lvl, new_help, stein);
					}
					if (copy_belohnungs_lvl[0] != 0) {
						zaehler++;
						zaehler_belohnungs_lvl[0] = zaehler_belohnungs_lvl[0] + copy_belohnungs_lvl[0];
						zaehler_belohnungs_lvl[1] = zaehler_belohnungs_lvl[1] + copy_belohnungs_lvl[1];
					}
					if (hoehe == 1) {
						belohnungs_lvl_entscheidung[a][b][0] = copy_belohnungs_lvl[0];
						belohnungs_lvl_entscheidung[a][b][1] = copy_belohnungs_lvl[1];
						//cout << copy_belohnungs_lvl[1]<<endl;
					}
				}
			}
		}
	}
	if (hoehe == 1) {
		for (int r = 0; r < 4; r++) {
			for (int h = 0; h < 24; h++) {
				//cout << "stein: " << r << " Zug: " << h << "belohnungs_lvl_weiß: " << belohnungs_lvl_entscheidung[r][h][0] << " belohnungs_lvl_schwarz: " << belohnungs_lvl_entscheidung[r][h][1] << endl;
				belohnungs_lvl_entscheidung[r][h][0] = (belohnungs_lvl_entscheidung[r][h][0] *(-1)) + belohnungs_lvl_entscheidung[r][h][1];
				//cout <<"belohnungs_lvl:"<< belohnungs_lvl_entscheidung[r][h][0] << endl;
			}
		}
		int hoechster_wert = -100;
		for (int r = 0; r < 4; r++) {
			for (int h = 0; h < 24; h++) {
				if (hoechster_wert < belohnungs_lvl_entscheidung[r][h][0] && daten.zuege[r][h].x !=100) {
					hoechster_wert = belohnungs_lvl_entscheidung[r][h][0];
					//cout <<"höchster wert"<< hoechster_wert << endl;
				}
			}
		}
		koordinate position_max[96];
		for (int a = 0; a < 96; a++) {
			position_max[a] = { 0,0 };
		}
		int max_best = 0;
		for (int r = 0; r < 4; r++) {
			for (int h = 0; h < 24; h++) {
				if (hoechster_wert == belohnungs_lvl_entscheidung[r][h][0] && daten.zuege[r][h].x != 100) {
					position_max[max_best] = { r,h };
					if (ki_dev) {
						cout << " -- moeglicher Zug: ---\n";
						cout << "belohnungs Lvl: " << belohnungs_lvl_entscheidung[r][h][0] << endl;
						cout << "stein=x, zug_nr=y: " << position_max[max_best];
						cout << "Position " << daten.zuege[position_max[max_best].x][position_max[max_best].y] << "\n";
					}
					max_best++;
				}
			}
		}
		srand(time(0));
		int rand_zug;
		if (max_best == 0) {
			rand_zug = 0;
		}else {
			rand_zug = rand() % max_best; 
		}
		neue_pos_ki = daten.zuege[position_max[rand_zug].x][position_max[rand_zug].y];
		stein = position_max[rand_zug].x;
		if (ki_dev) {
			cout << " -- GEWAEHLTER ZUG: ---\n";
			cout << "belohnungs Lvl: " << belohnungs_lvl_entscheidung[position_max[rand_zug].x][position_max[rand_zug].y][0] << endl;
			cout << "stein=x, zug_nr=y: " << position_max[rand_zug];
			cout << "Position " << daten.zuege[position_max[rand_zug].x][position_max[rand_zug].y] << "\n";
		}
	}
	else {
		if (zaehler != 0) {
			zaehler_belohnungs_lvl[0] = zaehler_belohnungs_lvl[0] / zaehler;
			zaehler_belohnungs_lvl[1] = zaehler_belohnungs_lvl[1] / zaehler;
		}
		belohnungs_lvl[0] += zaehler_belohnungs_lvl[0];
		belohnungs_lvl[1] += zaehler_belohnungs_lvl[1];
		if (hoehe == 2) {
			belohnungs_lvl[0] /= belohnungs_verringerung;
			belohnungs_lvl[1] /= belohnungs_verringerung;
		}
	}
}