#include <fstream>
#include "save.h"
#include<iostream>
using namespace std;

save_manager::save_manager() {
    //cout << "konstructed";
}

save_manager::~save_manager(){
    //cout << "destructed";
}



void save_manager::save(save_dat dat){
    //speichern in file game_save_file und ggf. neuerstellung
    ofstream outdata;
    outdata.open("src/game_save_file.dat");
    if (!outdata) {
        exit(1);
    }
    if (dat.muted) {
        outdata << 1 << endl;
    }
    else {
        outdata << 0 << endl;
    }
    outdata << dat.ki_lvl << endl;
    outdata << dat.fx_lvl << endl ;
    outdata << dat.music_lvl << endl;
    outdata << dat.zugvorschau_lvl << endl;
    outdata.close();
}

save_dat save_manager::load(){
    //einlesen von daten
    ifstream indata; 
    save_dat dat;
    indata.open("src/game_save_file.dat"); 
    if (!indata) { 
        //fals kein save file vorhanden
        dat.muted = false;
        dat.ki_lvl = 1;
        dat.fx_lvl = 2;
        dat.music_lvl = 2;
        dat.zugvorschau_lvl = 1;
    }
    else {
        int x;
        indata >> x;
        if (x == 0) {
            dat.muted = false;
        }
        else {
            dat.muted = true;
        }
        indata >> dat.ki_lvl;
        indata >> dat.fx_lvl;
        indata >> dat.music_lvl;
        indata >> dat.zugvorschau_lvl;
        indata.close();
    }
    if (dat.ki_lvl < 0 || dat.ki_lvl>1)  dat.ki_lvl = 1;
    if (dat.fx_lvl < 0 || dat.fx_lvl>4)  dat.fx_lvl = 3;
    if (dat.music_lvl < 0 || dat.music_lvl>4)  dat.music_lvl = 3;
    if (dat.zugvorschau_lvl < 0 || dat.zugvorschau_lvl>2)  dat.zugvorschau_lvl = 1;
    return dat;
}