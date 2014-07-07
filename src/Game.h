#pragma once

#include <boost/scoped_ptr.hpp>
#include "Units.h"

class Map;
class Player;
class FirstCaveBat;
class Graphics;

class Game
{
public:
	Game(void);
	~Game(void);

	static units::Tile kScreenWidth;
	static units::Tile kScreenHeight;
private:
	void eventLoop();
	void update(units::MS elapsed_time_ms);
	void draw(Graphics& graphics);

	boost::scoped_ptr<Player> player_;
	boost::scoped_ptr<FirstCaveBat> bat_;
	boost::scoped_ptr<Map> map_;
};