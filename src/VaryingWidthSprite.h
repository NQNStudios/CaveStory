#pragma once

#include "Sprite.h"

class VaryingWidthSprite : public Sprite
{
public:
	VaryingWidthSprite(Graphics& graphics, const std::string& file_path,
			units::Pixel source_x, units::Pixel source_y,
			units::Pixel initial_width, units::Pixel height) :
		Sprite(graphics, file_path, source_x, source_y, initial_width, height)
	{

	}

	void set_width(units::Pixel width) { source_rect_.w = width; }

};