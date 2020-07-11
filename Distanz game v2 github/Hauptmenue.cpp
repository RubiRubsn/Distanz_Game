#include "Hauptmenue.h"
#include "Engine.h"
#include "Design.h"
 /*Die Hauptmenue.cpp realisiert die Texturen und Buttons im Hauptmeneu.
Für eine genauere Beschreibung, wie das printen von Texturen funktioniert siehe Kommentare in der Design.cpp. 
Das Hauptmenue haben wir aufgrund seiner Besonderheit daraus ausgelagert. 
Vom Hauptmenue aus kann man in alle Spielmodi, die Einstellungem und Credits gelangen und auch das Spiel beenden.*/


/*Funktion zum printen des Hintergrund Artworks*/
void Hauptmenue::Design_HM::Background(engine& engine) {
	GL_koordinate Hintergrund[4] = { { -1.0f,1.0f }, { 1.0f,1.0f }, { 1.0f,-1.0f }, { -1.0f,-1.0f } };
	engine.zeichnen.polygon(Hintergrund, Textur, 4, 100); //Hauptmenü hintergrund
}
/*Funktion zum printen der Credits*/
void Hauptmenue::Design_HM::credits(engine& engine) {
	if (engine.menue == 7) {
		GL_koordinate credits[4] = { { -1.0f,1.0f }, { 1.0f,1.0f }, { 1.0f,-1.0f }, { -1.0f,-1.0f } };
		engine.zeichnen.polygon(credits, Textur, 4, 109); //credits
	}
}
/*Funktion zum printen aller Buttons und deren Hoverversion*/
void Hauptmenue::Design_HM::Buttons(engine& engine) {
	koordinate button_wert = engine.cursor_hover_pos;
	if(button_wert.x != 1 || engine.menue == 4){
	GL_koordinate Einzelspieler[4] = { { 0.54f,0.58f }, { 0.755f,0.58f }, { 0.755f,0.52f }, { 0.54f,0.52f } };
    engine.zeichnen.polygon(Einzelspieler,Textur, 4, 103); //einzelspieler
	}
	else {
		GL_koordinate Einzelspieler_pressed[4] = { { 0.54f,0.58f }, { 0.755f,0.58f }, { 0.755f,0.52f }, { 0.54f,0.52f } };
		engine.zeichnen.polygon(Einzelspieler_pressed, Textur, 4, 104); //einzelspieler pressed
	}

	if (button_wert.x != 2 || engine.menue == 4) {
		GL_koordinate Mehrspieler[4] = { { 0.53f,0.50f }, { 0.745f,0.50f }, { 0.745f,0.44f }, { 0.53f,0.44f } };
		engine.zeichnen.polygon(Mehrspieler, Textur, 4, 105); //mehrspieler
	}
	else {
		GL_koordinate Mehrspieler_pressed[4] = { { 0.53f,0.50f }, { 0.745f,0.50f }, { 0.745f,0.44f }, { 0.53f,0.44f } };
		engine.zeichnen.polygon(Mehrspieler_pressed, Textur, 4, 106); //mehrspieler pressed
	}

	if (button_wert.x != 3 || engine.menue == 4) {
		GL_koordinate Einstellungen[4] = { { 0.505f,0.42f }, { 0.72f,0.42f }, { 0.72f,0.36f }, { 0.505f,0.36f } };
		engine.zeichnen.polygon(Einstellungen, Textur, 4, 102); //einstellung
	}
	else {
		GL_koordinate Einstellungen_pressed[4] = { { 0.505f,0.42f }, { 0.72f,0.42f }, { 0.72f,0.36f }, { 0.505f,0.36f } };
		engine.zeichnen.polygon(Einstellungen_pressed, Textur, 4, 101); //einstellung pressed
	}
	
	if (button_wert.x != 4 || engine.menue == 4) {
		GL_koordinate Tutorial[4] = { { 0.515f,0.34f }, { 0.73f,0.34f }, { 0.73f,0.28f }, { 0.515f,0.28f } };
		engine.zeichnen.polygon(Tutorial, Textur, 4, 107); //tutorial
	}
	else {
		GL_koordinate Tutorial_pressed[4] = { { 0.515f,0.34f }, { 0.73f,0.34f }, { 0.73f,0.28f }, { 0.515f,0.28f } };
		engine.zeichnen.polygon(Tutorial_pressed, Textur, 4, 108); //tutorial pressed
	}
		
	if (button_wert.x != 5 || engine.menue == 4) {
		GL_koordinate exit[4] = { {-0.9f, -0.82f},{-0.5f, -0.82f},{-0.5f, -0.94f},{-0.9f,-0.94f} };
		engine.zeichnen.polygon(exit, Textur, 4, 113); //exit
	}
	else {
		GL_koordinate exit_pressed[4] = {{-0.9f, -0.82f},{-0.5f, -0.82f},{-0.5f, -0.94f},{-0.9f,-0.94f} };
		engine.zeichnen.polygon(exit_pressed, Textur, 4, 114); //exit pressed
	}
}


/*Funktuion zum Aufruf aller Hauptmenue design Funktionen*/
void Hauptmenue::Design_HM::in_menue(engine& engine) {
	Background(engine);
	Buttons(engine);
	credits(engine);
}
/*Funktion zum Aufrufen der Einstellung vom Hauptmenue aus*/
void Hauptmenue::Settings_handler(engine& engine, Design& design) {
	if (engine.menue == 4) {
		design.Einstellung_Interface(engine);
	}
}
/* Funktion zum Aufruf des Hauptmenues insgesamt*/
void Hauptmenue::Hauptmenue_handle(engine& engine, Design& design) {
	Design_HM.in_menue(engine);
	Settings_handler(engine, design);
}