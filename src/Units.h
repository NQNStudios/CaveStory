#pragma once

#include <boost/math/special_functions.hpp>

namespace units
{

	typedef int HP;

	typedef float Game; // Float for extra precision. Intrinsic units of position
	typedef int Pixel; // Integer for discrete units. Pixel values can be +/-.
	typedef unsigned int Tile; // Also discrete, but non-negative.
	typedef unsigned int Frame; // Discrete, non-negative.
	typedef float Degrees;

	typedef unsigned int MS; // Discrete Milliseconds. unsigned int matches SDL
	typedef unsigned int FPS; // Frames per seconds. (Mz or 1 / Second)

	typedef float Velocity; // Game / MS
	typedef float Acceleration; // Game / MS / MS
	typedef float AngularVelocity; // Degrees / MS

	namespace
	{
		const Game kTileSize = 32.0f;
		const double kPi = atan(1) * 4;
	}

	inline double degreesToRadians(Degrees degrees)
	{
		return degrees * kPi / 180.0f;
	}

	inline Pixel gameToPixel(Game game)
	{
		// TODO quit assuming 16x16
		return Pixel(boost::math::round(game / 2));
	}

	inline Tile gameToTile(Game game)
	{
		return Tile(game / kTileSize);
	}

	inline Game tileToGame(Tile tile)
	{
		return tile * kTileSize;
	}

	inline Pixel tileToPixel(Tile tile)
	{
		return gameToPixel(tileToGame(tile));
	}

	const Game kHalfTile = tileToGame(1) / 2.0f;

} //units