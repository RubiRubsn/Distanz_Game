#pragma once
#include"Engine.h"
#include"struct_src.h"
#include"Design.h"

/*
	Diese Klasse beschaeftigt sich mit allem was etwas mit Spielsteinen zutun hat.
	Das Berechnen aller moeglichen Positionen
	Das Berechnen von Spielsteintauschmoeglichlkeiten
	Das Handeln von Vorschau der Zuege sowie auch das hovern ueber Spielsteine
	Den Gewinn-/Verlustcheck
	Das Berechnen von Zuegen und das Ausfuehren der Zuege von  der KI.
*/

class spielstein_handle {
private:
	friend class ki;
	void neue_pos_berechner_helper(int beginn, int stein_id, stein_src steine, koordinate schritte[], koordinate schritte_help);
	void neue_pos_berechner(koordinate schritte[], stein_src steine, int stein_id);
	koordinate neue_pos(engine& engine, koordinate schritte[]);
	void tausch_option(koordinate neue_pos_help, koordinate alte_pos, stein_src& steine_schwarz, stein_src& steine_weiss, bool spieler, bool Koenig);
	void vorschau_print(engine& engine, stein_src steine_schwarz, stein_src steine_weiss, koordinate schritte[], bool steine_typ, bool spieler);
	void stein_bewegungs_aufruf(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss);
	void hover(engine& engine, stein_src steine_schwarz, stein_src  steine_weiss);
	void gewinncheck(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss);
public:
	static bool reset;
	void ki_zug(stein_src& steine_schwarz, stein_src& steine_weiss, koordinate neue_pos, int stein_id);
	//Funktion die alles was das indirekte Aufrufen von Steinen usw. aus dem Hauptprogramm handelt.
	void tick_check_steine(engine& engine, stein_src& steine_schwarz, stein_src& steine_weiss);
};
