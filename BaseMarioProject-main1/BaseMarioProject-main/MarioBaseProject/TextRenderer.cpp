#include "TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

TextRenderer::~TextRenderer()
{
	m_renderer = nullptr;
}

void TextRenderer::Render(int x, int y)
{
	text_rect.x = x;
	text_rect.y = y;

	SDL_RenderCopy(m_renderer, m_texture, nullptr, &text_rect);
}

bool TextRenderer::LoadFont(const string file_path, int fontSize, const string c_string, SDL_Color color)
{
	font = TTF_OpenFont(file_path.c_str(), fontSize);
	if (font == nullptr)
	{
		cout << "Unable to create font. Error: " << TTF_GetError();
	}

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, c_string.c_str(), {0, 0, 0, 255});
	if (text_surface == nullptr)
	{
		cout << "Unable to create text surface. Error: " << TTF_GetError();
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
	if (m_texture == nullptr)
	{
		cout << "Unable to create texture. Error: " << TTF_GetError();
	}

	TTF_CloseFont(font);
	
	SDL_FreeSurface(text_surface);
	SDL_QueryTexture(m_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);

	return m_texture;
}
