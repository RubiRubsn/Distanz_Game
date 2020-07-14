#include"Engine.h";
#include<iostream>
#define	GLEW_STATIC
#include<GL/glew.h>
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include "SDL_syswm.h"
#include"struct_src.h"
#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"glew32s.lib")
#pragma comment(lib,"opengl32.lib")
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
using namespace std;

/*
	Dieser Teil des Codes ist groessten Teils uninteressant da es stupide Einbindungen von Texturen sind.
	Lediglich die Funktion Polygon ist interessant.
*/


GLuint err, Schachbrett, neustart, neustart_pressed, bauer_schwarz, bauer_schwarz_transparent, bauer_weiss, bauer_weiss_transparent, Koenig_Hell, Koenig_Dunkel, Koenig_Hell_transparent, Koenig_Dunkel_transparent, Bauer_weiss_gef, Bauer_schwarz_gef, schrift_eins_weiss, schrift_eins_schwarz;
GLuint Layout, einstellung_trans, Hauptmenue_button, Hauptmenue_button_pressed, Musik_an_button, Musik_an_button_pressed, Musik_aus_button, Musik_aus_button_pressed, laden, schwarz_aktiv, weiss_aktiv;
GLuint slider, alle_zuege, alle_zuege_pressed, audio, eigene_zuege, zurueck, zurueck_pressed, eigene_zuege_pressed, ki_modus, leicht, leicht_pressed, musik, schwer, schwer_pressed, slider_kopf, slider_kopf_pressed, sound_fx, zugvorschau, background, einstellungen_header, vorschau_aus, vorschau_aus_pressed;
GLuint Background_menue, Einstellungen, Einstellungen_pressed, Einzelspieler, Einzelspieler_pressed, Mehrspieler, Mehrspieler_pressed, credits, credits_pressed;
GLuint Endbildschirm_gewonnen, Endbildschirm_weiﬂ, Endbildschirm_schwarz, Endbildschirm_verloren, credit_screen, beenden, beenden_pressed, hauptmenue_gold;


