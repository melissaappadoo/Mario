#pragma once
#ifndef _TEXTRENDERER_H
#define _TEXTRENDERER_H

#include <SDL_ttf.h>
#include <string>

using namespace std;

class TextRenderer
{
private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	mutable SDL_Rect text_rect;
	TTF_Font* font;

public:
	TextRenderer(SDL_Renderer* renderer);
	~TextRenderer();

	void Render(int x, int y);
	bool LoadFont(const string file_path, int fontSize, const string message, SDL_Color color);
};

#endif _TEXTRENDERER_H