#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include <vector>

#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"
#include "CharacterKoopa.h"
#include "TextRenderer.h"

class Texture2D;
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	Character* mario;
	CharacterKoopa* koopa;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	vector<CharacterKoopa*> m_enemies;
	TextRenderer* m_text;
	const std::string message;
	int score;
	int old_score;

	bool SetUpLevel();
	void SetLevelMap();
	void DoScreenShake();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePOWBlock();
};

#endif // _GAMESCREENLEVEL1_H