void engine::Textur_init_Hauptmenue() {
	int texWidth_Credits_screen = 0;
	int texHeight_Credits_screen = 0;
	int bitsPerPixel_Credits_screen = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Background_Credits_screen = stbi_load("src/assets/etc/Credits_screen.png", &texWidth_Credits_screen, &texHeight_Credits_screen, &bitsPerPixel_Credits_screen, 4);

	glGenTextures(1, &credit_screen);
	glBindTexture(GL_TEXTURE_2D, credit_screen);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Credits_screen, texHeight_Credits_screen, 0, GL_RGBA, GL_UNSIGNED_BYTE, Background_Credits_screen);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Background_menue = 0;
	int texHeight_Background_menue = 0;
	int bitsPerPixel_Background_menue = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Background_menue_Dat = stbi_load("src/backgrounds/Background_menue.png", &texWidth_Background_menue, &texHeight_Background_menue, &bitsPerPixel_Background_menue, 4);

	glGenTextures(1, &Background_menue);
	glBindTexture(GL_TEXTURE_2D, Background_menue);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Background_menue, texHeight_Background_menue, 0, GL_RGBA, GL_UNSIGNED_BYTE, Background_menue_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Einstellungen = 0;
	int texHeight_Einstellungen = 0;
	int bitsPerPixel_Einstellungen = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Einstellungen_Dat = stbi_load("src/buttons/Einstellungen.png", &texWidth_Einstellungen, &texHeight_Einstellungen, &bitsPerPixel_Einstellungen, 4);

	glGenTextures(1, &Einstellungen);
	glBindTexture(GL_TEXTURE_2D, Einstellungen);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Einstellungen, texHeight_Einstellungen, 0, GL_RGBA, GL_UNSIGNED_BYTE, Einstellungen_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	int texWidth_Einstellungen_pressed = 0;
	int texHeight_Einstellungen_pressed = 0;
	int bitsPerPixel_Einstellungen_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Einstellungen_pressed_Dat = stbi_load("src/buttons/Einstellungen_pressed.png", &texWidth_Einstellungen_pressed, &texHeight_Einstellungen_pressed, &bitsPerPixel_Einstellungen_pressed, 4);

	glGenTextures(1, &Einstellungen_pressed);
	glBindTexture(GL_TEXTURE_2D, Einstellungen_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Einstellungen_pressed, texHeight_Einstellungen_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Einstellungen_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Einzelspieler = 0;
	int texHeight_Einzelspieler = 0;
	int bitsPerPixel_Einzelspieler = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Einzelspieler_Dat = stbi_load("src/buttons/Einzelspieler.png", &texWidth_Einzelspieler, &texHeight_Einzelspieler, &bitsPerPixel_Einzelspieler, 4);

	glGenTextures(1, &Einzelspieler);
	glBindTexture(GL_TEXTURE_2D, Einzelspieler);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Einzelspieler, texHeight_Einzelspieler, 0, GL_RGBA, GL_UNSIGNED_BYTE, Einzelspieler_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Einzelspieler_pressed = 0;
	int texHeight_Einzelspieler_pressed = 0;
	int bitsPerPixel_Einzelspieler_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Einzelspieler_pressed_Dat = stbi_load("src/buttons/Einzelspieler_pressed.png", &texWidth_Einzelspieler_pressed, &texHeight_Einzelspieler_pressed, &bitsPerPixel_Einzelspieler_pressed, 4);

	glGenTextures(1, &Einzelspieler_pressed);
	glBindTexture(GL_TEXTURE_2D, Einzelspieler_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Einzelspieler_pressed, texHeight_Einzelspieler_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Einzelspieler_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Mehrspieler = 0;
	int texHeight_Mehrspieler = 0;
	int bitsPerPixel_Mehrspieler = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Mehrspieler_Dat = stbi_load("src/buttons/Mehrspieler.png", &texWidth_Mehrspieler, &texHeight_Mehrspieler, &bitsPerPixel_Mehrspieler, 4);

	glGenTextures(1, &Mehrspieler);
	glBindTexture(GL_TEXTURE_2D, Mehrspieler);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Mehrspieler, texHeight_Mehrspieler, 0, GL_RGBA, GL_UNSIGNED_BYTE, Mehrspieler_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Mehrspieler_pressed = 0;
	int texHeight_Mehrspieler_pressed = 0;
	int bitsPerPixel_Mehrspieler_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Mehrspieler_pressed_Dat = stbi_load("src/buttons/Mehrspieler_pressed.png", &texWidth_Mehrspieler_pressed, &texHeight_Mehrspieler_pressed, &bitsPerPixel_Mehrspieler_pressed, 4);

	glGenTextures(1, &Mehrspieler_pressed);
	glBindTexture(GL_TEXTURE_2D, Mehrspieler_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Mehrspieler_pressed, texHeight_Mehrspieler_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Mehrspieler_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Tutorial = 0;
	int texHeight_Tutorial = 0;
	int bitsPerPixel_Tutorial = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Tutorial_Dat = stbi_load("src/buttons/Credits.png", &texWidth_Tutorial, &texHeight_Tutorial, &bitsPerPixel_Tutorial, 4);

	glGenTextures(1, &credits);
	glBindTexture(GL_TEXTURE_2D, credits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Tutorial, texHeight_Tutorial, 0, GL_RGBA, GL_UNSIGNED_BYTE, Tutorial_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Tutorial_pressed = 0;
	int texHeight_Tutorial_pressed = 0;
	int bitsPerPixel_Tutorial_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Tutorial_pressed_Dat = stbi_load("src/buttons/Credits_pressed.png", &texWidth_Tutorial_pressed, &texHeight_Tutorial_pressed, &bitsPerPixel_Tutorial_pressed, 4);

	glGenTextures(1, &credits_pressed);
	glBindTexture(GL_TEXTURE_2D, credits_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Tutorial_pressed, texHeight_Tutorial_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Tutorial_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	int texWidth_Beenden = 0;
	int texHeight_Beenden = 0;
	int bitsPerPixel_Beenden = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Beenden_Dat = stbi_load("src/buttons/Beenden.png", &texWidth_Beenden, &texHeight_Beenden, &bitsPerPixel_Beenden, 4);

	glGenTextures(1, &beenden);
	glBindTexture(GL_TEXTURE_2D, beenden);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Beenden, texHeight_Beenden, 0, GL_RGBA, GL_UNSIGNED_BYTE, Beenden_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	int texWidth_Beenden_pressed = 0;
	int texHeight_Beenden_pressed = 0;
	int bitsPerPixel_Beenden_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Beenden_pressed_Dat = stbi_load("src/buttons/Beenden_Pressed.png", &texWidth_Beenden_pressed, &texHeight_Beenden_pressed, &bitsPerPixel_Beenden_pressed, 4);

	glGenTextures(1, &beenden_pressed);
	glBindTexture(GL_TEXTURE_2D, beenden_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Beenden_pressed, texHeight_Beenden_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Beenden_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

}

void engine::Textur_init_first() {
	int texWidth_Load = 0;
	int texHeight_Load = 0;
	int bitsPerPixel_Load = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Load_Dat = stbi_load("src/assets/etc/Load.png", &texWidth_Load, &texHeight_Load, &bitsPerPixel_Load, 4);

	glGenTextures(1, &laden);
	glBindTexture(GL_TEXTURE_2D, laden);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Load, texHeight_Load, 0, GL_RGBA, GL_UNSIGNED_BYTE, Load_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);



	GL_koordinate Textur[4] = { { 0.0f,1.0f },{ 1.0f,1.0f} ,{ 1.0f,0.0f }, { 0.0f,0.0f } };
	GL_koordinate Load[4] = { { -1.0f,1.0f },{ 1.0f,1.0f} ,{ 1.0f,-1.0f }, { -1.0f,-1.0f } };
	zeichnen.polygon(Load, Textur, 4, 55);
	tickhandling();
}

void engine::tex_init_ingame() {
	int texWidth_Hauptmenue_gold = 0;
	int texHeight_Hauptmenue_gold = 0;
	int bitsPerPixel_Hauptmenue_gold = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Hauptmenue_gold_Dat = stbi_load("src/buttons/Hauptmenue_gold.png", &texWidth_Hauptmenue_gold, &texHeight_Hauptmenue_gold, &bitsPerPixel_Hauptmenue_gold, 4);

	glGenTextures(1, &hauptmenue_gold);
	glBindTexture(GL_TEXTURE_2D, hauptmenue_gold);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Hauptmenue_gold, texHeight_Hauptmenue_gold, 0, GL_RGBA, GL_UNSIGNED_BYTE, Hauptmenue_gold_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Neustart = 0;
	int texHeight_Neustart = 0;
	int bitsPerPixel_Neustart = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Neustart_Dat = stbi_load("src/buttons/Neustart.png", &texWidth_Neustart, &texHeight_Neustart, &bitsPerPixel_Neustart, 4);

	glGenTextures(1, &neustart);
	glBindTexture(GL_TEXTURE_2D, neustart);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Neustart, texHeight_Neustart, 0, GL_RGBA, GL_UNSIGNED_BYTE, Neustart_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Neustart_pressed = 0;
	int texHeight_Neustart_pressed = 0;
	int bitsPerPixel_Neustart_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Neustart_pressed_Dat = stbi_load("src/buttons/Neustart_pressed.png", &texWidth_Neustart_pressed, &texHeight_Neustart_pressed, &bitsPerPixel_Neustart_pressed, 4);

	glGenTextures(1, &neustart_pressed);
	glBindTexture(GL_TEXTURE_2D, neustart_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Neustart_pressed, texHeight_Neustart_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Neustart_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Endbildschirm_gewonnen = 0;
	int texHeight_Endbildschirm_gewonnen = 0;
	int bitsPerPixel_Endbildschirm_gewonnen = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Endbildschirm_gewonnen_Dat = stbi_load("src/assets/ingame/Endbildschirm_gewonnen.png", &texWidth_Endbildschirm_gewonnen, &texHeight_Endbildschirm_gewonnen, &bitsPerPixel_Endbildschirm_gewonnen, 4);

	glGenTextures(1, &Endbildschirm_gewonnen);
	glBindTexture(GL_TEXTURE_2D, Endbildschirm_gewonnen);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Endbildschirm_gewonnen, texHeight_Endbildschirm_gewonnen, 0, GL_RGBA, GL_UNSIGNED_BYTE, Endbildschirm_gewonnen_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Endbildschirm_weiﬂ = 0;
	int texHeight_Endbildschirm_weiﬂ = 0;
	int bitsPerPixel_Endbildschirm_weiﬂ = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Endbildschirm_weiﬂ_Dat = stbi_load("src/assets/ingame/Endbildschirm_Weiss.png", &texWidth_Endbildschirm_weiﬂ, &texHeight_Endbildschirm_weiﬂ, &bitsPerPixel_Endbildschirm_weiﬂ, 4);

	glGenTextures(1, &Endbildschirm_weiﬂ);
	glBindTexture(GL_TEXTURE_2D, Endbildschirm_weiﬂ);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Endbildschirm_weiﬂ, texHeight_Endbildschirm_weiﬂ, 0, GL_RGBA, GL_UNSIGNED_BYTE, Endbildschirm_weiﬂ_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Endbildschirm_schwarz = 0;
	int texHeight_Endbildschirm_schwarz = 0;
	int bitsPerPixel_Endbildschirm_schwarz = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Endbildschirm_schwarz_dat = stbi_load("src/assets/ingame/Endbildschirm_Schwarz.png", &texWidth_Endbildschirm_schwarz, &texHeight_Endbildschirm_schwarz, &bitsPerPixel_Endbildschirm_schwarz, 4);

	glGenTextures(1, &Endbildschirm_schwarz);
	glBindTexture(GL_TEXTURE_2D, Endbildschirm_schwarz);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Endbildschirm_schwarz, texHeight_Endbildschirm_schwarz, 0, GL_RGBA, GL_UNSIGNED_BYTE, Endbildschirm_schwarz_dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Endbildschirm_verloren = 0;
	int texHeight_Endbildschirm_verloren = 0;
	int bitsPerPixel_Endbildschirm_verloren = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Endbildschirm_verloren_Dat = stbi_load("src/assets/ingame/Endbildschirm_verloren.png", &texWidth_Endbildschirm_verloren, &texHeight_Endbildschirm_verloren, &bitsPerPixel_Endbildschirm_verloren, 4);

	glGenTextures(1, &Endbildschirm_verloren);
	glBindTexture(GL_TEXTURE_2D, Endbildschirm_verloren);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Endbildschirm_verloren, texHeight_Endbildschirm_verloren, 0, GL_RGBA, GL_UNSIGNED_BYTE, Endbildschirm_verloren_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_schw_akt = 0;
	int texHeight_schw_akt = 0;
	int bitsPerPixel_schw_akt = 0;
	stbi_set_flip_vertically_on_load(true);
	auto schw_akt_Dat = stbi_load("src/assets/ingame/spieler_schwarz_aktiv.png", &texWidth_schw_akt, &texHeight_schw_akt, &bitsPerPixel_schw_akt, 4);

	glGenTextures(1, &schwarz_aktiv);
	glBindTexture(GL_TEXTURE_2D, schwarz_aktiv);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_schw_akt, texHeight_schw_akt, 0, GL_RGBA, GL_UNSIGNED_BYTE, schw_akt_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	int texWidth_weiss_aktiv = 0;
	int texHeight_weiss_aktiv = 0;
	int bitsPerPixel_weiss_aktiv = 0;
	stbi_set_flip_vertically_on_load(true);
	auto weiss_aktiv_Dat = stbi_load("src/assets/ingame/spieler_weiss_aktiv.png", &texWidth_weiss_aktiv, &texHeight_weiss_aktiv, &bitsPerPixel_weiss_aktiv, 4);

	glGenTextures(1, &weiss_aktiv);
	glBindTexture(GL_TEXTURE_2D, weiss_aktiv);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_weiss_aktiv, texHeight_weiss_aktiv, 0, GL_RGBA, GL_UNSIGNED_BYTE, weiss_aktiv_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Layout = 0;
	int texHeight_Layout = 0;
	int bitsPerPixel_Layout = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Layout_Dat = stbi_load("src/backgrounds/Layout.png", &texWidth_Layout, &texHeight_Layout, &bitsPerPixel_Layout, 4);

	glGenTextures(1, &Layout);
	glBindTexture(GL_TEXTURE_2D, Layout);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Layout, texHeight_Layout, 0, GL_RGBA, GL_UNSIGNED_BYTE, Layout_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Einstellungen_trans = 0;
	int texHeight_Einstellungen_trans = 0;
	int bitsPerPixel_Einstellungen_trans = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Einstellungen_trans_Dat = stbi_load("src/buttons/Einstellungen_trans.png", &texWidth_Einstellungen_trans, &texHeight_Einstellungen_trans, &bitsPerPixel_Einstellungen_trans, 4);

	glGenTextures(1, &einstellung_trans);
	glBindTexture(GL_TEXTURE_2D, einstellung_trans);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Einstellungen_trans, texHeight_Einstellungen_trans, 0, GL_RGBA, GL_UNSIGNED_BYTE, Einstellungen_trans_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Hauptmenue_button = 0;
	int texHeight_Hauptmenue_button = 0;
	int bitsPerPixel_Hauptmenue_button = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Hauptmenue_button_Dat = stbi_load("src/buttons/Hauptmenue_button.png", &texWidth_Hauptmenue_button, &texHeight_Hauptmenue_button, &bitsPerPixel_Hauptmenue_button, 4);

	glGenTextures(1, &Hauptmenue_button);
	glBindTexture(GL_TEXTURE_2D, Hauptmenue_button);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Hauptmenue_button, texHeight_Hauptmenue_button, 0, GL_RGBA, GL_UNSIGNED_BYTE, Hauptmenue_button_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Hauptmenue_button_pressed = 0;
	int texHeight_Hauptmenue_button_pressed = 0;
	int bitsPerPixel_Hauptmenue_button_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Hauptmenue_button_pressed_Dat = stbi_load("src/buttons/Hauptmenue_button_pressed.png", &texWidth_Hauptmenue_button_pressed, &texHeight_Hauptmenue_button_pressed, &bitsPerPixel_Hauptmenue_button_pressed, 4);

	glGenTextures(1, &Hauptmenue_button_pressed);
	glBindTexture(GL_TEXTURE_2D, Hauptmenue_button_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Hauptmenue_button_pressed, texHeight_Hauptmenue_button_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Hauptmenue_button_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Musik_an_button = 0;
	int texHeight_Musik_an_button = 0;
	int bitsPerPixel_Musik_an_button = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Musik_an_button_Dat = stbi_load("src/buttons/Musik_an.png", &texWidth_Musik_an_button, &texHeight_Musik_an_button, &bitsPerPixel_Musik_an_button, 4);

	glGenTextures(1, &Musik_an_button);
	glBindTexture(GL_TEXTURE_2D, Musik_an_button);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Musik_an_button, texHeight_Musik_an_button, 0, GL_RGBA, GL_UNSIGNED_BYTE, Musik_an_button_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Musik_an_button_pressed = 0;
	int texHeight_Musik_an_button_pressed = 0;
	int bitsPerPixel_Musik_an_button_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Musik_an_button_pressed_Dat = stbi_load("src/buttons/Musik_an_pressed.png", &texWidth_Musik_an_button_pressed, &texHeight_Musik_an_button_pressed, &bitsPerPixel_Musik_an_button_pressed, 4);

	glGenTextures(1, &Musik_an_button_pressed);
	glBindTexture(GL_TEXTURE_2D, Musik_an_button_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Musik_an_button_pressed, texHeight_Musik_an_button_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Musik_an_button_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Musik_aus_button = 0;
	int texHeight_Musik_aus_button = 0;
	int bitsPerPixel_Musik_aus_button = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Musik_aus_button_Dat = stbi_load("src/buttons/Musik_aus.png", &texWidth_Musik_aus_button, &texHeight_Musik_aus_button, &bitsPerPixel_Musik_aus_button, 4);

	glGenTextures(1, &Musik_aus_button);
	glBindTexture(GL_TEXTURE_2D, Musik_aus_button);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Musik_aus_button, texHeight_Musik_aus_button, 0, GL_RGBA, GL_UNSIGNED_BYTE, Musik_aus_button_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Musik_aus_button_pressed = 0;
	int texHeight_Musik_aus_button_pressed = 0;
	int bitsPerPixel_Musik_aus_button_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto Musik_aus_button_pressed_Dat = stbi_load("src/buttons/Musik_aus_pressed.png", &texWidth_Musik_aus_button_pressed, &texHeight_Musik_aus_button_pressed, &bitsPerPixel_Musik_aus_button_pressed, 4);

	glGenTextures(1, &Musik_aus_button_pressed);
	glBindTexture(GL_TEXTURE_2D, Musik_aus_button_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Musik_aus_button_pressed, texHeight_Musik_aus_button_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, Musik_aus_button_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_err = 0;
	int texHeight_err = 0;
	int bitsPerPixel_err = 0;
	stbi_set_flip_vertically_on_load(true);
	auto errDat = stbi_load("src/err.jpeg", &texWidth_err, &texHeight_err, &bitsPerPixel_err, 4);

	glGenTextures(1, &err);
	glBindTexture(GL_TEXTURE_2D, err);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_err, texHeight_err, 0, GL_RGBA, GL_UNSIGNED_BYTE, errDat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_Schachbrett = 0;
	int texHeight_Schachbrett = 0;
	int bitsPerPixel_Schachbrett = 0;
	stbi_set_flip_vertically_on_load(true);
	auto SchachbrettDat = stbi_load("src/assets/ingame/Schachbrett_textur.png", &texWidth_Schachbrett, &texHeight_Schachbrett, &bitsPerPixel_Schachbrett, 4);

	glGenTextures(1, &Schachbrett);
	glBindTexture(GL_TEXTURE_2D, Schachbrett);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_Schachbrett, texHeight_Schachbrett, 0, GL_RGBA, GL_UNSIGNED_BYTE, SchachbrettDat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_schwarz = 0;
	int texHeight_bauer_schwarz = 0;
	int bitsPerPixel_bauer_schwarz = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_schwarz_Dat = stbi_load("src/assets/ingame/Spielstein_Bauer_Dunkel.png", &texWidth_bauer_schwarz, &texHeight_bauer_schwarz, &bitsPerPixel_bauer_schwarz, 4);

	glGenTextures(1, &bauer_schwarz);
	glBindTexture(GL_TEXTURE_2D, bauer_schwarz);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_schwarz, texHeight_bauer_schwarz, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_schwarz_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_schwarz_transparent = 0;
	int texHeight_bauer_schwarz_transparent = 0;
	int bitsPerPixel_bauer_schwarz_transparent = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_schwarz_transparent_Dat = stbi_load("src/assets/ingame/Spielstein_Bauer_Dunkel_transparent.png", &texWidth_bauer_schwarz_transparent, &texHeight_bauer_schwarz_transparent, &bitsPerPixel_bauer_schwarz_transparent, 4);

	glGenTextures(1, &bauer_schwarz_transparent);
	glBindTexture(GL_TEXTURE_2D, bauer_schwarz_transparent);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_schwarz_transparent, texHeight_bauer_schwarz_transparent, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_schwarz_transparent_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_weiss = 0;
	int texHeight_bauer_weiss = 0;
	int bitsPerPixel_bauer_weiss = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_weiss_Dat = stbi_load("src/assets/ingame/Spielstein_Bauer_Hell.png", &texWidth_bauer_weiss, &texHeight_bauer_weiss, &bitsPerPixel_bauer_weiss, 4);

	glGenTextures(1, &bauer_weiss);
	glBindTexture(GL_TEXTURE_2D, bauer_weiss);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_weiss, texHeight_bauer_weiss, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_weiss_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_weiss_transparent = 0;
	int texHeight_bauer_weiss_transparent = 0;
	int bitsPerPixel_bauer_weiss_transparent = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_weiss_transparent_Dat = stbi_load("src/assets/ingame/Spielstein_Bauer_Hell_transparent.png", &texWidth_bauer_weiss_transparent, &texHeight_bauer_weiss_transparent, &bitsPerPixel_bauer_weiss_transparent, 4);

	glGenTextures(1, &bauer_weiss_transparent);
	glBindTexture(GL_TEXTURE_2D, bauer_weiss_transparent);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_weiss_transparent, texHeight_bauer_weiss_transparent, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_weiss_transparent_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_koenig_hell = 0;
	int texHeight_koenig_hell = 0;
	int bitsPerPixel_koenig_hell = 0;
	stbi_set_flip_vertically_on_load(true);
	auto koenig_hell_Dat = stbi_load("src/assets/ingame/Koenig_Hell.png", &texWidth_koenig_hell, &texHeight_koenig_hell, &bitsPerPixel_koenig_hell, 4);

	glGenTextures(1, &Koenig_Hell);
	glBindTexture(GL_TEXTURE_2D, Koenig_Hell);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_koenig_hell, texHeight_koenig_hell, 0, GL_RGBA, GL_UNSIGNED_BYTE, koenig_hell_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_koenig_dunkel = 0;
	int texHeight_koenig_dunkel = 0;
	int bitsPerPixel_koenig_dunkel = 0;
	stbi_set_flip_vertically_on_load(true);
	auto koenig_dunkel_Dat = stbi_load("src/assets/ingame/Koenig_Dunkel.png", &texWidth_koenig_dunkel, &texHeight_koenig_dunkel, &bitsPerPixel_koenig_dunkel, 4);

	glGenTextures(1, &Koenig_Dunkel);
	glBindTexture(GL_TEXTURE_2D, Koenig_Dunkel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_koenig_dunkel, texHeight_koenig_dunkel, 0, GL_RGBA, GL_UNSIGNED_BYTE, koenig_dunkel_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_koenig_hell_transparent = 0;
	int texHeight_koenig_hell_transparent = 0;
	int bitsPerPixel_koenig_hell_transparent = 0;
	stbi_set_flip_vertically_on_load(true);
	auto koenig_hell_transparent_Dat = stbi_load("src/assets/ingame/Koenig_Hell_trans.png", &texWidth_koenig_hell_transparent, &texHeight_koenig_hell_transparent, &bitsPerPixel_koenig_hell_transparent, 4);

	glGenTextures(1, &Koenig_Hell_transparent);
	glBindTexture(GL_TEXTURE_2D, Koenig_Hell_transparent);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_koenig_hell_transparent, texHeight_koenig_hell_transparent, 0, GL_RGBA, GL_UNSIGNED_BYTE, koenig_hell_transparent_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_koenig_Dunkel_transparent = 0;
	int texHeight_koenig_Dunkel_transparent = 0;
	int bitsPerPixel_koenig_Dunkel_transparent = 0;
	stbi_set_flip_vertically_on_load(true);
	auto koenig_Dunkel_transparent_Dat = stbi_load("src/assets/ingame/Koenig_Dunkel_trans.png", &texWidth_koenig_Dunkel_transparent, &texHeight_koenig_Dunkel_transparent, &bitsPerPixel_koenig_Dunkel_transparent, 4);

	glGenTextures(1, &Koenig_Dunkel_transparent);
	glBindTexture(GL_TEXTURE_2D, Koenig_Dunkel_transparent);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_koenig_Dunkel_transparent, texHeight_koenig_Dunkel_transparent, 0, GL_RGBA, GL_UNSIGNED_BYTE, koenig_Dunkel_transparent_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_weiss_gef = 0;
	int texHeight_bauer_weiss_gef = 0;
	int bitsPerPixel_bauer_weiss_gef = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_weiss_gef_Dat = stbi_load("src/assets/ingame/Bauer_Hell_Gefangen.png", &texWidth_bauer_weiss_gef, &texHeight_bauer_weiss_gef, &bitsPerPixel_bauer_weiss_gef, 4);

	glGenTextures(1, &Bauer_weiss_gef);
	glBindTexture(GL_TEXTURE_2D, Bauer_weiss_gef);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_weiss_gef, texHeight_bauer_weiss_gef, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_weiss_gef_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_bauer_schwarz_gef = 0;
	int texHeight_bauer_schwarz_gef = 0;
	int bitsPerPixel_bauer_schwarz_gef = 0;
	stbi_set_flip_vertically_on_load(true);
	auto bauer_schwarz_gef_Dat = stbi_load("src/assets/ingame/Bauer_Dunkel_gefangen.png", &texWidth_bauer_schwarz_gef, &texHeight_bauer_schwarz_gef, &bitsPerPixel_bauer_schwarz_gef, 4);

	glGenTextures(1, &Bauer_schwarz_gef);
	glBindTexture(GL_TEXTURE_2D, Bauer_schwarz_gef);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_bauer_schwarz_gef, texHeight_bauer_schwarz_gef, 0, GL_RGBA, GL_UNSIGNED_BYTE, bauer_schwarz_gef_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	int texWidth_schrift_eins_schwarz = 0;
	int texHeight_schrift_eins_schwarz = 0;
	int bitsPerPixel_schrift_eins_schwarz = 0;
	stbi_set_flip_vertically_on_load(true);
	auto schrift_eins_schwarz_Dat = stbi_load("src/assets/ingame/schrift_tex_schwarz.png", &texWidth_schrift_eins_schwarz, &texHeight_schrift_eins_schwarz, &bitsPerPixel_schrift_eins_schwarz, 4);

	glGenTextures(1, &schrift_eins_schwarz);
	glBindTexture(GL_TEXTURE_2D, schrift_eins_schwarz);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_schrift_eins_schwarz, texHeight_schrift_eins_schwarz, 0, GL_RGBA, GL_UNSIGNED_BYTE, schrift_eins_schwarz_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, 0);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void engine::tex_init_settings() {
	int texWidth_slider = 0;
	int texHeight_slider = 0;
	int bitsPerPixel_slider = 0;
	stbi_set_flip_vertically_on_load(true);
	auto slider_Dat = stbi_load("src/buttons/slider.png", &texWidth_slider, &texHeight_slider, &bitsPerPixel_slider, 4);

	glGenTextures(1, &slider);
	glBindTexture(GL_TEXTURE_2D, slider);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_slider, texHeight_slider, 0, GL_RGBA, GL_UNSIGNED_BYTE, slider_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_alle_zuege = 0;
	int texHeight_alle_zuege = 0;
	int bitsPerPixel_alle_zuege = 0;
	stbi_set_flip_vertically_on_load(true);
	auto alle_zuege_Dat = stbi_load("src/buttons/alle_zuege.png", &texWidth_alle_zuege, &texHeight_alle_zuege, &bitsPerPixel_alle_zuege, 4);

	glGenTextures(1, &alle_zuege);
	glBindTexture(GL_TEXTURE_2D, alle_zuege);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_alle_zuege, texHeight_alle_zuege, 0, GL_RGBA, GL_UNSIGNED_BYTE, alle_zuege_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);



	int texWidth_alle_zuege_pressed = 0;
	int texHeight_alle_zuege_pressed = 0;
	int bitsPerPixel_alle_zuege_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto alle_zuege_pressed_Dat = stbi_load("src/buttons/alle_zuege_pressed.png", &texWidth_alle_zuege_pressed, &texHeight_alle_zuege_pressed, &bitsPerPixel_alle_zuege_pressed, 4);

	glGenTextures(1, &alle_zuege_pressed);
	glBindTexture(GL_TEXTURE_2D, alle_zuege_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_alle_zuege_pressed, texHeight_alle_zuege_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, alle_zuege_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_slider_kopf = 0;
	int texHeight_slider_kopf = 0;
	int bitsPerPixel_slider_kopf = 0;
	stbi_set_flip_vertically_on_load(true);
	auto slider_kopf_Dat = stbi_load("src/buttons/slider_kopf.png", &texWidth_slider_kopf, &texHeight_slider_kopf, &bitsPerPixel_slider_kopf, 4);

	glGenTextures(1, &slider_kopf);
	glBindTexture(GL_TEXTURE_2D, slider_kopf);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_slider_kopf, texHeight_slider_kopf, 0, GL_RGBA, GL_UNSIGNED_BYTE, slider_kopf_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	
	int texWidth_audio = 0;
	int texHeight_audio = 0;
	int bitsPerPixel_audio = 0;
	stbi_set_flip_vertically_on_load(true);
	auto audio_Dat = stbi_load("src/assets/settings/audio.png", &texWidth_audio, &texHeight_audio, &bitsPerPixel_audio, 4);

	glGenTextures(1, &audio);
	glBindTexture(GL_TEXTURE_2D, audio);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_audio, texHeight_audio, 0, GL_RGBA, GL_UNSIGNED_BYTE, audio_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_eigene_zuege_pressed = 0;
	int texHeight_eigene_zuege_pressed = 0;
	int bitsPerPixel_eigene_zuege_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto eigene_zuege_pressed_Dat = stbi_load("src/buttons/eigene_zuege_pressed.png", &texWidth_eigene_zuege_pressed, &texHeight_eigene_zuege_pressed, &bitsPerPixel_eigene_zuege_pressed, 4);

	glGenTextures(1, &eigene_zuege_pressed);
	glBindTexture(GL_TEXTURE_2D, eigene_zuege_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_eigene_zuege_pressed, texHeight_eigene_zuege_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, eigene_zuege_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_background = 0;
	int texHeight_background = 0;
	int bitsPerPixel_background = 0;
	stbi_set_flip_vertically_on_load(true);
	auto background_Dat = stbi_load("src/assets/settings/background.png", &texWidth_background, &texHeight_background, &bitsPerPixel_background, 4);

	glGenTextures(1, &background);
	glBindTexture(GL_TEXTURE_2D, background);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_background, texHeight_background, 0, GL_RGBA, GL_UNSIGNED_BYTE, background_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_einstellungen_header = 0;
	int texHeight_einstellungen_header = 0;
	int bitsPerPixel_einstellungen_header = 0;
	stbi_set_flip_vertically_on_load(true);
	auto einstellungen_header_Dat = stbi_load("src/assets/settings/einstellungen_header.png", &texWidth_einstellungen_header, &texHeight_einstellungen_header, &bitsPerPixel_einstellungen_header, 4);

	glGenTextures(1, &einstellungen_header);
	glBindTexture(GL_TEXTURE_2D, einstellungen_header);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_einstellungen_header, texHeight_einstellungen_header, 0, GL_RGBA, GL_UNSIGNED_BYTE, einstellungen_header_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);



	int texWidth_ki_modus = 0;
	int texHeight_ki_modus = 0;
	int bitsPerPixel_ki_modus = 0;
	stbi_set_flip_vertically_on_load(true);
	auto ki_modus_Dat = stbi_load("src/assets/settings/ki_modus.png", &texWidth_ki_modus, &texHeight_ki_modus, &bitsPerPixel_ki_modus, 4);

	glGenTextures(1, &ki_modus);
	glBindTexture(GL_TEXTURE_2D, ki_modus);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_ki_modus, texHeight_ki_modus, 0, GL_RGBA, GL_UNSIGNED_BYTE, ki_modus_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	int texWidth_leicht = 0;
	int texHeight_leicht = 0;
	int bitsPerPixel_leicht = 0;
	stbi_set_flip_vertically_on_load(true);
	auto leicht_Dat = stbi_load("src/buttons/leicht.png", &texWidth_leicht, &texHeight_leicht, &bitsPerPixel_leicht, 4);

	glGenTextures(1, &leicht);
	glBindTexture(GL_TEXTURE_2D, leicht);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_leicht, texHeight_leicht, 0, GL_RGBA, GL_UNSIGNED_BYTE, leicht_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_leicht_pressed = 0;
	int texHeight_leicht_pressed = 0;
	int bitsPerPixel_leicht_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto leicht_pressed_Dat = stbi_load("src/buttons/leicht_pressed.png", &texWidth_leicht_pressed, &texHeight_leicht_pressed, &bitsPerPixel_leicht_pressed, 4);

	glGenTextures(1, &leicht_pressed);
	glBindTexture(GL_TEXTURE_2D, leicht_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_leicht_pressed, texHeight_leicht_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, leicht_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_musik = 0;
	int texHeight_musik = 0;
	int bitsPerPixel_musik = 0;
	stbi_set_flip_vertically_on_load(true);
	auto musik_Dat = stbi_load("src/assets/settings/musik.png", &texWidth_musik, &texHeight_musik, &bitsPerPixel_musik, 4);

	glGenTextures(1, &musik);
	glBindTexture(GL_TEXTURE_2D, musik);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_musik, texHeight_musik, 0, GL_RGBA, GL_UNSIGNED_BYTE, musik_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_schwer = 0;
	int texHeight_schwer = 0;
	int bitsPerPixel_schwer = 0;
	stbi_set_flip_vertically_on_load(true);
	auto schwer_Dat = stbi_load("src/buttons/schwer.png", &texWidth_schwer, &texHeight_schwer, &bitsPerPixel_schwer, 4);

	glGenTextures(1, &schwer);
	glBindTexture(GL_TEXTURE_2D, schwer);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_schwer, texHeight_schwer, 0, GL_RGBA, GL_UNSIGNED_BYTE, schwer_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_schwer_pressed = 0;
	int texHeight_schwer_pressed = 0;
	int bitsPerPixel_schwer_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto schwer_pressed_Dat = stbi_load("src/buttons/schwer_pressed.png", &texWidth_schwer_pressed, &texHeight_schwer_pressed, &bitsPerPixel_schwer_pressed, 4);

	glGenTextures(1, &schwer_pressed);
	glBindTexture(GL_TEXTURE_2D, schwer_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_schwer_pressed, texHeight_schwer_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, schwer_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_slider_kopf_pressed = 0;
	int texHeight_slider_kopf_pressed = 0;
	int bitsPerPixel_slider_kopf_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto slider_kopf_pressed_Dat = stbi_load("src/buttons/slider_kopf_pressed.png", &texWidth_slider_kopf_pressed, &texHeight_slider_kopf_pressed, &bitsPerPixel_slider_kopf_pressed, 4);

	glGenTextures(1, &slider_kopf_pressed);
	glBindTexture(GL_TEXTURE_2D, slider_kopf_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_slider_kopf_pressed, texHeight_slider_kopf_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, slider_kopf_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_sound_fx = 0;
	int texHeight_sound_fx = 0;
	int bitsPerPixel_sound_fx = 0;
	stbi_set_flip_vertically_on_load(true);
	auto sound_fx_Dat = stbi_load("src/assets/settings/sound_fx.png", &texWidth_sound_fx, &texHeight_sound_fx, &bitsPerPixel_sound_fx, 4);

	glGenTextures(1, &sound_fx);
	glBindTexture(GL_TEXTURE_2D, sound_fx);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_sound_fx, texHeight_sound_fx, 0, GL_RGBA, GL_UNSIGNED_BYTE, sound_fx_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_zugvorschau = 0;
	int texHeight_zugvorschau = 0;
	int bitsPerPixel_zugvorschau = 0;
	stbi_set_flip_vertically_on_load(true);
	auto zugvorschau_Dat = stbi_load("src/assets/settings/zugvorschau.png", &texWidth_zugvorschau, &texHeight_zugvorschau, &bitsPerPixel_zugvorschau, 4);

	glGenTextures(1, &zugvorschau);
	glBindTexture(GL_TEXTURE_2D, zugvorschau);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_zugvorschau, texHeight_zugvorschau, 0, GL_RGBA, GL_UNSIGNED_BYTE, zugvorschau_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_vorschau_aus = 0;
	int texHeight_vorschau_aus = 0;
	int bitsPerPixel_vorschau_aus = 0;
	stbi_set_flip_vertically_on_load(true);
	auto vorschau_aus_Dat = stbi_load("src/buttons/vorschau_aus.png", &texWidth_vorschau_aus, &texHeight_vorschau_aus, &bitsPerPixel_vorschau_aus, 4);

	glGenTextures(1, &vorschau_aus);
	glBindTexture(GL_TEXTURE_2D, vorschau_aus);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_vorschau_aus, texHeight_vorschau_aus, 0, GL_RGBA, GL_UNSIGNED_BYTE, vorschau_aus_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_vorschau_aus_pressed = 0;
	int texHeight_vorschau_aus_pressed = 0;
	int bitsPerPixel_vorschau_aus_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto vorschau_aus_pressed_Dat = stbi_load("src/buttons/vorschau_aus_pressed.png", &texWidth_vorschau_aus_pressed, &texHeight_vorschau_aus_pressed, &bitsPerPixel_vorschau_aus_pressed, 4);

	glGenTextures(1, &vorschau_aus_pressed);
	glBindTexture(GL_TEXTURE_2D, vorschau_aus_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_vorschau_aus_pressed, texHeight_vorschau_aus_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, vorschau_aus_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


    int texWidth_eigene_zuege = 0;
	int texHeight_eigene_zuege = 0;
	int bitsPerPixel_eigene_zuege = 0;
	stbi_set_flip_vertically_on_load(true);
	auto eigene_zuege_Dat = stbi_load("src/buttons/eigene_zuege.png", &texWidth_eigene_zuege, &texHeight_eigene_zuege, &bitsPerPixel_eigene_zuege, 4);

	glGenTextures(1, &eigene_zuege);
	glBindTexture(GL_TEXTURE_2D, eigene_zuege);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_eigene_zuege, texHeight_eigene_zuege, 0, GL_RGBA, GL_UNSIGNED_BYTE, eigene_zuege_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


	int texWidth_zurueck = 0;
	int texHeight_zurueck = 0;
	int bitsPerPixel_zurueck = 0;
	stbi_set_flip_vertically_on_load(true);
	auto zurueck_Dat = stbi_load("src/buttons/zurueck.png", &texWidth_zurueck, &texHeight_zurueck, &bitsPerPixel_zurueck, 4);

	glGenTextures(1, &zurueck);
	glBindTexture(GL_TEXTURE_2D, zurueck);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_zurueck, texHeight_zurueck, 0, GL_RGBA, GL_UNSIGNED_BYTE, zurueck_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


    int texWidth_zurueck_pressed = 0;
	int texHeight_zurueck_pressed = 0;
	int bitsPerPixel_zurueck_pressed = 0;
	stbi_set_flip_vertically_on_load(true);
	auto zurueck_pressed_Dat = stbi_load("src/buttons/zurueck_pressed.png", &texWidth_zurueck_pressed, &texHeight_zurueck_pressed, &bitsPerPixel_zurueck_pressed, 4);

	glGenTextures(1, &zurueck_pressed);
	glBindTexture(GL_TEXTURE_2D, zurueck_pressed);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texWidth_zurueck_pressed, texHeight_zurueck_pressed, 0, GL_RGBA, GL_UNSIGNED_BYTE, zurueck_pressed_Dat);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);


}

/*Funktion zum zeichnen eines Polygons*/
void engine::Zeichnen::polygon(GL_koordinate Punkt[], GL_koordinate TexPunkt[], int Anzahl, int TextureID) {
	/*Switch Case zur Auswahl der Textur*/
	switch (TextureID) {
	case 0:
		break;
	case 1:
		glBindTexture(GL_TEXTURE_2D, Koenig_Hell);
		glEnable(GL_TEXTURE_2D);
		break;
	case 2:
		glBindTexture(GL_TEXTURE_2D, Koenig_Dunkel_transparent);
		glEnable(GL_TEXTURE_2D);
		break;
	case 3:
		glBindTexture(GL_TEXTURE_2D, Koenig_Hell_transparent);
		glEnable(GL_TEXTURE_2D);
		break;
	case 4:
		glBindTexture(GL_TEXTURE_2D, Schachbrett);
		glEnable(GL_TEXTURE_2D);
		break;
	case 5:
		glBindTexture(GL_TEXTURE_2D, bauer_schwarz);
		glEnable(GL_TEXTURE_2D);
		break;
	case 6:
		glBindTexture(GL_TEXTURE_2D, bauer_schwarz_transparent);
		glEnable(GL_TEXTURE_2D);
		break;
	case 7:
		glBindTexture(GL_TEXTURE_2D, bauer_weiss);
		glEnable(GL_TEXTURE_2D);
		break;
	case 8:
		glBindTexture(GL_TEXTURE_2D, bauer_weiss_transparent);
		glEnable(GL_TEXTURE_2D);
		break;
	case 9:
		glBindTexture(GL_TEXTURE_2D, Koenig_Dunkel);
		glEnable(GL_TEXTURE_2D);
		break;
	case 10:
		glBindTexture(GL_TEXTURE_2D, Bauer_schwarz_gef);
		glEnable(GL_TEXTURE_2D);
		break;
	case 11:
		glBindTexture(GL_TEXTURE_2D, Bauer_weiss_gef);
		glEnable(GL_TEXTURE_2D);
		break;
	case 12:
		glBindTexture(GL_TEXTURE_2D, Layout);
		glEnable(GL_TEXTURE_2D);
		break;
	case 13:
		glBindTexture(GL_TEXTURE_2D, einstellung_trans);
		glEnable(GL_TEXTURE_2D);
		break;
	case 15:
		glBindTexture(GL_TEXTURE_2D, Hauptmenue_button);
		glEnable(GL_TEXTURE_2D);
		break;
	case 16:
		glBindTexture(GL_TEXTURE_2D, Hauptmenue_button_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 17:
		glBindTexture(GL_TEXTURE_2D, Musik_an_button);
		glEnable(GL_TEXTURE_2D);
		break;
	case 18:
		glBindTexture(GL_TEXTURE_2D, Musik_an_button_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 19:
		glBindTexture(GL_TEXTURE_2D, Musik_aus_button);
		glEnable(GL_TEXTURE_2D);
		break;
	case 20:
		glBindTexture(GL_TEXTURE_2D, Musik_aus_button_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 21:
		glBindTexture(GL_TEXTURE_2D, schwarz_aktiv);
		glEnable(GL_TEXTURE_2D);
		break;
	case 22:
		glBindTexture(GL_TEXTURE_2D, weiss_aktiv);
		glEnable(GL_TEXTURE_2D);
		break;
	case 30:
		glBindTexture(GL_TEXTURE_2D, schrift_eins_weiss);
		glEnable(GL_TEXTURE_2D);
		break;
	case 31:
		glBindTexture(GL_TEXTURE_2D, schrift_eins_schwarz);
		glEnable(GL_TEXTURE_2D);
		break;
	case 55:
		glBindTexture(GL_TEXTURE_2D, laden);
		glEnable(GL_TEXTURE_2D);
		break;
	case 60:
		glBindTexture(GL_TEXTURE_2D, Endbildschirm_gewonnen);
		glEnable(GL_TEXTURE_2D);
		break;
	case 61:
		glBindTexture(GL_TEXTURE_2D, Endbildschirm_verloren);
		glEnable(GL_TEXTURE_2D);
		break;
	case 62:
		glBindTexture(GL_TEXTURE_2D, Endbildschirm_weiﬂ);
		glEnable(GL_TEXTURE_2D);
		break;
	case 63:
		glBindTexture(GL_TEXTURE_2D, Endbildschirm_schwarz);
		glEnable(GL_TEXTURE_2D);
		break;
	case 70: 		
		glBindTexture(GL_TEXTURE_2D, background);
		glEnable(GL_TEXTURE_2D);
		break;
	case 71:
		glBindTexture(GL_TEXTURE_2D, einstellungen_header);
		glEnable(GL_TEXTURE_2D);
		break;
	case 72:
		glBindTexture(GL_TEXTURE_2D, slider);
		glEnable(GL_TEXTURE_2D);
		break;
	case 73:
		glBindTexture(GL_TEXTURE_2D, slider_kopf);
		glEnable(GL_TEXTURE_2D);
		break;
	case 74:
		glBindTexture(GL_TEXTURE_2D, ki_modus);
		glEnable(GL_TEXTURE_2D);
		break;
	case 75:
		glBindTexture(GL_TEXTURE_2D, leicht);
		glEnable(GL_TEXTURE_2D);
		break;
	case 76:
		glBindTexture(GL_TEXTURE_2D, leicht_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 77:
		glBindTexture(GL_TEXTURE_2D, schwer);
		glEnable(GL_TEXTURE_2D);
		break;
	case 78:
		glBindTexture(GL_TEXTURE_2D, schwer_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 79:
		glBindTexture(GL_TEXTURE_2D, zugvorschau);
		glEnable(GL_TEXTURE_2D);
		break;
	case 80:
		glBindTexture(GL_TEXTURE_2D, alle_zuege);
		glEnable(GL_TEXTURE_2D);
		break;
	case 81:
		glBindTexture(GL_TEXTURE_2D, alle_zuege_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 82:
		glBindTexture(GL_TEXTURE_2D, eigene_zuege);
		glEnable(GL_TEXTURE_2D);
		break;
	case 83:
		glBindTexture(GL_TEXTURE_2D, eigene_zuege_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 84:
		glBindTexture(GL_TEXTURE_2D, vorschau_aus);
		glEnable(GL_TEXTURE_2D);
		break;
	case 85:
		glBindTexture(GL_TEXTURE_2D, vorschau_aus_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 86:
		glBindTexture(GL_TEXTURE_2D, audio);
		glEnable(GL_TEXTURE_2D);
		break;
	case 87:
		glBindTexture(GL_TEXTURE_2D, musik);
		glEnable(GL_TEXTURE_2D);
		break;
	case 88:
		glBindTexture(GL_TEXTURE_2D, sound_fx);
		glEnable(GL_TEXTURE_2D);
		break;
	case 89:
		glBindTexture(GL_TEXTURE_2D, zurueck);
		glEnable(GL_TEXTURE_2D);
		break;
	case 90:
		glBindTexture(GL_TEXTURE_2D, zurueck_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 91:
		glBindTexture(GL_TEXTURE_2D, slider_kopf_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 100:
		glBindTexture(GL_TEXTURE_2D, Background_menue);
		glEnable(GL_TEXTURE_2D);
		break;
	case 101:
		glBindTexture(GL_TEXTURE_2D, Einstellungen_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 102:
		glBindTexture(GL_TEXTURE_2D, Einstellungen);
		glEnable(GL_TEXTURE_2D);
		break;
	case 103:
		glBindTexture(GL_TEXTURE_2D, Einzelspieler);
		glEnable(GL_TEXTURE_2D);
		break;
	case 104:
		glBindTexture(GL_TEXTURE_2D, Einzelspieler_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 105:
		glBindTexture(GL_TEXTURE_2D, Mehrspieler);
		glEnable(GL_TEXTURE_2D);
		break;
	case 106:
		glBindTexture(GL_TEXTURE_2D, Mehrspieler_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 107:
		glBindTexture(GL_TEXTURE_2D, credits);
		glEnable(GL_TEXTURE_2D);
		break;
	case 108:
		glBindTexture(GL_TEXTURE_2D, credits_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 109:
		glBindTexture(GL_TEXTURE_2D, credit_screen);
		glEnable(GL_TEXTURE_2D);
		break;
	case 110:
		glBindTexture(GL_TEXTURE_2D, neustart);
		glEnable(GL_TEXTURE_2D);
		break;
	case 111:
		glBindTexture(GL_TEXTURE_2D, neustart_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	case 112:
		glBindTexture(GL_TEXTURE_2D, hauptmenue_gold);
		glEnable(GL_TEXTURE_2D);
		break;
	case 113:
		glBindTexture(GL_TEXTURE_2D, beenden);
		glEnable(GL_TEXTURE_2D);
		break;
	case 114:
		glBindTexture(GL_TEXTURE_2D, beenden_pressed);
		glEnable(GL_TEXTURE_2D);
		break;
	default:
		glBindTexture(GL_TEXTURE_2D, err);
		glEnable(GL_TEXTURE_2D);
		break;
	}
	/*polygon printen*/
	glBegin(GL_POLYGON);
	for (int a = 0; a < Anzahl; a++) {
		glTexCoord2f(TexPunkt[a].x, TexPunkt[a].y);  glVertex2f(Punkt[a].x, Punkt[a].y);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}