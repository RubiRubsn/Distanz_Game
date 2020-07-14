#pragma once
#include"Engine.h"
#include"spielstein_handle.h"
#include"struct_src.h"
#include <ctime>

/*fuer naehere infos siehe Design.cpp*/

class Design {
private:
	GL_koordinate Textur[4] = { { 0.0f,1.0f },{ 1.0f,1.0f} ,{ 1.0f,0.0f }, { 0.0f,0.0f } };
	friend class Hauptmenue;
	void Endscreen(engine& engine);
	void Spielfeld(engine& engine);
	void Interface(engine& engine);
	void print(engine& engine, int zahlen[]);
	void Einstellung_Interface(engine& engine);
public:
	void Spielstein(engine& engine, stein_src stein, bool spieler);
	void Spielstein_grayed(engine& engine, koordinate stein,bool steintyp, bool spieler);
	void InGame(engine& engine, stein_src steine_schwarz, stein_src steine_weiss);


};