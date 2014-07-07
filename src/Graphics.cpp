#include "Graphics.h"
#include <SDL.h>
#include "Game.h"
#include "Units.h"

Graphics::Graphics(void)
{
	window_ = SDL_CreateWindow("Cave Story", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		units::tileToPixel(Game::kScreenWidth), units::tileToPixel(Game::kScreenHeight), 
		SDL_WINDOW_SHOWN);

	screen_ = SDL_GetWindowSurface(window_);

	SDL_ShowCursor(SDL_DISABLE);
}


Graphics::~Graphics(void)
{
	for (SpriteMap::iterator iter = sprite_sheets_.begin();
		iter != sprite_sheets_.end();
		++iter)
	{
		SDL_FreeSurface(iter->second);
	}

	SDL_FreeSurface(screen_);
	SDL_DestroyWindow(window_);
}

Graphics::SurfaceID Graphics::loadImage(const std::string& file_path, bool black_is_transparent)
{
	if (sprite_sheets_.count(file_path) == 0)
	{
		sprite_sheets_[file_path] = SDL_LoadBMP(file_path.c_str());
		if (black_is_transparent)
		{
			const Uint32 black_color = SDL_MapRGB(sprite_sheets_[file_path]->format, 0, 0, 0);
			SDL_SetColorKey(sprite_sheets_[file_path], SDL_TRUE, black_color);
		}
	}

	return sprite_sheets_[file_path];
}

void Graphics::blitSurface(
	SurfaceID source, 
	SDL_Rect* source_rectangle, 
	SDL_Rect* destination_rectangle)
{
	SDL_BlitSurface(source, source_rectangle, screen_, destination_rectangle);
}

void Graphics::flip()
{
	SDL_UpdateWindowSurface(window_);
}

void Graphics::clear()
{
	SDL_FillRect(screen_, NULL, 0);
}