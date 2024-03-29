#pragma once
#ifndef _CHARACTERKOOPA_H
#define _CHARACTERKOOPA_H

#include "Character.h"

class CharacterKoopa : public Character
{
private:
	float m_single_sprite_w;
	float m_single_sprite_h;
	bool m_injured;
	float m_injured_time;

	void FlipRightwayUp();

public:
	CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);

	void TakeDamage();
	void Jump();
	void Flip();
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	bool GetInjured() { return m_injured; }
};

#endif // _CHARACTERKOOPA_H