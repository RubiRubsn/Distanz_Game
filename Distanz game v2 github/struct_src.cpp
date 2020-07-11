#include"struct_src.h"
#include<iostream>

/*uninteressant hauptsaechlich operator overloading*/

std::ostream& operator<<(std::ostream& str, koordinate& koord) {
	return str << "x: " << koord.x << " y: " << koord.y << "\n";
}

std::ostream& operator<<(std::ostream& str, stein_src src) {
	return str << "Bauer eins: " << src.spiel_stein[0].aktiv << " position: " << src.spiel_stein[0].koord << "Bauer zwei:" << src.spiel_stein[1].aktiv << " position: " << src.spiel_stein[1].koord << "Bauer drei: " << src.spiel_stein[2].aktiv << " position: " << src.spiel_stein[2].koord << "Koenig: " << src.spiel_stein[3].aktiv << " position: " << src.spiel_stein[3].koord;
}

bool operator!=(koordinate a, koordinate b) {
	if (a.x != b.x && a.y != b.y) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(koordinate a, koordinate b) {
	if (a.x == b.x && a.y == b.y) {
		return true;
	}
	else {
		return false;
	}
}

koordinate operator+(koordinate& a, koordinate& b) {
	koordinate erg = { a.x + b.x,a.y + b.y };
	return erg;
}

koordinate operator-(koordinate& a, koordinate& b) {
	koordinate erg = { a.x - b.x,a.y - b.y };
	return erg;
}