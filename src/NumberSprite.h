#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include "Units.h"

class Sprite;
class Graphics;

class NumberSprite
{
public:
	static NumberSprite HUDNumber(Graphics& graphics, int number, int num_digits)
	{
		return NumberSprite(graphics, number, num_digits, WHITE, NONE);
	}
	static NumberSprite DamageNumber(Graphics& graphics, int number)
	{
		return NumberSprite(graphics, number, 0, RED, MINUS);
	}
	static NumberSprite ExperienceNumber(Graphics& graphics, int number)
	{
		return NumberSprite(graphics, number, 0, WHITE, PLUS);
	}

	void draw(Graphics& graphics, units::Game x, units::Game y);
	void drawCentered(Graphics& graphics, units::Game x, units::Game y)
	{
		draw(graphics, x - width() / 2, y - height() / 2);
	}
private:
	enum ColorType
	{
		RED,
		WHITE
	};
	enum OperatorType
	{
		PLUS,
		MINUS,
		NONE
	};
	NumberSprite(Graphics& graphics, int number, int num_digits, ColorType color, OperatorType op);

	units::Game width() const { return units::kHalfTile * reversed_glyphs_.size(); }
	units::Game height() const { return units::kHalfTile; }

	units::Game padding_;
	std::vector<boost::shared_ptr<Sprite> > reversed_glyphs_;
};

