#include "nag³ówek.h"

int main()
{
	Patient first_one("Adam", "Kowalski", 38, 1.80, 70);//18
	Patient second_one("Alina","Radke",24);
	Patient third_one("Juliusz", "Cezary",45,1.78, 97);
	Patient fourth_one("Rita", "Wertys", 56, 1.54, 49);
	Patient fifth_one( "Marcin", "Malber",31);
	Patient sixth_one( "Teodor","Kartyd", 48, 1.85, 89);
	Patient seventh_one("Ania", "Nowak", 19, 1.62, 52);
	Patient eight_one("Katarzyna","Eczaf", 29, 1.68, 70);
	Patient ninth_one("Wiktor", "Umecki", 33, 1.95, 104);

		
	Patient people[9] = { first_one, second_one, third_one, fourth_one, fifth_one, sixth_one, seventh_one, eight_one, ninth_one };

	Clinic medvival("Medvival", "ul. Kraszekus 89");//18

	for (int i = 0; i < 9; i++)//19
	{
		medvival.addPatient(people[i]);
	}
	medvival.displayPatients();
	medvival.choosePatient(22);

	for (int i = 0; i < 9; i++)//20
	{
		float tmp;
		tmp =  medvival.checkBMI(people[i].get_name(), people[i].get_last_name());

		if (tmp > 18.5 && tmp < 24.9)//21
		{
			medvival.removePatient(people[i].get_name(), people[i].get_last_name());
			people[i].~Patient();
		}
	}
	medvival.displayPatients();//22
	medvival.~Clinic();//23

}