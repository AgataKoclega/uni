#include<iostream>

using namespace std;

char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';
int n;

void Draw()
{
	system("cls"); ///for cleaning
	cout << "Tic Tac Toe" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Input()
{
	int a;
	cout <<"it's "<<player<< " turn"<< "Press the number of the field: "; cin >> a;

	if (a == 1)
	{
		if (matrix[0][0] == '1')               // if a == 1 && (matrix[0][0] != ‘X’ && matrix[0][0] != ‘O’)
		{
			matrix[0][0] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 2)
	{
		if (matrix[0][1] == '2')
		{
			matrix[0][1] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 3)
	{
		if (matrix[0][2] == '3')
		{
			matrix[0][2] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}

	if (a == 4)
	{
		if (matrix[1][0] == '4')
		{
			matrix[1][0] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 5)
	{
		if (matrix[1][1] == '5')
		{
			matrix[1][1] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 6)
	{
		if (matrix[1][2] == '6')
		{
			matrix[1][2] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}

	if (a == 7)
	{
		if (matrix[2][0] == '7')
		{
			matrix[2][0] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 8)
	{
		if (matrix[2][1] == '8')
		{
			matrix[2][1] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
	else if (a == 9)
	{
		if (matrix[2][2] == '9')
		{
			matrix[2][2] = player;
		}
		else
		{
			cout << "it's already taken" << endl;
			Input();
		}
	}
}

/*
This is a shorter way for the input function. With division and modulo, you can get the row and the column:
void Input()
{
	int a=0;
	int row,col;

	cout << "Press the number of the field: ";
	cin >> a;

	row = (a-1) / 3;
	col = (a-1) % 3;

	matrix[row][col] = player;
*/

void TogglePlayer()
{
	if (player == 'X')
	{
		player = 'O';
	}
	else
		player = 'X';
}

char Win()
	{
	//first player
	if (matrix[0][0] == 'X'&& matrix[0][1] == 'X' && matrix[0][2] == 'X')
	{
		return 'X';
    }
	if (matrix[1][0] == 'X'&& matrix[1][1] == 'X' && matrix[1][2] == 'X')
	{
		return 'X';
	}
	if (matrix[2][0] == 'X'&& matrix[2][1] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	if (matrix[0][0] == 'X'&& matrix[1][0] == 'X' && matrix[2][0] == 'X')
	{
		return 'X';
	}
	if (matrix[0][1] == 'X'&& matrix[1][1] == 'X' && matrix[2][1] == 'X')
	{
		return 'X';
	}
	if (matrix[0][2] == 'X'&& matrix[1][2] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	if (matrix[0][0] == 'X'&& matrix[1][1] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	if (matrix[2][0] == 'X'&& matrix[1][1] == 'X' && matrix[0][2] == 'X')
	{
		return 'X';
	}

	///second player

	if (matrix[0][0] == 'O'&& matrix[0][1] == 'O' && matrix[0][2] == 'O')
	{
		return 'O';
	}
	if (matrix[1][0] == 'O'&& matrix[1][1] == 'O' && matrix[1][2] == 'O')
	{
		return 'O';
	}
	if (matrix[2][0] == 'O'&& matrix[2][1] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}

	if (matrix[0][0] == 'O'&& matrix[1][0] == 'O' && matrix[2][0] == 'O')
	{
		return 'O';
	}
	if (matrix[0][1] == 'O'&& matrix[1][1] == 'O' && matrix[2][1] == 'O')
	{
		return 'O';
	}
	if (matrix[0][2] == 'O'&& matrix[1][2] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}

	if (matrix[0][0] == 'O'&& matrix[1][1] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}

	if (matrix[2][0] == 'O'&& matrix[1][1] == 'O' && matrix[0][2] == 'O')
	{
		return 'O';
	}
	return '/';
	}

/*
char Win()
{
	char Winner = 'N';

   for(int i = 0;i < 3;i++)               // check if rows/columns are equal
   {
	   if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) Winner = matrix[i][0];
	   if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) Winner = matrix[0][i];
   }
												   // check the two diagonal win possibilities
   if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) Winner = matrix[0][0];
   if (matrix[0][2] == matrix[1][1] && matrix[2][0] == matrix[1][1]) Winner = matrix[0][2];
   return Winner;
}
*/

int main()
{
	n = 0;

	Draw();
	while (1)
	{
		n++;
		Input();
		Draw();
		if (Win() == 'X')
		{
			cout << "x wins!"<<endl;
			break;
		}
		else if (Win() == 'O')
		{
			cout << "y wins!"<<endl;
			break;
		}
		else if (Win() == '/' && n==9)
		{
			cout << "it's a draw" << endl;
			break;
		}
		TogglePlayer();
	}
	system("PAUSE");
	return 0;
}