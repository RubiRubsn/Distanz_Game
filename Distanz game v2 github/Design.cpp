#include<iostream>
#include"Design.h"
#include <Windows.h>
#include"Engine.h"
#include <cwchar>
#include"spielstein_handle.h"
#include"struct_src.h"

/*
Die Design.cpp beschäftigt sich mit dem Zeichen und Anzeigen von den Texturen im Spiel und in den Einstellungen. 
Dies funktioniert folgendermaßen: Wir Zeichnen ein Polygon (eigentlich immer Rechtecke) mit den Koordinaten (x,y) für die Eckpunkte in der Reihenfolge (oben links,oben rechts, unten rechts, unten links)
GL_koordinate <name>[Anzahl der Ecken] = { { x1,y1 }, { x2,y2 }, { x3,y3 }, { x4,y4 } };
Dann wird mit unserer Zeichenengine das Polygon gezeichnet. Hierbei legen wir die vorher in die Grafikkarte geladene und nummerierte entsprechende Textur  in das Polygon.
engine.zeichnen.polygon(<name>,<Eckpunkte der Textur auf dem Polygon>, Anzahl der Ecken, Nummer der Textur );
Die Texturen werden von Hinten nach Vorne angezeigt. (weiter oben im Code = weiter hinten im Bild).
Nach diesem Schema werden alle Texturen im Spiel eingebunden.
*/


/*Funktion zum printen des Spielfelds und dem Hintergrund*/
void Design::Spielfeld(engine& engine) {
    GL_koordinate layout[4] = { { -1.0f,1.0f }, { 1.0f,1.0f }, { 1.0f,-1.0f }, { -1.0f,-1.0f } }; //Layout
    engine.zeichnen.polygon(layout,Textur, 4, 12);
    GL_koordinate Schachbrett[4] = { {-0.95f, 0.95f},{0.65f, 0.95f},{0.65f, -0.65f},{-0.95f, -0.65f} }; //Schachbrett
    engine.zeichnen.polygon(Schachbrett,Textur, 4,4);
}

