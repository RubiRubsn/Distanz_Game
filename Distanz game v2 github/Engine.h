#pragma once
#include"struct_src.h"
#include <ctime>

/*
	Diese Headerdatei beinhaltet die Definiton von der Engine. Der Code der Engine findet sich in Engine.cpp, Sound_engine.cpp und textur_res.cpp
	Die Engine teilt sich auf in:
	HauptEngine, Grafik (genannt Zeichnen), Mausbehandlung (gennant Maus), und Soundbehandlung (gennant Sound).
*/


class engine {
private:
	//ist die Positon des Mausklicks umgerechnet in x,y des Spielfelds also Feld (links oben) A8 == 0,0 und die Buttons als eine Position ausserhalb des Spielfelds z.b. 90,90 die void position ist IMMER 100,100
	static koordinate cursor_klick_pos;
	//Position der aktuellen Position im selben Prinzip wie Mausklick
	static koordinate cursor_hover_pos;
	//Variable um die Aktivierung des Hovers (z.b. für sound) EINMALIG zu machen
	bool hover_einmalig;
	//handling der Positionskonsequenzen
	void pos_mgr();
	//Zeitvariablen zum Ingame-Timer
	static time_t zeit_beginn;
	int timer_help = 0;
	//Funktion zur Berechnung des Ingame-Timers
	void zeitberechnung(int ziffern[]);
	//Einrichtung des Fensters des Games
	void Fenster();
	//andere Klassen frienden
	friend class spielstein_handle;
	friend class Design;
	friend class Stein;
	friend class spielstein_handle;
	friend class ki;
	friend class Hauptmenue;

	/*Klasse zum zeichnen*/
	/*
		die Linienfunktion sowohl auch die Hintergrundfarbe wird von uns nicht genutz, sie bleiben trotzdem in der Engine um eventuell spätere Games mit dieser Engine zu realisieren.
	*/
	class Zeichnen {
	private:
		friend engine;
		Color BK_color = { 1, 1, 1 };
		void hintergrund();
	public:
		void BK_color_wechseln(Color farbe);
		void linie(GL_koordinate Punkt[], Color Farbe);
		void polygon(GL_koordinate Punkt[], GL_koordinate TexPunkt[], int Anzahl, int TextureID);

	};
public:
	/*Klasse zur Maus behandlung*/
	class Maus {
	private:
		//wird verwendet um den Klick einmalig zu machen
		bool click;

	public:
		/*
			Ausgabe der aktuellen Mausposition in der GL_koordinaten form.
			das sieht folgendermaßen aus:

					|
			-1,1	|	1,1
			--------|--------
			-1,-1	|	1,-1
					|
			fuer naehere Infos siehe Maus.mausposition();

		*/
		GL_koordinate mausposition();
		// wird true, wenn Maus geklickt ist
		bool klickbehandlung();
		/*
			Berechnung / Umwandlung der Mausposition in unsere Form der Koordinaten also wie oben beschrieben bei cursor_klick_pos / cursor_hover_pos 
		*/
		koordinate spielfeld_klick(GL_koordinate pos);
		koordinate settings_klick(GL_koordinate pos);
		koordinate Hauptmenue_klick(GL_koordinate pos);
		koordinate endscreen_klick(GL_koordinate pos);
	};
	class Sound {
	private:
	public:
		//Musik ist gemuted
		static bool mute;
		//Soundinitialisierung
		void sound_init();
		//Musik pausieren
		void music_pause();
		//Musik abspielen
		void play_music(int id);
		//Soundeffekt abspielen
		void play_sfx(int id);
		//Regelung der Lautstaerke
		void sound_tick_check(bool mus_fx);
		//Musikwiedergabe beenden
		void music_stop(int id);
		//Lautstaerke der Soundeffekts / musik
		static int fx_lvl;
		static int music_lvl;
	};
	Sound sound;
	Zeichnen zeichnen;
	Maus maus;
	//Zustand in dem sich das Spiel befindet: 0 = Hauptmenue, 1 = Einzelspieler, 2 = Mehrspieler  
	static int gamestate;
	// Variable, die speichert, ob KI leicht oder schwer eingestellt ist
	static int ki_lvl;
	// variable zur einstellung zuglvl 0== aus, 1==eigene, 2==alle
	static int zugvorschau_lvl;
	/*
	variable, die den zustand des layouts speicher: 0 == ingame, 1||4 == einstellungen, 3==Hauptmenue, 5==endscreen (also z.b. du hast verloren), 7==credits
	*/
	static int menue;
	static bool spieler;
	static bool reset;
	engine();
	void zeit_setzen(time_t zeit);
	//initialisierungen
	void Textur_init_first();
	void Textur_init_Hauptmenue();
	void tex_init_ingame();
	void tex_init_settings();
	//checkt ob das programm beendet wird und printet ein neues bild aus dem buffer
	bool tickhandling();
	//checkt ob das programm beendet wird un printet KEIN neues bild aus dem buffer
	bool tick_helper();
	int ende = 0; // Ende = 1 =>  Weiß hat gewonnen , Ende = 2 => Schwarz hat gewonnen, Ende = -10 => Programm wird beendet
};