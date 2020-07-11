#pragma once
#include"struct_src.h";
#include"spielstein_handle.h"
/*
	Die Ki ist komplex und wird deshalb hier nochmal theoretisch erlaeutert.
	
	Die Ki ist eine rekursive Funktion, die alle moeglichen Zuege berechnet, jeder Zug wird daraufhin virtuell ausgeführt und alle weiteren moeglichen Zuege werden berechnet. Das kann theoretisch unbegrenzt geschehen. 
	Wenn in einem potentiellen Zug ein Koenig geschlagen werden kann oder ein zweiter Bauer gefangen werden kann, werden alle folgenden Zuege ungültig gemacht, um Rechenzeit einzusparen. 
	Jeder Zug bekommt ein Belohnungslevel, welches natürlich unterschiedlich ist. Einen König zu schlagen oder den zweiten Bauern gefangen zu nehmen, gibt eine hohe Belohnung. Den ersten Bauern zu schlagen eine mittlere Belohnung,
	einen Bauern zu befreien auch eine mittlere. da, die ki auch gerne mit sich selbst tauschte um nicht wirklich zu ziehen gibt es eine kleine bestrafung fuer einen eigentausch von Bauer mit Bauer. Koenig-Bauer ist unbestraft.
	Es gibt auch eine Verjüngung der Werte, damit ein Sieg in zwei Zuegen nicht so wertvoll ist, wie ein Sieg in einem Zug.
	Die Ki geht dabei folgendermaßen vor:
	Es gibt verschiedene Hoehen in der sich die KI befindet, die Anzahl dieser bestimmt das Niveau der KI.
	Bei Hoehe eins berechnet die KI nur ihren eigenen naechsten Zug vorraus.
	Bei Hoehe zwei berechnet die KI ihren naechsten Zug und den moeglichen Zug des Spielers.
	Auf hoehe drei berechnet die KI ihren eigenen, den Zug des Spielers und den darauffolgenden Zug von sich und dem Speieler.

	KI auf leicht ist bis hoehe 1
	KI auf schwer ist bis hoehe 3
	Die KI koennte rein theoretisch noch hoeher rechnen, dann muesste man einen Weg finden, um uninterresannte Zuege zu ignorieren damit Rechenleistung gespart wird, da sich die Laufzeit expotentiell verlaengert.
	wir empfinden die rechenzeit fuer hoehe 3 akzeptabel, sowie auch die ki leistung auf dieser hoehe.

	Die Belohnungslevel werden fuer beide Spieler gesondert gespeichert und wenn Hoehe != 1 ist, wird aus allen Werten der Durchschnitt gebildet. Um die Attraktivität des Ausgangszuges zu repraesentieren.
	auf hoehe zwei werden die belohnungslvl halbiert um wie oben beschrieben hintere zuege unatraktiever zu machen.
	Am Ende der Berechnung wird die Hoehe wieder auf 1 gesetzt, das Belohnungslevel des Spielers negiert und zu der der KI addiert, um ein Gesamtlevel zu bekommen. Wenn also z.b. die KI im naechsten Zug schlagbar ist, wird das
	Belohnungslevel dadurch sehr stark verringert, wenn am Ende mehrere Zuege mit dem selben Belohnungslevel bestimmt werden, wird zufaellig ein Zug aus diesen gewaehlt.
*/


class ki {
private: 
	/*Definition belohnungs lvl*/
	static int ganz_leicht;
	static int leicht;
	static int stark;
	static int end;
	static float belohnungs_verringerung;

	koordinate error = { 100,100 };
	/*um die moeglichen zuege der ki zu sehen(also des hoechsten lvls) und den im endeffekt gewaehlten auf true setzen*/
	bool ki_dev = true;
	//berechnung der anzahl aktiver bauern
	int anzahl_bauern(stein_src stein);
	//belohnungs vergabe
	void belohnung(stein_src spielstein, stein_src spielstein_gegner, koordinate neu, int belohnungs_lvl[], bool spieler);
	//Belohnungslvl speicherung für jeden zug, jedes steins und jedes spielers.
	int belohnungs_lvl_entscheidung[4][24][2];
	spielstein_handle handler;
protected:

public:
	ki();
	~ki();
	//ki belohnungs werte veraendern hauptsaechlich fuer die ki optimierung gedacht
	void werte_change(int g_l, int l, int s, int e, float b);
	koordinate neue_pos;
	//Hauptfunktion
	void ki_iter(engine& engine, int hoehe, ki_daten daten, int belohnungs_lvl[], koordinate& neue_pos_ki, int& stein);
};
