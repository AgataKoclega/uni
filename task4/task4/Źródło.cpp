#include "nag³ówek.h"
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Planet::Planet(string n) : name(n)
{
	age = 0;
	available_amount_of_food = rand() % 300 + 15;
}

void Planet::increase_age(int value)
{
	if (value > 0)
		age += value;
}
void Planet::decrease_amount_of_food(int value)
{
	if (available_amount_of_food - value > 0)
		available_amount_of_food -= value;
}

bool Planet::increase_amount_of_food(int value)
{
	if (available_amount_of_food + value > 0)
	{
		available_amount_of_food += value;
		return true;
	}
	return false;
}

Organism::Organism(Planet &origin) : home(origin)
{
	still_alive = true;
}

Animal::Animal(Planet &origin) : Organism(origin)
{
	age = rand() % 99;
	weight = (rand() % 2000) / 10.0 + 15;
}

void Animal::increase_age(int value)
{
	if (value > 0)
		age += value;
}

bool Animal::change_food()
{
	if (home.get_food() < weight * 0.1 && still_alive)
	{
		cout << "The animal died\n";
		still_alive = false;
		return false;
	}
	else
	{
		home.decrease_amount_of_food(weight * 0.1);
		return true;
	}
}

Plant::Plant(Planet &origin) : Organism(origin)
{
	age = 0;
	height = rand() % 47;
	production_coefficient = (rand() % 101) / 25.0 + 0.1;
}

bool Plant::change_food()
{
	return home.increase_amount_of_food(production_coefficient * height);
}

void Plant::increase_age(int value)
{
	if (value > 0)
		age += value;
}