/* Funktion zum printen der Zugvorschau für die Spielsteine*/
void Design::Spielstein_grayed(engine& engine, koordinate stein, bool steintyp, bool spieler) {
    int i = stein.x;
    int j = stein.y;
    if (stein.x != 100 && stein.y != 100){
        if (spieler == true) {
            if (steintyp == false) {
                GL_koordinate Bauer[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Zugvorschau Bauer Weiß
                engine.zeichnen.polygon(Bauer, Textur, 4, 8);
            }
            else {
                GL_koordinate Koenig[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Zugvorschau König Weiß
                engine.zeichnen.polygon(Koenig, Textur, 4, 3);
            }
        }
        else {
            if (steintyp == false) {
                GL_koordinate Bauer[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Zugvorschau Bauer Schwarz
                engine.zeichnen.polygon(Bauer, Textur, 4,6);
            }
            else {
                GL_koordinate Koenig[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Zugvorschau König Schwarz
                engine.zeichnen.polygon(Koenig, Textur, 4, 2);
            }
        }
    }
}
 /*Funktion zum printen der Spielsteine*/
void Design::Spielstein(engine& engine,stein_src stein, bool spieler) {
    int i=0, j=0;
    if (spieler == true) {
        if (stein.spiel_stein[0].aktiv == true) {   
            i = stein.spiel_stein[0].koord.x;
            j = stein.spiel_stein[0].koord.y;
            GL_koordinate Bauer1[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 1 Weiß
            engine.zeichnen.polygon(Bauer1, Textur, 4, 7);
        }else {                                     
            i = stein.spiel_stein[0].koord.x;
            j = stein.spiel_stein[0].koord.y;
            GL_koordinate Bauer[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Bauer 1 Weiß gefangen
            engine.zeichnen.polygon(Bauer, Textur, 4, 11);
        }
        if (stein.spiel_stein[1].aktiv == true) {    
            i = stein.spiel_stein[1].koord.x;
            j = stein.spiel_stein[1].koord.y;
            GL_koordinate Bauer2[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 2 Weiß
            engine.zeichnen.polygon(Bauer2, Textur, 4, 7);
        }
        else {                                         
            i = stein.spiel_stein[1].koord.x;
            j = stein.spiel_stein[1].koord.y;
            GL_koordinate Bauer2[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 2 Weiß gefangen
            engine.zeichnen.polygon(Bauer2, Textur, 4, 11);
        }
        
        if (stein.spiel_stein[2].aktiv == true) {     
            i = stein.spiel_stein[2].koord.x;
            j = stein.spiel_stein[2].koord.y;
            GL_koordinate Bauer3[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Bauer 3 Weiß
            engine.zeichnen.polygon(Bauer3, Textur, 4, 7);
        }
        else {                                         
            i = stein.spiel_stein[2].koord.x;
            j = stein.spiel_stein[2].koord.y;
            GL_koordinate Bauer3[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 3 Weiß gefangen
            engine.zeichnen.polygon(Bauer3, Textur, 4, 11);
        }
                                                      
        i = stein.spiel_stein[3].koord.x;
        j = stein.spiel_stein[3].koord.y;
        GL_koordinate Koenig[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//König Weiß
        engine.zeichnen.polygon(Koenig, Textur, 4,1);
    }
    else {
        
        if (stein.spiel_stein[0].aktiv == true) {    
            i = stein.spiel_stein[0].koord.x;
            j = stein.spiel_stein[0].koord.y;
            GL_koordinate Bauer1[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Bauer 1 Schwarz
            engine.zeichnen.polygon(Bauer1, Textur, 4, 5);
        }else {                                       
            i = stein.spiel_stein[0].koord.x;
            j = stein.spiel_stein[0].koord.y;
            GL_koordinate Bauer1[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} }; //Bauer 1 Schwarz gefangen
            engine.zeichnen.polygon(Bauer1, Textur, 4, 10);
        }
       
        if (stein.spiel_stein[1].aktiv == true) {           
            i = stein.spiel_stein[1].koord.x;
            j = stein.spiel_stein[1].koord.y;
            GL_koordinate Bauer2[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 2 Schwarz
            engine.zeichnen.polygon(Bauer2, Textur, 4, 5);
        }else {                                             
            i = stein.spiel_stein[1].koord.x;
            j = stein.spiel_stein[1].koord.y;
            GL_koordinate Bauer2[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 2 Schwarz gefangen
            engine.zeichnen.polygon(Bauer2, Textur, 4, 10);
        }
        
        if(stein.spiel_stein[2].aktiv == true){ 
            i = stein.spiel_stein[2].koord.x;
            j = stein.spiel_stein[2].koord.y;
            GL_koordinate Bauer3[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 3 Schwarz
            engine.zeichnen.polygon(Bauer3,Textur, 4, 5);
        }
        else {                                 
            i = stein.spiel_stein[2].koord.x;
            j = stein.spiel_stein[2].koord.y;
            GL_koordinate Bauer3[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//Bauer 3 Schwarz gefangen
            engine.zeichnen.polygon(Bauer3,Textur, 4, 10);
        }
                                                 
        i = stein.spiel_stein[3].koord.x;
        j = stein.spiel_stein[3].koord.y;
        GL_koordinate Koenig[4] = { {-0.93f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.93f + (-0.2 * j)},{-0.77f + (0.2 * i), 0.77f + (-0.2 * j)} ,{-0.93f + (0.2 * i), 0.77f + (-0.2 * j)} };//König Schwarz
        engine.zeichnen.polygon(Koenig, Textur, 4, 9);
    }
}
 /*Funktion zum printen des Endbilschirms*/
void Design::Endscreen(engine& engine) {
  

    if (engine.gamestate == 2) {
        if (engine.ende == 1) {
            GL_koordinate weis_gewonnen[4] = { {-1.0f, 1.0f},{1.0f, 1.0f},{1.0f, -1.0f},{-1.0f,-1.0f} }; //weis gewonnen
            engine.zeichnen.polygon(weis_gewonnen, Textur, 4, 62);
        }
        else if (engine.ende == 2) {
            GL_koordinate schwarz_gewonnen[4] = { {-1.0f, 1.0f},{1.0f, 1.0f},{1.0f, -1.0f},{-1.0f,-1.0f} }; //schwarz gewonnen
            engine.zeichnen.polygon(schwarz_gewonnen, Textur, 4, 63);
        }
    }
    else if (engine.gamestate == 1) {
        if (engine.ende == 2) {
            GL_koordinate du_hast_verloren[4] = { {-1.0f, 1.0f},{1.0f, 1.0f},{1.0f, -1.0f},{-1.0f,-1.0f} }; //du hast verloren
            engine.zeichnen.polygon(du_hast_verloren, Textur, 4, 61);
        }
        else if (engine.ende == 1) {
            GL_koordinate du_hast_gewonnen[4] = { {-1.0f, 1.0f},{1.0f, 1.0f},{1.0f, -1.0f},{-1.0f,-1.0f} }; //du hast gewonnen
            engine.zeichnen.polygon(du_hast_gewonnen, Textur, 4, 60);
        }
    }
    
        koordinate button_wert = engine.cursor_hover_pos;
     
      if (engine.ende == 1 || engine.ende == 2) {
        if (button_wert.x != 80) {
            GL_koordinate Hauptmenue_endscreen[4] = { {-0.65f, -0.49f},{-0.15f, -0.49f},{-0.15f, -0.62f},{-0.65f,-0.62f} }; //Hauptmenü
            engine.zeichnen.polygon(Hauptmenue_endscreen, Textur, 4, 112);
        }
        else {
            GL_koordinate Hauptmenue_endscreen_pressed[4] = { {-0.65f, -0.49f},{-0.15f, -0.49f},{-0.15f, -0.62f},{-0.65f,-0.62f} }; //Hauptmenü pressed
            engine.zeichnen.polygon(Hauptmenue_endscreen_pressed, Textur, 4, 16);
        }
        if (button_wert.x != 81) {
            GL_koordinate neustart[4] = { {0.15f, -0.49f}, { 0.65f, -0.49f }, { 0.65f,  -0.62f}, { 0.15f, -0.62f } }; // neustart
            engine.zeichnen.polygon(neustart, Textur, 4, 110);
        }
        else {
            GL_koordinate neustart_pressed[4] = { {0.15f, -0.49f}, { 0.65f, -0.49f }, { 0.65f,  -0.62f}, { 0.15f, -0.62f } }; // neustart pressed
            engine.zeichnen.polygon(neustart_pressed, Textur, 4, 111);
        }
    }
}
 /*Funktion zum printen des Einstellungsbildschirmes*/
void Design::Einstellung_Interface(engine& engine) {
    GL_koordinate HG[4] = { {-1.0f, 1.0f},{1.0f,1.0f},{1.0f,-1.0f},{-1.0,-1.0f} }; //Hintergrund
    engine.zeichnen.polygon(HG, Textur, 4, 70);
    koordinate button_wert = engine.cursor_hover_pos;
    if (button_wert.x != 50) {
        GL_koordinate exit[4] = { {-0.2f, -0.575f},{0.2f, -0.575f},{0.2f, -0.695f},{-0.2f,-0.695f} }; //zurück
        engine.zeichnen.polygon(exit, Textur, 4, 89);
    }
    else {
        GL_koordinate exit_pressed[4] = { {-0.2f, -0.575f},{0.2f, -0.575f},{0.2f, -0.695f},{-0.2f,-0.695f} }; //zurück pressed
        engine.zeichnen.polygon(exit_pressed, Textur, 4, 90);
    }

    GL_koordinate Header[4] = { {-0.75f, 0.95f},{0.75f, 0.95f},{0.75f, 0.627f},{-0.75f,0.627f} }; //Header
    engine.zeichnen.polygon(Header, Textur, 4, 71);

    GL_koordinate ki_modus[4] = { {-0.75f, 0.58f},{-0.05f, 0.58f},{-0.05f, 0.38f},{-0.75f,0.38f} }; // KI Modus
    engine.zeichnen.polygon(ki_modus, Textur, 4, 74);

    if (engine.ki_lvl == 0) {
        if (button_wert.x != 51) {
            GL_koordinate leicht[4] = { {-0.65f, 0.32f},{-0.15f, 0.32f},{-0.15f, 0.2f},{-0.65f,0.2f} }; // leicht
            engine.zeichnen.polygon(leicht, Textur, 4, 75);
        }
        else {
            GL_koordinate leicht_pressed[4] = { {-0.65f, 0.32f},{-0.15f, 0.32f},{-0.15f, 0.2f},{-0.65f,0.2f} }; // leicht pressed
            engine.zeichnen.polygon(leicht_pressed, Textur, 4, 76);
        }
    }
    else if (engine.ki_lvl == 1) {
        if (button_wert.x != 51) {
            GL_koordinate schwer[4] = { {-0.65f, 0.32f},{-0.15f, 0.32f},{-0.15f, 0.2f},{-0.65f,0.2f} }; // schwer
            engine.zeichnen.polygon(schwer, Textur, 4, 77);
        }
        else {
            GL_koordinate schwer_pressed[4] = { {-0.65f, 0.32f},{-0.15f, 0.32f},{-0.15f, 0.2f},{-0.65f,0.2f} }; // schwer pressed
            engine.zeichnen.polygon(schwer_pressed, Textur, 4, 78);
        }
    }

    GL_koordinate zugvorschau[4] = { {-0.75f, 0.14f},{-0.05f, 0.14f},{-0.06f, -0.06f},{-0.75f,-0.06f} }; // Zug vorschau
    engine.zeichnen.polygon(zugvorschau, Textur, 4, 79);

    if (engine.zugvorschau_lvl == 2) {
        if (button_wert.x != 52) {
            GL_koordinate alle_zuege[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // alle zuege
            engine.zeichnen.polygon(alle_zuege, Textur, 4, 80);
        }
        else {
            GL_koordinate alle_zuege_pressed[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // alle züge pressed
            engine.zeichnen.polygon(alle_zuege_pressed, Textur, 4, 81);
        }
    }
    else if (engine.zugvorschau_lvl == 1) {
        if (button_wert.x != 52) {
            GL_koordinate eigene_zuege[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // eigene zuege
            engine.zeichnen.polygon(eigene_zuege, Textur, 4, 82);
        }
        else {
            GL_koordinate eigene_zuege_pressed[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // eigene züge pressed
            engine.zeichnen.polygon(eigene_zuege_pressed, Textur, 4, 83);
        }
    }
    else if (engine.zugvorschau_lvl == 0) {
        if (button_wert.x != 52) {
            GL_koordinate zuege_aus[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // züge aus
            engine.zeichnen.polygon(zuege_aus, Textur, 4, 84);
        }
        else {
            GL_koordinate zuege_aus_pressed[4] = { {-0.65f, -0.12f},{-0.15f, -0.12f},{-0.15f, -0.24f},{-0.65f,-0.24f} }; // zuege aus pressed
            engine.zeichnen.polygon(zuege_aus_pressed, Textur, 4, 85);
        }
    }

    GL_koordinate Audio[4] = { {0.05f, 0.58f},{0.75f, 0.58f},{0.75f, 0.38f},{0.05f,0.38f} }; // Audio
    engine.zeichnen.polygon(Audio, Textur, 4, 86);

    GL_koordinate Musik[4] = { {0.15f, 0.32f}, { 0.65f, 0.32f }, { 0.65f, 0.2f }, { 0.15f,0.2f } }; // Musik
    engine.zeichnen.polygon(Musik, Textur, 4, 87);

    GL_koordinate Musik_slider[4] = { {0.05f, 0.105f}, { 0.75f, 0.105f  }, { 0.75f, -0.015f }, { 0.05f,-0.015f } }; // Musik Slider
    engine.zeichnen.polygon(Musik_slider, Textur, 4, 72);
    if (engine.sound.music_lvl == 0 && button_wert.x == 53) {
        GL_koordinate Musik_slider_knopf[4] = { {0.09f, 0.105f}, { 0.122f, 0.105f  }, { 0.122f, -0.015f }, { 0.09f,-0.015f } }; // Musik Slider knopf pos 1
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.music_lvl == 1 && button_wert.x == 54) {
        GL_koordinate Musik_slider_knopf[4] = { {0.244f, 0.105f}, { 0.276f, 0.105f  }, { 0.276f, -0.015f }, { 0.244f,-0.015f } }; // Musik Slider knopf pos 2
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.music_lvl == 2 && button_wert.x == 55) {
        GL_koordinate Musik_slider_knopf[4] = { {0.384f, 0.105f}, { 0.416f, 0.105f  }, { 0.416f, -0.015f }, { 0.384f,-0.015f } }; // Musik Slider knopf pos 3
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.music_lvl == 3 && button_wert.x ==  56) {
        GL_koordinate Musik_slider_knopf[4] = { {0.524f, 0.105f}, { 0.556f, 0.105f  }, { 0.556f, -0.015f }, { 0.524f,-0.015f } }; // Musik Slider knopf pos 4
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.music_lvl == 4 && button_wert.x == 57) {
        GL_koordinate Musik_slider_knopf[4] = { {0.678f, 0.105f}, { 0.71f, 0.105f  }, { 0.71f, -0.015f }, { 0.678f,-0.015f } }; // Musik Slider knopf pos 5
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 91);
    }

    if (engine.sound.music_lvl == 0) {
        GL_koordinate Musik_slider_knopf[4] = { {0.09f, 0.105f}, { 0.122f, 0.105f  }, { 0.122f, -0.015f }, { 0.09f,-0.015f } }; // Musik Slider knopf pos 1
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.music_lvl == 1) {
        GL_koordinate Musik_slider_knopf[4] = { {0.244f, 0.105f}, { 0.276f, 0.105f  }, { 0.276f, -0.015f }, { 0.244f,-0.015f } }; // Musik Slider knopf pos 2
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.music_lvl == 2) {
        GL_koordinate Musik_slider_knopf[4] = { {0.384f, 0.105f}, { 0.416f, 0.105f  }, { 0.416f, -0.015f }, { 0.384f,-0.015f } }; // Musik Slider knopf pos 3
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.music_lvl == 3) {
        GL_koordinate Musik_slider_knopf[4] = { {0.524f, 0.105f}, { 0.556f, 0.105f  }, { 0.556f, -0.015f }, { 0.524f,-0.015f } }; // Musik Slider knopf pos 4
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.music_lvl == 4) {
        GL_koordinate Musik_slider_knopf[4] = { {0.678f, 0.105f}, { 0.71f, 0.105f  }, { 0.71f, -0.015f }, { 0.678f,-0.015f } }; // Musik Slider knopf pos 5
        engine.zeichnen.polygon(Musik_slider_knopf, Textur, 4, 73);
    }
   
    

    GL_koordinate fx[4] = { {0.15f, -0.12f}, { 0.65f, -0.12f }, { 0.65f, -0.24f }, { 0.15f,-0.24f } }; // fx
    engine.zeichnen.polygon(fx, Textur, 4, 88);

    GL_koordinate fx_slider[4] = { {0.05f, -0.335f}, { 0.75f, -0.335f  }, { 0.75f, -0.455f }, { 0.05f,-0.455f } }; // fx Slider
    engine.zeichnen.polygon(fx_slider, Textur, 4, 72);
   
    if (engine.sound.fx_lvl == 0 && button_wert.x == 60) {
        GL_koordinate fx_slider_knopf[4] = { {0.09f, -0.335f}, { 0.122f,-0.335f }, { 0.122f, -0.455f }, { 0.09f,-0.455f } }; // fx Slider knopf pos 1
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.fx_lvl == 1 && button_wert.x == 61) {
        GL_koordinate fx_slider_knopf[4] = { {0.244f, -0.335f}, { 0.276f, -0.335f  }, { 0.276f, -0.455f }, { 0.244f,-0.455f } }; // fx Slider knopf pos 2
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.fx_lvl == 2 && button_wert.x == 62) {
        GL_koordinate fx_slider_knopf[4] = { {0.384f, -0.335f}, { 0.416f, -0.335f  }, { 0.416f, -0.455f}, { 0.384f,-0.455f } }; // fx Slider knopf pos 3
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.fx_lvl == 3 && button_wert.x ==  63) {
        GL_koordinate fx_slider_knopf[4] = { {0.524f, -0.335f}, { 0.556f, -0.335f  }, { 0.556f, -0.455f }, { 0.524f,-0.455f } }; // fx Slider knopf pos 4
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 91);
    }
    else if (engine.sound.fx_lvl == 4 && button_wert.x == 64) {
        GL_koordinate fx_slider_knopf[4] = { {0.678f, -0.335f}, { 0.71f,-0.335f  }, { 0.71f, -0.455f }, { 0.678f,-0.455f } }; // fx Slider knopf pos 5
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 91);
    }

    if (engine.sound.fx_lvl == 0) {
        GL_koordinate fx_slider_knopf[4] = { {0.09f, -0.335f}, { 0.122f, -0.335f }, { 0.122f, -0.455f }, { 0.09f,-0.455f } }; // fx Slider knopf pos 1
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.fx_lvl == 1) {
        GL_koordinate fx_slider_knopf[4] = { {0.244f, -0.335f}, { 0.276f,-0.335f  }, { 0.276f, -0.455f }, { 0.244f,-0.455f } }; // fx Slider knopf pos 2
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.fx_lvl == 2) {
        GL_koordinate fx_slider_knopf[4] = { {0.384f, -0.335f}, { 0.416f, -0.335f }, { 0.416f, -0.455f }, { 0.384f,-0.455f } }; // fx Slider knopf pos 3
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.fx_lvl == 3) {
        GL_koordinate fx_slider_knopf[4] = { {0.524f, -0.335f}, { 0.556f, -0.335f  }, { 0.556f, -0.455f }, { 0.524f,-0.455f} }; // fx Slider knopf pos 4
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 73);
    }
    else if (engine.sound.fx_lvl == 4) {
        GL_koordinate fx_slider_knopf[4] = { {0.678f,-0.335f}, { 0.71f, -0.335f  }, { 0.71f, -0.455f }, { 0.678f,-0.455f } }; // fx slider knopf pos 5
        engine.zeichnen.polygon(fx_slider_knopf, Textur, 4, 73);
    }
 }
  
 /*Funktion zum printen des Ingame-Interfaces*/
void Design::Interface(engine& engine) {

    koordinate button_wert = engine.cursor_hover_pos;

    if (button_wert.x == 40 ) {              
        GL_koordinate Menu_Button_pressed[4] = { {0.705f, 0.665f},{0.935f, 0.665f},{0.935f, 0.603f},{0.705f,0.603f} };      //Menu gedrückt
        engine.zeichnen.polygon(Menu_Button_pressed, Textur, 4, 16);
    }
    else {                                 
        GL_koordinate Menu_Button[4] = { {0.705f, 0.665f},{0.935f, 0.665f},{0.935f, 0.603f},{0.705f,0.603f} };      //Menu nicht gedrückt
        engine.zeichnen.polygon(Menu_Button, Textur, 4, 15);
    }
    if (button_wert.x == 41) {            
        GL_koordinate einstellung_Button_pressed[4] = { {0.705f, 0.545f},{0.935f, 0.545f},{0.935f, 0.483f},{0.705f,0.483f} };   // einstellung gedrückt
        engine.zeichnen.polygon(einstellung_Button_pressed, Textur, 4, 101);
    }
    else {                               
         GL_koordinate einstellung_Button[4] = { {0.705f, 0.545f},{0.935f, 0.545f},{0.935f, 0.483f},{0.705f,0.483f} };  //einstellung nicht gedrückt
        engine.zeichnen.polygon(einstellung_Button, Textur, 4, 13);
    }
    if (engine.sound.mute == false) {  // für Fall Musik ist an
        if(button_wert.x == 42) {      
            GL_koordinate musik_an_Button_pressed[4] = { {0.705f, 0.425f},{0.935f, 0.425f},{0.935f, 0.363f},{0.705f,0.363f} };  //musik an gedrückt
            engine.zeichnen.polygon(musik_an_Button_pressed, Textur, 4, 18);
        }else{                          
            GL_koordinate musik_an_Button[4] = { {0.705f, 0.425f},{0.935f, 0.425f},{0.935f, 0.363f},{0.705f,0.363f} };      //musik an 
            engine.zeichnen.polygon(musik_an_Button, Textur, 4, 17);
        }
    }
    else {                              //Fall Musik ist aus
        if(button_wert.x == 42) {   
            GL_koordinate musik_aus_Button_pressed[4] = { {0.705f, 0.425f},{0.935f, 0.425f},{0.935f, 0.363f},{0.705f,0.363f} };//Musik aus gedrückt
            engine.zeichnen.polygon(musik_aus_Button_pressed, Textur, 4, 20);
        }else{                       
            GL_koordinate musik_aus_Button[4] = { {0.705f, 0.425f},{0.935f, 0.425f},{0.935f, 0.363f},{0.705f,0.363f} };     //musik aus 
            engine.zeichnen.polygon(musik_aus_Button, Textur, 4, 19);
        }
    } 
    if (engine.spieler == true) {
        GL_koordinate Spieler1_am_zug[4] = { {-0.45f, -0.68f},{0.45f, -0.68f},{0.45f, -0.99f},{-0.45f,-0.99f} };    // Spieler 1 (Weiß) am Zug
        engine.zeichnen.polygon(Spieler1_am_zug, Textur, 4,  22);

    }
    else {        
        GL_koordinate Spieler2_am_zug[4] = { {-0.45f, -0.68f},{0.45f, -0.68f},{0.45f, -0.99f},{-0.45f,-0.99f} };    // Spieler 2 (Schwarz) am Zug
        engine.zeichnen.polygon(Spieler2_am_zug, Textur, 4, 21);
     
    }


    int arr[5];
    engine.zeitberechnung(arr);
    print(engine, arr);
 }

/*funktion zum printen von ziffern*/
void Design::print(engine& engine, int zahlen[]) {
    GL_koordinate tex[5][4];
    for (int x = 0; x < 5; x++) {
        if (x != 2) {
            switch (zahlen[x])
            {
            case 0:         //0
                tex[x][0] = { 0.8f,0.3f };
                tex[x][1] = { 0.98f,0.3f };
                tex[x][2] = { 0.98f,0.05f };
                tex[x][3] = { 0.8f,0.05f };
                break;
            case 1:         //1
                tex[x][0] = { 0.05f,0.95f };
                tex[x][1] = { 0.2f,0.95f };
                tex[x][2] = { 0.2f,0.72f };
                tex[x][3] = { 0.05f,0.72f };
                break;
            case 2:         //2
                tex[x][0] = { 0.28f,0.95f };
                tex[x][1] = { 0.45f,0.95f };
                tex[x][2] = { 0.45f,0.7f };
                tex[x][3] = { 0.28f,0.7f };
                break;
            case 3:         //3
                tex[x][0] = { 0.525f,0.95f };
                tex[x][1] = { 0.725f,0.95f };
                tex[x][2] = { 0.752f, 0.7f };
                tex[x][3] = { 0.525f, 0.7f };
                break;
            case 4:         //4
                tex[x][0] = { 0.04f,0.621f };
                tex[x][1] = { 0.2f,0.621f };
                tex[x][2] = { 0.2f,0.37f };
                tex[x][3] = { 0.04f,0.37f };
                break;
            case 5:         //5
                tex[x][0] = { 0.28f, 0.62f };
                tex[x][1] = { 0.45f,0.62f };
                tex[x][2] = { 0.45f,0.37f };
                tex[x][3] = { 0.28f,0.37f };
                break;
            case 6:         //6
                tex[x][0] = { 0.525f,0.625f };
                tex[x][1] = { 0.725f,0.625f };
                tex[x][2] = { 0.725f,0.375f };
                tex[x][3] = { 0.525f,0.375f };
                break;
            case 7:         //7
                tex[x][0] = { 0.05f,0.3f };
                tex[x][1] = { 0.225f,0.3f };
                tex[x][2] = { 0.225f,0.05f };
                tex[x][3] = { 0.05f,0.05f };
                break;
            case 8:         //8 
                tex[x][0] = { 0.28f,0.31f };
                tex[x][1] = { 0.425f,0.31f };
                tex[x][2] = { 0.425f,0.063f };
                tex[x][3] = { 0.28f,0.063f };
                break;
            case 9:         //9
                tex[x][0] = { 0.55f,0.31f };
                tex[x][1] = { 0.72f,0.31f };
                tex[x][2] = { 0.72f,0.05f };
                tex[x][3] = { 0.55f,0.05f };
                break;
            }
        }
    }
                                                       
    tex[2][0] = { 0.8375,0.95f };                // : Doppelpunkt
    tex[2][1] = { 0.9225f,0.95f };
    tex[2][2] = { 0.9225f,0.7f };
    tex[2][3] = { 0.8375f,0.7f };

    //Position des Timers

    GL_koordinate char_eins[4] = { {0.6995f, 0.037f},{0.7535f, 0.037f},{0.7535f, -0.015f},{0.6995f,-0.015f} };  // Mm : ss
    engine.zeichnen.polygon(char_eins, tex[0], 4, 31);

    GL_koordinate char_zwei[4] = { {0.7535f, 0.037f},{0.8075f, 0.037f},{0.8075f, -0.015f},{0.7535f,-0.015f} }; // mM : ss
    engine.zeichnen.polygon(char_zwei, tex[1], 4, 31);

    GL_koordinate char_drei[4] = { {0.8075f, 0.037f},{0.8345f, 0.037f},{0.8345f, -0.015f},{0.8075f,-0.015f} };  //mm : ss (Doppelpunkt)
    engine.zeichnen.polygon(char_drei, tex[2], 4, 31);

    GL_koordinate char_vier[4] = { {0.8345f, 0.037f},{0.8885f, 0.037f},{0.8885f, -0.015f},{0.8345f,-0.015f} }; //   mm :Ss
    engine.zeichnen.polygon(char_vier, tex[3], 4, 31);

    GL_koordinate char_fuenf[4] = { {0.8885f, 0.037f},{0.9425f, 0.037f},{0.9425f, -0.015f},{0.8885f,-0.015f} }; //  mm: sS
    engine.zeichnen.polygon(char_fuenf, tex[4], 4, 31);
  
 }
 /*Funktion zum Aufruf aller Design-Funktionen*/
void Design::InGame(engine& engine, stein_src steine_schwarz, stein_src steine_weiss) {
    Spielfeld(engine);
    Spielstein(engine, steine_schwarz, false);
    Spielstein(engine, steine_weiss, true);
    Interface(engine);
    if (engine.menue == 1) {
        Einstellung_Interface(engine);
    }
    Endscreen(engine);
}