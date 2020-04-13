#pragma once
#include "project.h"
#include "universe.h"
// The class Planet is responsible for handling one planet
class Planet
{
	//The solarsystem has access to all private members of class Planet
	friend class solarsystem;
private:
	//These are the coordinates and variables that we will use to create a planet 
	double x, y;
	double vx, vy;
	double ax, ay;
	int radious;
	sf::Color color;
	double mass;
	universe *space;
public:
	//constructor commonly used
	Planet(double x, double y, double vx, double vy, double mass, universe *space, int radious = 50, sf::Color color = sf::Color::Red);
	// deconstructor is needed for creating an array of planets
	Planet() {};
	void setax(double a);
	void setay(double a);
	void increaseay(double a);
	void increaseax(double a);
	// method actualize(double time) will be used for changing velocities and position of a planet
	void actualize(double time);
	void draw_a_planet();
};