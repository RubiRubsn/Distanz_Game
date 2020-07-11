#include"Engine.h"
#include<irrKlang.h>

time_t engine::zeit_beginn;
koordinate engine::cursor_klick_pos;
koordinate engine::cursor_hover_pos;
bool engine::spieler;
int engine::ki_lvl;
int engine::Sound::fx_lvl;
int engine::Sound::music_lvl;
int engine::zugvorschau_lvl;
int engine::menue;
bool engine::Sound::mute;

irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();
irrklang::ISoundSource* INGAME;
irrklang::ISoundSource* INMENUE;
irrklang::ISoundSource* BUTTON_KLICK;
irrklang::ISoundSource* BUTTON_HOVER;
irrklang::ISoundSource* STEIN_KLICK;
irrklang::ISound* INGAME_PLAY;
irrklang::ISound* INMENUE_PLAY;

/*
	Groeßten teils selbst erklaerend
*/

void engine::Sound::sound_init() {
	INMENUE = SoundEngine->addSoundSourceFromFile("src/music/menue_track.mp3");
	BUTTON_KLICK = SoundEngine->addSoundSourceFromFile("src/music/Button_klick.mp3");
	STEIN_KLICK = SoundEngine->addSoundSourceFromFile("src/music/Stein_zug.wav");
	INGAME = SoundEngine->addSoundSourceFromFile("src/music/INGAME.mp3");
	BUTTON_HOVER = SoundEngine->addSoundSourceFromFile("src/music/Hover_sound.mp3");
}

void engine::Sound::music_stop(int id) {
	switch (id) {
	case 1:
		SoundEngine->stopAllSounds();
		INMENUE_PLAY->drop();
		INMENUE_PLAY = 0;
		break;
	case 2:
		SoundEngine->stopAllSounds();
		INGAME_PLAY->drop();
		INGAME_PLAY = 0;
		break;
	}
}

void engine::Sound::music_pause() {
	if (mute) {
		mute = false;
	}
	else {
		mute = true;
	}
	SoundEngine->setAllSoundsPaused(mute);
}

void engine::Sound::play_music(int id) {
	switch (id) {
	case 1:
		INMENUE_PLAY = SoundEngine->play2D(INMENUE, true, mute, true);
		sound_tick_check(true);
		break;
	case 2:
		INGAME_PLAY = SoundEngine->play2D(INGAME, true, mute, true);
		sound_tick_check(true);
		break;
	}
}

void engine::Sound::play_sfx(int id) {
	switch (id) {
	case 1:
		SoundEngine->play2D(BUTTON_KLICK);
		break;
	case 2:
		SoundEngine->play2D(STEIN_KLICK);
		break;
	case 3:
		SoundEngine->play2D(BUTTON_HOVER);
		break;

	}
}

/*funktion um Lautstaerke zu regeln, und ja, es ist bewusst keine regelmaeßige verschiebung*/
void engine::Sound::sound_tick_check(bool mus_fx) {
	if (mus_fx) {
		switch (music_lvl) {
		case 0:
			if (menue == 0 || menue == 1) {
				INGAME_PLAY->setVolume(0.0f);
			}
			else {
				INMENUE_PLAY->setVolume(0.0f);
			}
			break;
		case 1:
			if (menue == 0 || menue == 1) {
				INGAME_PLAY->setVolume(0.2f);
			}
			else {
				INMENUE_PLAY->setVolume(0.2f);
			}
			break;
		case 2:
			if (menue == 0 || menue == 1) {
				INGAME_PLAY->setVolume(0.5f);
			}
			else {
				INMENUE_PLAY->setVolume(0.5f);
			}
			break;
		case 3:
			if (menue == 0 || menue == 1) {
				INGAME_PLAY->setVolume(0.8f);
			}
			else {
				INMENUE_PLAY->setVolume(0.8f);
			}
			break;
		case 4:
			if (menue == 0 || menue == 1) {
				INGAME_PLAY->setVolume(1.0f);
			}
			else {
				INMENUE_PLAY->setVolume(1.0f);
			}
			break;
		}
	}
	else {
		switch (fx_lvl) {
		case 0:
			BUTTON_KLICK->setDefaultVolume(0.0f);
			STEIN_KLICK->setDefaultVolume(0.0f);
			BUTTON_HOVER->setDefaultVolume(0.0f);
			break;
		case 1:
			BUTTON_KLICK->setDefaultVolume(0.1f);
			STEIN_KLICK->setDefaultVolume(0.1f);
			BUTTON_HOVER->setDefaultVolume(0.05f);
			break;
		case 2:
			BUTTON_KLICK->setDefaultVolume(0.3f);
			STEIN_KLICK->setDefaultVolume(0.3f);
			BUTTON_HOVER->setDefaultVolume(0.15f);
			break;
		case 3:
			BUTTON_KLICK->setDefaultVolume(0.6f);
			STEIN_KLICK->setDefaultVolume(0.6f);
			BUTTON_HOVER->setDefaultVolume(0.3f);
			break;
		case 4:
			BUTTON_KLICK->setDefaultVolume(1.0f);
			STEIN_KLICK->setDefaultVolume(1.0f);
			BUTTON_HOVER->setDefaultVolume(0.5f);
			break;
		}
	}
}