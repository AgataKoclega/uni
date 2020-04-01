#define _CRT_SECURE_NO_WARNINGS
#include "nag³ówek.h"
#include <string.h>
#include <iostream>


using namespace std;

Patient::Patient()//2
{
	name = new char[2];
	strcpy(name, " ");
	last_name = new char[2];
	strcpy(last_name, " ");
	age = 0;
	height = 0;
	weight = 0;
}

Patient::Patient( const char*name2, const char*last_name2, short int age2,  float height2, float weight2)//3
{
	name = new char[strlen(name2) + 1];
	strcpy(name, name2);
	last_name = new char[strlen(last_name2) +1];
	strcpy(last_name, last_name2);
	age = age2;
	height = height2;
	weight = weight2;
}

Patient::Patient(Patient &person)//4
{
	name = new char[strlen(person.name) + 1];
	strcpy(name, person.name);
	last_name = new char[strlen(person.last_name) + 1];
	strcpy(last_name, person.last_name);
	age = person.age;
	height = person.height;
	weight = person.weight;
	
}

float Patient::BMI()//5
{
	if (weight > 0 && height > 0)
		return weight / height / height;
	else
	{
		cerr << "Uncompleted mission"<<endl;
		return 0;
	}
}

char *Patient::get_name()
{
	return name;
}

char *Patient::get_last_name()
{
	return last_name;
}

short int Patient::get_age()
{
	return age;
}

void Patient::set_age(short int age2)
{
	age = age2;
}

float Patient::get_height()
{
	return height;
}

void Patient::set_height(float height2)
{
	height = height2;
}

float Patient::get_weight()
{
	return weight;
}

void Patient::set_weight(float weight2)
{
	weight = weight2;
}

void Patient::display()//7
{
	cout << "Name: " << name << endl;
	cout << "Last name:" << last_name << endl;
	cout << "Age:" << age << endl;
	cout << "Height:" << height << endl;
	cout << "Weight:" << weight << endl;
	
}

Patient::~Patient()//9
{
	delete[] name;
	delete[]last_name; 
	cout<< "Object of class Patient was destroyed" << endl;
}

//ostream& operator<<(ostream& out, Patient& person)

Clinic::Clinic(  const char* name2, string adress2)//11
{
	name = new char[strlen(name2) + 1];
	strcpy(name, name2);
	adress = adress2;
	registered_patients = NULL;
}

Clinic::Clinic(Clinic &hospital)//12
{
	name = new char[strlen(hospital.name) + 1];
	strcpy(name, hospital.name);
	adress = hospital.adress;
	list_of_elements *current = hospital.registered_patients;
	registered_patients = NULL;
	list_of_elements *current2 = registered_patients;
	while(current != NULL)
	{
		if (current2 == NULL)
		{
			current2 = new list_of_elements;
			registered_patients = current2;
			current2->next = NULL;
			current2->person = current->person;
		}
		current2->next = new list_of_elements;
		current2 = current2->next;
		current2->person = current->person;
		current2->next = NULL;
		current = current->next;
	}
	current->next = NULL;
}


void Clinic::addPatient(Patient& p)//13
{
	if (registered_patients == NULL)
	{
		registered_patients = new list_of_elements;
		registered_patients->person = p;
		registered_patients->next = NULL;
	}
	else
	{
		list_of_elements *current = registered_patients;
		while (current->next != NULL)
			current = current->next;
		current->next = new list_of_elements;
		current = current->next;
		current->person = p;
		current->next = NULL;
	}
}

void Clinic::removePatient(char *name, char *last_name)
{
	list_of_elements *current = registered_patients;
	if (strcmp(current->person.get_name(), name) == 0 && strcmp(current->person.get_last_name(), last_name))
	{
		registered_patients = current->next;
		delete current;
		current = registered_patients;
	}
	while (current->next != NULL)
	{
		if (strcmp(current->next->person.get_name(), name) == 0 && strcmp(current->next->person.get_last_name(), last_name) == 0)
		{
			list_of_elements *tmp = current->next->next;
			delete current->next;
			current->next = tmp;
		}
		current = current->next;
	}
}
//14
float Clinic::checkBMI(char *name, char *last_name)
{
	list_of_elements *current = registered_patients;
	while (current != NULL)
	{
		if (strcmp(current->person.get_name(), name) == 0 && strcmp(current->person.get_last_name(), last_name) == 0)
		{
			while (current->person.BMI() == 0)
			{
				float tmp;
				cout << "give data:\n";
				cout << "weight: ";
				cin >> tmp;
				current->person.set_weight(tmp);
				cout << "height: ";
				cin >> tmp;
				current->person.set_height(tmp);
			}
			cout << "bmi: " << current->person.BMI() << endl;
			return current->person.BMI();
		}
		current = current->next;
	}
	cerr << "No such patient in this clinic";
	return -1;
}
void Clinic::choosePatient(float limit)//16
{
	list_of_elements *current = registered_patients;
	while (current != NULL)
	{
		if (current->person.BMI() > limit)
		{
			cout << "name: " << current->person.get_name() << endl;
			cout << "last name: " << current->person.get_last_name() << endl;
		}
		current = current->next;
	}
}
void Clinic::displayPatients()//17
{
	list_of_elements *current = registered_patients;
	while (current != NULL)
	{
		cout << current->person;
		current = current->next;
	}
}


Clinic::~Clinic()
{
	list_of_elements *current = registered_patients;
	list_of_elements *tmp;
	while (current != NULL)
	{
		tmp = current->next;
		delete current;
		current = tmp;
	}
	cout << "Object of class Clinic was destroyed" << endl;

}
//18