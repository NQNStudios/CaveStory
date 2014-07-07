#pragma once

struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;

#include <map>
#include <string>

class Graphics
{
public:
	typedef SDL_Surface* SurfaceID;

	Graphics(void);
	~Graphics(void);

	SurfaceID loadImage(const std::string& file_path, bool black_is_transparent=false);

	void blitSurface(
		SurfaceID source,
		SDL_Rect* source_rectangle,
		SDL_Rect* destination_rectangle);

	void flip();
	void clear();
private:
	typedef std::map<std::string, SDL_Surface*> SpriteMap;
	SpriteMap sprite_sheets_;

	SDL_Window* window_;
	SDL_Surface* screen_;
};

