#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture2D.h"

using namespace std;

class Texture2D;

class Character
{
protected:
	bool m_moving_left;
	bool m_moving_right;
	float m_collision_radius;

private:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	FACING m_facing_direction;

public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	float GetCollisionRadius();
	Rect2D GetCollisionBox() {return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }
};

#endif // !_CHARACTER_H