#include "project.h"
#include "universe.h"

universe::universe(int width, int height, int starwayx, int starwayy) : sf::RenderWindow(sf::VideoMode(width, height), "simulation")
{
	this->setVisible(false);
	this->width = width;
	this->height = height;
	this->starwayx = starwayx;
	this->starwayy = starwayy;
}