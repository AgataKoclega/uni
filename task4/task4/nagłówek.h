#pragma once

#include <iostream>
#include <string>

using namespace std;

class Planet
{
private:

	const string name;
	int age;
	int available_amount_of_food;

public:

	void increase_age(int value);
	void decrease_amount_of_food(int value);
	bool increase_amount_of_food(int value);
	Planet(string n);
	~Planet() 
	{};
	int get_food() 
	{ return available_amount_of_food; }

};

class Organism
{
protected:
	Planet& home;
	bool still_alive;
public:
	virtual bool change_food()
	{ return true; };
	virtual void increase_age(int value)
	{};
	virtual void increase_size() 
	{};
	Organism(Planet &origin);
	~Organism()
	{};
	bool is_indeed_alive()
	{ return still_alive; }
};

class Animal : public Organism
{
private:
	int age;
	float weight;
public:
	Animal(Planet &origin);
	void increase_size() 
	{ weight *= 1.1; };
	void increase_age(int value);
	bool change_food();
};

class Plant : public Organism
{
private:
	int age;
	float production_coefficient;
	float height;
public:
	void increase_size() 
	{ height *= 1.23; }
	void increase_age(int value);
	Plant(Planet &origin);
	bool change_food();
};