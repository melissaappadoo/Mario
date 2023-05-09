#include "SoundEffect.h"

SoundEffect* SoundEffect::instance = 0;
SoundEffect::AudioState SoundEffect::currentState = ERROR;
std::string SoundEffect::musicFilename = "";

void SoundEffect::PlayMusic(const std::string& fileName)
{
	if (currentState != ERROR)
	{
		if (Mix_PlayingMusic() == 0)
		{
			Mix_Music* music = Mix_LoadMUS(fileName.c_str());
			Mix_PlayMusic(music, -1);
			currentState = PLAYING;
			musicFilename = fileName.c_str();
		}
		else
		{
			this->PauseMusic();
		}
	}
}

void SoundEffect::PauseMusic()
{
	if (currentState != ERROR)
	{
		if (Mix_PlayingMusic() == 1)
		{
			if (Mix_PausedMusic() == 1)
			{
				Mix_ResumeMusic();
				currentState = PLAYING;
			}
			else
			{
				Mix_PauseMusic();
				currentState = PAUSED;
			}
		}
	}
}

void SoundEffect::StopMusic()
{
	if (currentState != ERROR)
	{
		Mix_HaltMusic();
		currentState = STOPPED;
		musicFilename = "";
	}
}

void SoundEffect::PlayFX(const std::string& fileName) const
{
	if (currentState != ERROR)
	{
		Mix_Chunk* fx = Mix_LoadWAV(fileName.c_str());
		Mix_PlayChannel(-1, fx, 0);
	}
}
