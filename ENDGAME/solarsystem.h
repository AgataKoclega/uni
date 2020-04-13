#pragma once
#include "project.h"
#include "vector.h"

//The class solarsystem gathers all planets and menages them
class solarsystem
{
private:
	//dynamical array of the planets
	myvector<Planet *> family;
	//reference to "space", our window on which we display
	universe &space;
public:
	solarsystem(universe &space);
	void add_planet(Planet *sphere);
	void draw_a_solarsystem();
	// to change the acceleration of all the planets we need to call  actualize 
	void actualize(double t);
};