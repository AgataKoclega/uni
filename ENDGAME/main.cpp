#include "bluebodies.h"
#include <iostream>

using namespace std;

///*1
///while there is a problem in reading to a variable
///then ask user one more time to do so
///and in case reading was successful
///clear the input stream

// The function for clearing input stream
void clear()
{
	while (getchar() != '\n');
	cin.clear();
}

int main()
{
	// We are asking the user about dimensions of simulation
	int starwayx;
	int starwayy;
	cout << "Give the real width of the system: ";
	///*1
	while(!(cin >> starwayx))
	{
		clear();
		cout << "Give the real width of the system: ";
	}
	clear();
	cout << "Give the real height of the system: ";
	///*1
	while (!(cin >> starwayy))
	{
		clear();
		cout << "Give the real height of the system: ";
	}
	//create a window for displaying our simulation
	universe godcreation(400, 400, starwayx, starwayy);
	//create container for all planets in the system
	solarsystem Nebula(godcreation);
	srand(time(0));

	//as long as user wants
	while (true)
	{
		//ask whether new planet is to be created
		char choice;
		cout << "Do you want to insert new planet (y/n): ";
		clear();
		///*1
		while (!(cin >> choice) || (toupper(choice) != 'Y' && toupper(choice) != 'N'))
		{
			clear();
			cout << "Do you want to insert new planet (y/n): ";
		}
		//if not, then break the loop, and go to a simulation
		if (toupper(choice) == 'N')
			break;
		//if yes, then ask about parameters
		double x, y, vx, vy, mass;
		cout << "Position:\n";
		cout << "x: ";
		clear();
		///*1
		while (!(cin >> x))
		{
			clear();
			cout << "x: ";
		}
		cout << "y: ";
		clear();
		///*1
		while (!(cin >> y))
		{
			clear();
			cout << "y: ";
		}
		cout << "Velocities:\n";
		cout << "vx: ";
		clear();
		///*1
		while (!(cin >> vx))
		{
			clear();
			cout << "vx: ";
		}
		cout << "vy: ";
		clear();
		///*1
		while (!(cin >> vy))
		{
			clear();
			cout << "vy: ";
		}
		cout << "Mass: ";
		clear();
		///*1
		while (!(cin >> mass))
		{
			clear();
			cout << "Mass: ";
		}
		//create a new planet with the given parameters
		Planet *transparent = new Planet(x, y, vx, vy, mass, &godcreation, 10, sf::Color(rand(), rand(), rand()));
		//add this planet to our system
		Nebula.add_planet(transparent);
	}

	/// This was part of testing if the program works correctly
	//Planet Saturn(200, 300, -100, 0, 50e15, &godcreation, 10, sf::Color(155, 213, 174));
	//Planet Jupiter(200, 200, 100, 0, 50e15, &godcreation,10, sf::Color(255,253, 134));
	//Nebula.add_planet(&Saturn);
	//Nebula.add_planet(&Jupiter);
	///

	//window at the beginning was invisible, now we want to change it
	godcreation.setVisible(true);

	//while the window is opened
	while (godcreation.isOpen())
	{
		sf::Event event;
		//wait for events
		while (godcreation.pollEvent(event))
		{
			//if window was closed, then change its state
			if (event.type == sf::Event::Closed)
				godcreation.close();
		}
		// now clear the window
		godcreation.clear(sf::Color(112,356,209));
		// and draw all the planets
		Nebula.draw_a_solarsystem();
		//actualize the solar system
		Nebula.actualize(0.001);
		//display the  final result
		godcreation.display();
	}

	system("Pause");
	return 0;
}