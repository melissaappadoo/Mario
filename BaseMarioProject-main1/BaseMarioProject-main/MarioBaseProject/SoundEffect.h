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
	static std::string musicFilename;

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
		else
		{
			std::cerr << "Error initializing SDL audio subsystem";
			currentState == ERROR;
		}
	}

	SoundEffect()
	{
	}

	SoundEffect(const SoundEffect&)
	{
	}

	~SoundEffect()
	{
		Mix_CloseAudio();
	}

	SoundEffect& operator=(const SoundEffect&)
	{
	}


public:
	static SoundEffect* getInstance()
	{
		if (instance == 0)
		{
			instance = new SoundEffect;
			SoundEffect::initAudioDevice();
		}
		return instance;
	}

	void PlayMusic(const std::string& fileName);
	void PauseMusic();
	void StopMusic();
	void PlayFX(const std::string& fileName) const;

	bool isPaused() const
	{
		return currentState == PAUSED;
	}

	bool isStopped() const
	{
		return currentState == STOPPED:
	}

	bool isPlaying() const
	{
		return currentState == PLAYING;
	}

	bool inErrorState() const
	{
		return currentState == ERROR;
	}
};

#endif // !_SOUNDEFFECT_H