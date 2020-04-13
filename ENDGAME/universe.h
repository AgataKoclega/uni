#pragma once

#include "project.h"
#include <SFML/Graphics.hpp>

// The class universe inherits from window and menages dimensions of our simulation
class universe : public sf::RenderWindow
{
public:
	int width, height;
	double starwayx, starwayy;
	universe(int width, int height, int starwayx, int starwayy);
};