#include<iostream>
#include<vector>

using namespace std;

int main()
{
	unsigned int row;
	unsigned int column;

	cout << "number of rows: " << endl;

	cin >> row;

	cout << "number of columns: " << endl;

	cin >> column;

	vector<int> max;

	vector<vector<int>> matrix(row);

	for (size_t i = 0; i < row; ++i)
	{
		matrix[i].resize(column);
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			cout << "fulfill your matrix : " << endl;
			cin >> matrix[i][j];
		}
	}


	int maximum;

	for (size_t i = 0; i < row; i++)
	{
		maximum = matrix[i][0];
		for (size_t j = 0; j < column; j++)
		{
			if (maximum < matrix[i][j])
			{
				maximum = matrix[i][j];
			}
		}
		max.push_back(maximum);
	}

	for (size_t i = 0; i < max.size(); i++)
	{
		cout << max[i] << " ";
	}





	system("PAUSE");
	return 0;
}
