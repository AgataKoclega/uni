#include<iostream>
#include<string>

#define TYPE_CLASS 0
#define TYPE_INT 1
#define TYPE_ENUM 2
#define TYPE_FLOAT 3
#define TYPE_DOUBLE 4


using namespace std;

typedef int TYPE;

enum Week
{
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};


class My_Exceptions
{
public:
	My_Exceptions(string msg) 
	{
		err_msg = msg; 
	}
	void Show_ErrorMsg() 
	{ 
		cerr << err_msg << endl; 
	}
	~My_Exceptions() {}
private:
	string err_msg;

};

void Kinds_of_Exceptions(TYPE type) throw (My_Exceptions, int, Week, float, double) 
{
	switch (type)
	{
	case TYPE_CLASS:
		throw My_Exceptions("Exception! Type of Class");
		break;
	case TYPE_INT:
		throw 3000;
		break;
	case TYPE_ENUM:
		throw Friday;
		break;
	case TYPE_FLOAT:
		throw 1.78f;
		break;
	case TYPE_DOUBLE:
		throw 91.34;
		break;
	default:
		break;
	}
}


int main()
{

	int type;
	cout << "Input the type(0,1,2,3,4): " << endl;
	cout << "My choice is:" << endl;
	cin >> type;

	try
	{
		Kinds_of_Exceptions(type);
	}
	catch (My_Exceptions e) 
	{  
		e.Show_ErrorMsg();   
	}
	catch (float z) 
	{
		cerr << "float" << z << endl;
	}
	catch (double dd)
	{
		cerr << "double" << dd << endl;
	}
	catch (int i)
	{
		cerr << "Exception! Type of Int -->" << i << endl;
	}
	catch (Week week) 
	{
		cerr << "Exception! Type of Enum -->" << week << endl;
	}
	




	system("PAUSE");
	return 0; 
}