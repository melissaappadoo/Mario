#include "TextRenderer.h"

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

bool TextRenderer::LoadFont(const string file_path, int fontSize, const string message, SDL_Color color)
{
	font = TTF_OpenFont(file_path.c_str(), fontSize);
	if (font == nullptr)
	{
		
	}
	return false;
}
