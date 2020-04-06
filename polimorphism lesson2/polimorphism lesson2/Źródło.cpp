#include<iostream>

using namespace std;

class Mammal
{
public:
 void virtual giveVoice()=0;
 void virtual eat()=0;
 void virtual drink()=0;
 virtual ~Mammal()
 {
	 cout << "Mammal is deleted" << endl;
 }

};

class Dog :public Mammal
{
public:
	void virtual giveVoice()
	{
		cout << "Woof Woof!" << endl;
	}
	void virtual eat()
	{
		cout << "Dog is eating" << endl;
	}
	void virtual drink()
	{
		cout << "Dog is drinking" << endl;
	}

	~Dog()
	{
		cout << "DOg is deleted" << endl;
	}
};

class Cat : public Mammal
{
	void virtual giveVoice()
	{
		cout << "Meow Meow!" << endl;
	}
	void virtual eat()
	{
		cout << "Cat is eating" << endl;
	}
	void virtual drink()
	{
		cout << "Cat is drinking" << endl;
	}
public:
	~Cat()
	{
		cout << "Cat is deleted" << endl;
	}

};

class Monkey :public Mammal
{
	void virtual giveVoice()
	{
		cout << "Kiri Kiri!" << endl;
	}
	void virtual eat()
	{
		cout << "Monkey is eating" << endl;
	}
	void virtual drink()
	{
		cout << "Monkey is drinking" << endl;
	}

public:
	~Monkey() 
	{
		cout << "Monkey is deleted" << endl;
	}
};

void real_data(Mammal*ptr)
{
	ptr->giveVoice();
	ptr->eat();
	ptr->drink();
}

int main()
{

	Dog Georgin;
	Cat Priscilla;

	Mammal*Priscilla_ptr = &Priscilla;
	Mammal*monkeyLera_ptr = new Monkey;


	Georgin.drink();
	Georgin.eat();
	Georgin.giveVoice();

	real_data(Priscilla_ptr);
	real_data(monkeyLera_ptr);
	delete monkeyLera_ptr;





	system("PAUSE");
	return 0;
}
