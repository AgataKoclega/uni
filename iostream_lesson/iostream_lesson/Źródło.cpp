#include<iostream>
#include<fstream>
#include<iomanip>//manipulators
#include<sstream>
#include<string>
using namespace std;

int main()
{

	fstream file_1("try.txt",ios::out);

	string name = "gummy ";
	string surname= "bear";
	string city= "Ohrid";
	string age= "88";

	file_1 << setw(20) << setfill('.') << left << name << endl;//setfill fills the empty space
	file_1 << setw(11) << setfill('.') << right << surname << endl;
    file_1.close();
	///////////////////////////(                 ^            1-4                            )//////////////////////

	int tar=17;
	stringstream ss;
	ss << tar;

	ss >> age;

	file_1.open("try.txt", ios::out|ios::in|ios::app);
	file_1 << age << endl;
	cout << "\n " << "an integer: " << tar << "\n";
	cout << "string representing this integer: " << age << "\n";
	file_1.close();
	//file_1<<setw(20)<<setfill('.')<<left<<age<<endl;//


	//(                                               ^      5                                             )
	

	file_1.open("try.txt", ios::out | ios::in | ios::app);
	string maybe;
	int a = 0;
	while (getline (file_1,maybe))
	{
		cout << "your loop is working" << endl;
		a++;
		cout <<"Your file has "<< a <<" lines"<< endl;
	}

	cout << endl;
	cout << endl;
	file_1.close();

	///////////////(                   ^                           6                                            )


	///(                                                    7                                                  )

	
	 cout << "Give the name of the file: ";
	string file_name;
    cin >> file_name;
	fstream file_2(file_name,ios::in);//

	bool is_file_exist(const char *file_name);////checking if the file exist 
{
	ifstream file_2(file_name);//
	return file_2.good();//
}



/*
	if(!file_2.is_open())
	{
	    cout << "there is no such file here :( " <<endl;
		return 0;
	}
	while(file_2.is_open())
	{
		cout << "Your file exists!" << endl;
	
	}

	file_2.close();
	
*/


	system("PAUSE");
	return 0;
}



