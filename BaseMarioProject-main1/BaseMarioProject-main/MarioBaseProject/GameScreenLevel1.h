#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"

class Texture2D;
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	Character* mario;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;

	bool SetUpLevel();
	void SetLevelMap();

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePOWBlock();
};

#endif // _GAMESCREENLEVEL1_H