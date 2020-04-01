#include<iostream>
#include<typeinfo>

using namespace std;

class Papa
{
public:
	virtual void fun() {}
};


class Daughter :public Papa
{

};

class Base
{
public:
	virtual void fun_2(){}
};

class Derived:public Base
{

};

///////////////////////////////////////////////////
class Mammal 
{
public:
	virtual void fun_M() {}
};

class Dog : public Mammal 
{
public:
	//void fun() {} it's unnecesssary
};

class Cat : public Mammal
{
public:
	//void fun() {}
};



int main()
{
	cout << "1st part: " << endl;
	Papa*father = new Daughter();//////
	Daughter*girl= dynamic_cast<Daughter*>(father);

	if (girl != NULL)
		cout << "created without any problem" << endl;
	else
		cout << "unfortunately it is not working now";

	Derived child;
	Base*parent_p = &child;
	Base&parent_r = child;

	cout << "Parent reference: " << typeid(&parent_r).name() << endl;
	cout << "Pointer parent_p: " << typeid(*parent_p).name() << endl;
	cout << "parent_r: " << typeid(parent_r).name() << endl;
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "2nd part:" << endl;
	cout << endl;
	Dog *d = new Dog;
	Mammal *mammal = dynamic_cast<Mammal*>(d);
	Dog *c = dynamic_cast<Dog*>(mammal); 
	if (c != NULL)
		cout << "It works properly " << endl; 
	else
		cout << "It does not work at all " << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << "3rd part: " << endl;
	cout << endl;
	float my_array[10];
	cout << typeid(my_array).name() << endl;



	system("PAUSE");
	return 0;
}