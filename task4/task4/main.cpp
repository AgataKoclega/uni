#include "nag³ówek.h"
#include <time.h>
#include <iostream>

int main()
{
	srand(time(0));

	Planet earth("Catland");

	Animal cat(earth);
	Animal tiger (earth);
	Animal lion(earth);
	Animal jaguar(earth);
	Animal panther(earth);

	Plant grass(earth);
	Plant catmint(earth);
	Plant valerian(earth);

	Organism *array[8] = { &cat, &tiger, &lion, &jaguar, &panther, &grass, &catmint, &valerian };

	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			array[i]->change_food();
			array[i]->increase_age(1);
			array[i]->increase_size();
		}
		earth.increase_age(1);
		int count = 0;
		for (int i = 0; i < 5; i++)
			if (array[i]->is_indeed_alive())
				count++;
		if (count == 0)
			 break;
		else
			cout << "There is/are " << count << " animal/s left\n";
	}
	system("pause");
	return 0;
}