#pragma once
#include"struct_src.h"
#include"Engine.h"
#include "Design.h"

/* Diese Headerdatei beinhaltet die Definitionen des Hauptmenues. Der Code befindet sich in der Hauptmenue.cpp, der engine.cpp.*/

class Hauptmenue {
private:
	void Settings_handler(engine& engine, Design& design);
	class Design_HM {
	private:
		GL_koordinate Textur[4] = { { 0.0f,1.0f },{ 1.0f,1.0f} ,{ 1.0f,0.0f }, { 0.0f,0.0f } };
		void Buttons(engine &engine);
		void Background(engine& engine);
		void credits(engine& engine);
	public:
		void in_menue(engine& engine);
	};
	Design_HM Design_HM;
public:
	void Hauptmenue_handle(engine& engine, Design& design);
};