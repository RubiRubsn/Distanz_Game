# Distanz - Game

Distanz Game ist im Rahmen des Infoprojekts im 2. Semesters der EAH JENA im Studiengang Elektrotechnik und Informationstechnik bzw. Automatisierungstechnik und Informationstechnik international der Studenten Ruben Saitz, Markus Alter, Erik Leidenfrost und Frederike Otto enstandenes Spiel
    
![Alt text](https://i.ibb.co/Q6MQdnj/Distanz-Game-14-07-2020-11-26-22.png)
mehr Bilder unten!

# Installation

 - in [Releases](https://github.com/RubiRubsn/Distanz_Game/releases) herunterladen und entpacken.
 - in dem Ordner die Distanz-Game.exe starten
 - eine Meldung vom Defender öffnet sich, dass das Programm von einem unbekannten Entwickler ist ( ist ja klar)
 - auf Infos einblenden *klicken* und dann auf trotzdem ausführen *klicken*
 - LOS GEHTS :D

# Tutorial!
- Es wird auf einem 8x8 Schachbrett gespielt
- weiß beginnt
- immer 1 gegen 1, entweder PVP (Player vs Player) oder gegen die KI
- Jeder Spieler hat 4 Spielsteine: 1 König, 3 Bauern
- Es wird abwechselnd gezogen und es herrscht Zugzwang
- Jeder Spieler kann mit allen 4 Steinen ziehen
- **Steine können sich äquivalent zu den Abständen der anderen Steine bewegen**
- zieht man auf ein Feld der eigenen Figur wird der Platz der beiden Figuren getauscht
- Steine können gegnerische Steine fangen, wenn sie genau auf das Feld ziehen, wo der Stein sich befindet
- der gegnerische Stein wird dabei gefangen genommen (kann nicht mehr gezogen werden und zählt bei der Abstandsberechnung nicht mehr mit) und tauscht mit dem schlagenden Stein den Platz
- gefangene Steine können befreit werden, wenn der eigene König auf das Feld zieht, wo der gefangene Stein sich befindet (es wird wieder Platz getauscht und der Stein ist wieder voll einsetzbar)
- Spielziel ist den König des Gegners zu fangen oder 2 Bauern, da mit nur 2 Steinen kein Abstand zwischen den anderen Steinen existiert, wenn einer ausgewählt wird

# Bekannte Bugs und Fixes!

 - wenn deine Ki lange zum ziehen braucht, versuche folgende Fixes:
    - versuche das Spiel über einem anderen Fenster zu öffnen
    - wenn du mehrere Monitore hast, versuche das Spiel auf dem anderen zu starten

# Infos zum Code!

 - main -> Distanz_game.cpp
 - Programmiert in Visual Studio
 
### Genutze Libs
> 		glew-2.1.0
>		irrKlang-1.6.0
>   	SDL2-devel-2.0.12-VC
>		Simple OpenGL Image Library

* Info zu IrrKlang - Achtung, IrrKlang muss als Objekt in den Linker eingefügt werden

### Beinhaltete Dokumente

* [src](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/tree/master/Distanz%20game%20v2%20github/src) - Speicherort für alle Texturen, Musik und Spieledatein
* [Design.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Design.h) - Definition der Design Klasse
    * [Design.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Design.cpp) - Klasse mit Funktionen zum managen der Darstellung von Texturen in verschieden Spielmenüs und Stadien
* [engine.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Engine.h) - Definition der Engine Klasse
    * [Engine.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Engine.cpp) - Funktionen zum allgemeinen steuern des Programms
    * [Sound_engine.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Sound_engine.cpp) - Funktionen zur Steuerung des Sounds
    * [textur_res.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/textur_res.cpp) - Funktionen zum einbinden und steuern von Texturen
* [spielstein_handle.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/spielstein_handle.h) - Definition der Spielstein_handle Klasse
    * [spielstein_handle.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/spielstein_handle.cpp) - Funktionen zur Steuerung von Spielfunktionen
* [Hauptmenue.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Hauptmenue.h) - Definition der Hauptmenü Klasse
    * [Hauptmenue.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Hauptmenue.cpp) - Funktionen für das Hauptmenü
* [ki_src.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/Ki_src.h) - Definition der Ki Klasse
    * [ki_src.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/KI_src.cpp) - Funktionen zur Steuerung der KI
* [save.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/save.h) - Definitionen der Klasse save
    * [save.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/save.cpp) - Klasse mit Funktionen zur Speicherung der vom Spieler gewählten Einstellungen
* [struct_src.h](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/struct_src.h) – alle Datentypen werden hier deklariert
    * [struct_src.cpp](https://github.com/RubiRubsn/Distanz_Game_OpenGL_EAH_Jena/blob/master/Distanz%20game%20v2%20github/struct_src.cpp) - Operator overloading

### Entwicklung

- Dieses Projekt ist für jeden kostenlos verwendbar und veränderbar. Macht damit was ihr wollt und habt Spaß :D

### Aufteilung
- Markus Alter: Design, Hauptmenü, Spielstein_handle
- Erik Leidenfrost: textur_res, Spielstein_handle, struct_src
- Frederike Otto: Save, Spielstein_handle, textur_res, Testfälle
- Ruben Saitz:  Engine, KI , Sound, Main
- in gemeinsamer Arbeit enstanden: Klassendiagramm, Präsentation , Texturen, PAP

# Todos!

### engine:
- ~~Maus Inputs~~
- ~~Texturen Handelin~~
- ~~Auflösung~~
- ~~Auflösungs handlin~~
- ~~sound effekte~~
- ~~sound Outputs~~
- ~~Frame Buffering~~

### Design:
- ~~Windows icon~~
- ~~Exit Button~~
- ~~Credits~~
- ~~Lade bildschirm~~
- ~~hover über spielsteine~~
- ~~neustart und hauptmenü button im endscreen~~
- ~~einstellungen Textur~~
- ~~Hintergrund Menü~~
- ~~Interface~~
- ~~spielfeld~~


### Spiel-Handling:
- ~~spielregeln~~
- ~~timer beenden bei game ende~~
- ~~schwierigkeitsgrade der Ki~~
- ~~ki belohnungs lvl verjüngung~~
- ~~ki laufzeitoptimierung durch zug berechnung verkürzen~~
- ~~Ki~~
- ~~einstellung zugvorschau aus/eigene/alle~~
- ~~timer in Einstellungen pausieren~~


### Bugs:
- ~~aufhängen in einstellung wärend ki einen zug tätigt~~
- ~~Klick sound fix~~
- ~~schatten beim Nochmalbutton~~
- ~~Hover sound~~
- ~~flackern~~
- ~~figuren nur mit legalen zügen anklicken~~
- ~~bei musik an/aus klick lautstärke wird nicht gespeichert~~
- ~~Ki lvl Belohnungen~~
- ~~programm nicht immer beendbar~~
- ~~Züge fehlen~~
- ~~ki gefangene steine berechnungs bug~~
- ~~zugvorschau von gefangenen~~
- ~~klick ins nichts absturz~~

### Endanpassung:
- ~~Musik und SFX Default auf lvl 2~~
- ~~Ki Feinschliff. Bei Zugerzeugung Abhängigkeit von Aktivität des Königs erzeugen -> der König wird nicht mehr so greedy~~

# Mehr Bilder!

![](https://i.ibb.co/6RZRqZC/Distanz-Game-14-07-2020-11-26-50.png)
![](https://i.ibb.co/GvZJPds/Distanz-Game-14-07-2020-11-57-31.png)
![](https://i.ibb.co/YDtfYbf/Distanz-Game-14-07-2020-11-26-56.png)
![](https://i.ibb.co/yRmJqxp/Distanz-Game-14-07-2020-11-28-40.png)


### Lizenz!

**Free Software, Hell Yeah!**