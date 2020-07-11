#pragma once
#include"struct_src.h"

/*
	Funktion zum Speichern und laden von einstellungspunkten
*/

class save_manager {
private:
public:
	save_manager();
	~save_manager();
	void save(save_dat dat);
	save_dat load();

};