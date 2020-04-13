#include "project.h"
#include "Planet.h"
#include <iostream>

Planet::Planet(double x, double y, double vx, double vy, double mass, universe *space, int radious, sf::Color color) : space(space)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->mass = mass;
	this->color = color;
	this->radious = radious;
}

void Planet::setax(double a)
{
	this->ax = a;
}

void Planet::setay(double a)
{
	this->ay = a;
}
void Planet::actualize(double time)
{
	vx += ax * time;
	vy += ay * time;
	x += vx * time;
	y += vy * time;
}

void Planet::draw_a_planet()
{
	sf::CircleShape circle(radious);
	circle.setFillColor(color);
	circle.setPosition(sf::Vector2f(x*space->width / space->starwayx - radious, y*space->height / space->starwayy - radious));
	space->draw(circle);
}

void Planet::increaseay(double a)
{
	ay += a;
}

void Planet::increaseax(double a)
{
	ax += a;
}