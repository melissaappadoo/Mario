#pragma once
#ifndef _SOUNDEFFECT_H
#define _SOUNDEFFECT_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>

class SoundEffect
{
private:
	static SoundEffect* instance;

	enum AudioState
	{
		ERROR = 0,
		WAITING,
		PAUSED,
		STOPPED,
		PLAYING
	};
	static AudioState currentState;

	static void initAudioDevice()
	{
		if (SDL_Init(SDL_INIT_AUDIO) != -1)
		{
			if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			{
				std::cerr << "Error initialising audio device" << std::endl;
				currentState == ERROR;
			}
			else
			{
				currentState = WAITING;
			}
		}
	}

	SoundEffect();

public:
	void PlayMusic(const std::string& fileName);

};

#endif // !_SOUNDEFFECT_H