#pragma once

#include <iostream>
#include <string>

using namespace std;

class Patient//1
{
private:
	char *name;
	char *last_name;
	short int age;
	float height;
	float weight;
	friend ostream& operator<<(ostream& out, Patient& person)//8
	{
		out << "name: " << person.name << endl;
		out << "last_name:" << person.last_name << endl;
		out << "age:" << person.age << endl;
		out << "height:" << person.height << endl;
		out << "weight:" << person.weight << endl;
		return out;
	}
public:
	Patient();//2
	Patient(const char*name2, const char*last_name2, short int age2, float height2 = 0, float weight2 = 0);//3
	Patient(Patient &person);//4

	float BMI();//5 
	char *get_name();//6
	char* get_last_name();
	short int get_age();
	void set_age(short int age2);
	float get_height();
	void set_height(float height2);
	float get_weight();
	void set_weight(float weight2);
	void display();//7

	~Patient();//9
};

struct list_of_elements
{
	Patient person;
	list_of_elements* next;
};

class Clinic//10
{
private:
	char *name;
	string adress;
	list_of_elements* registered_patients;

public:
	Clinic(const char*name2, string adress2);//11


	Clinic(Clinic &hospital);//12

	void addPatient(Patient& p);//13
	void removePatient(char *name, char *last_name);//14
	float checkBMI(char *name, char *last_name);//15 
	void choosePatient(float limit);//16
	void displayPatients();//17
	~Clinic();//18


};








