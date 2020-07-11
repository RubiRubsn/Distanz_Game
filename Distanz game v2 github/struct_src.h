#pragma once
#include<iostream>

/*
	erstellen aller genutzen zusaetzlichen datentypen
*/

struct Color {
	float R, G, B;
};

struct koordinate {
	int x = 0, y = 0;
	friend bool operator==(koordinate a, koordinate b);
	friend bool operator!=(koordinate a, koordinate b);
	friend koordinate operator+(koordinate& a, koordinate& b);
	friend koordinate operator-(koordinate& a, koordinate& b);
	friend std::ostream& operator<<(std::ostream& str, koordinate& koord);
};

struct GL_koordinate {
	float x;
	float y;
};

struct obj_eigenschaften {
	GL_koordinate position;
};

struct spielsteine {
	koordinate koord;
	bool aktiv = true;
};

struct stein_src {
	spielsteine spiel_stein[4];
	friend std::ostream& operator<<(std::ostream& str, koordinate& koord);
	friend std::ostream& operator<<(std::ostream& str, stein_src src);
};

struct ki_daten {
	stein_src steine[2];
	koordinate zuege[4][48];
	bool spieler;
};

struct ki_feed {
	koordinate end_pos = { 0,0 };
	int nichts[2] = { 0,0 };
	int stein = 0;
};

struct ki_stein {
	koordinate koord;
	int stein;
};

struct save_dat {
	bool muted;
	int ki_lvl;
	int fx_lvl;
	int music_lvl;
	int zugvorschau_lvl;
};

struct timer_dat {
	bool timer_zustand = false;
	int timer = 0;
};