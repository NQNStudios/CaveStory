#pragma once

#include "Units.h"
#include "Timer.h"

class Graphics;

class DamageText
{
public:
	DamageText();

	void setDamage(units::HP damage);

	void update(units::MS elapsed_time);
	void draw(Graphics& graphics, units::Game center_x, units::Game center_y);
private:
	units::HP damage_;
	units::Game offset_y_;
	Timer timer_;
};

