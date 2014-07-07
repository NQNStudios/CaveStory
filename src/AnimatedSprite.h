#pragma once

#include "Sprite.h"
#include <string>
#include "Graphics.h"
#include "Timer.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(
		Graphics& graphics,
		const std::string& file_path,
		units::Pixel source_x, units::Pixel source_y,
		units::Pixel width, units::Pixel height,
		units::FPS fps, units::Frame num_frames);

	void update(units::MS elapsed_time_ms);
private:
	const units::Frame num_frames_;
	units::Frame current_frame_;
	Timer frame_timer_;
};

