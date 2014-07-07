#pragma once

#include <string>
#include <SDL.h>
#include "Graphics.h"
#include "Units.h"

class Sprite
{
public:
	Sprite(Graphics& graphics,
		const std::string& file_path,
		units::Pixel source_x, units::Pixel source_y,
		units::Pixel width, units::Pixel height);

	virtual void update(units::MS elapsed_time_ms) { }
	void draw(Graphics& graphics, units::Game x, units::Game y);
private:
	SDL_Surface* sprite_sheet_;
protected:
	SDL_Rect source_rect_;
};

