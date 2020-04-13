#include "project.h"
#include "solarsystem.h"
#include "Planet.h"
#include <iostream>
// this is the part I have the most problem with. 

solarsystem::solarsystem(universe &space) : space(space)
{

}

void solarsystem::draw_a_solarsystem()
{
	for (int i = 0; i < family.size(); i++)
		family[i]->draw_a_planet();
}

void solarsystem::actualize(double t)
{
	for (int i = 0; i < family.size(); i++)
	{
		family[i]->setax(0);
		family[i]->setay(0);
		for (int j = 0; j < family.size(); j++)

		{
			if (i == j)
				continue;
			double r = sqrt((family[i]->x - family[j]->x)*(family[i]->x - family[j]->x) + (family[i]->y - family[j]->y)*(family[i]->y - family[j]->y));
			family[i]->increaseax(G*family[j]->mass / r / r / r * (family[j]->x - family[i]->x));
			family[i]->increaseay(G*family[j]->mass / r / r / r * (family[j]->y - family[i]->y));
		}
	}
	for (int i = 0; i < family.size(); i++)
	{
		family[i]->actualize(t);
	}
}

void solarsystem::add_planet(Planet *sphere)
{
	family.push(sphere);
}