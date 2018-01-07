#include<iostream>
#include<vector>
using namespace std;

void setRowZero(std::vector<std::vector<int>> &m1, int index){
	for(int i = 0; i < m1[0].size(); i++)
		m1[index][i] = 0;
}

void setColumnZero(vector<vector<int>> &m2, int index){
	for (int i = 0; i < m2.size(); ++i)
	{
		m2[i][index] = 0;
	}
}

void zeroMatrix(std::vector<std::vector<int>> &m)
{
	bool rowZero = false, colZero = false;

	//checking if first row has zero or not
	for(int i = 0; i < m[0].size(); i++)
	{
		if(m[0][i] == 0){
			cout << "first row zero\n";
			rowZero = true;
			break;
		}
	}
	//checking if first column has zero or not
	for(int i = 0; i < m.size(); i++){
		if(m[i][0] == 0){
			cout << "first col zero\n";
			colZero = true;
			break;
		}
	}

	//now processing the whole matrix for zero
	for (int i = 1; i < m.size(); ++i)
	{
		for(int j =1; j < m[0].size(); ++j){
			if(m[i][j] == 0){
				cout << "found zero at :"<< i << " , "<<j <<'\n';
				m[0][j] = 0;
				m[i][0] = 0;
			}
		}
	}

	//starting to set col as zero
	for(int i = 1; i < m[0].size(); ++i){
		if(m[0][i] == 0)
		{
			cout << "attempting to set zero for column :" << i <<'\n';
			setColumnZero(m, i);
		}
	}
	//starting to set rows as zero
	for (int i = 1; i < m.size(); ++i)
	{
		if (m[i][0] == 0)
		{
			cout << "attempting to set zero for row :" << i <<'\n';
			setRowZero(m, i);
		}
	}

	//now checking the initial condition of the 0th row and 0th column whether they has zero or not
	if(rowZero) {cout <<"setting first row as zero\n"; setRowZero(m,0);}
	if(colZero) {cout <<"setting first column as zero\n"; setColumnZero(m,0);}
}

int main()
{
	vector<vector<int>> matrix;
	cout << "enter dimentions(space seperated) of 2d matrix\n";
	int r, c; cin >> r >> c;
	cout << "enter a 2d matrix(and I will see if zero is present, and set its row and col to zero)\n";
	for (int i = 0; i < r; ++i)
	{
		vector<int> row;
		for (int j = 0; j < c; ++j)
		{
			int x;
			cin >> x;
			row.push_back(x);
		}
		matrix.push_back(row);
	}

	cout << "***********input over********\n";
	zeroMatrix(matrix);
	cout << "***********output********\n";
	for (int i = 0; i < matrix.size(); ++i)
	{
		for(int j = 0; j < matrix[0].size(); ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << '\n';
	}

	return 0;
}