#pragma once

#include <map>
#include <boost/shared_ptr.hpp>
#include "Units.h"
#include "SpriteState.h"

class Graphics;
class Sprite;

class PolarStar
{
public:
	PolarStar(Graphics& graphics);

	void draw(Graphics& graphics, 
		HorizontalFacing horizontal_facing,
		VerticalFacing vertical_facing,
		units::Game x, units::Game y);
private:
	struct SpriteState
	{
		SpriteState(HorizontalFacing horizontal_facing, VerticalFacing vertical_facing) :
			horizontal_facing(horizontal_facing),
			vertical_facing(vertical_facing) {}

		HorizontalFacing horizontal_facing;
		VerticalFacing vertical_facing;
	};

	friend bool operator<(const SpriteState& a, const SpriteState& b)
	{
		if (a.horizontal_facing != b.horizontal_facing)
		{
			return a.horizontal_facing < b.horizontal_facing;
		}

		return a.vertical_facing < b.vertical_facing;
	}

	void initializeSprites(Graphics& graphics);
	void initializeSprite(Graphics& graphics, const SpriteState& sprite_state);

	std::map<SpriteState, boost::shared_ptr<Sprite> > sprite_map_;
};

