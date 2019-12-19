#include <iostream>
#include <time.h>


using namespace std;

class Matrix 
{
public: 
	Matrix(int line_size = 1, int column_size = 1) 
	{
		_line = line_size; _column = column_size; 
		CreateMatrix(_line, _column); 
	}

	int** CreateMatrix(int line_size, int colum_size)
	{
		_Data = new int* [line_size];
		for (int i = 0; i < line_size; i++) 
		{
			_Data[i] = new int[colum_size];
			for (int j = 0;j < colum_size;j++)
				_Data[i][j] = 0;
		};

		return _Data;
	}

	void RandomMatrix(int Eps) 
	{
		srand((int)time(0));

		for (int i = 0; i < _line; i++)
			for (int j = 0;j < _column;j++)
				_Data[i][j] = rand() % Eps;
	}

	int* operator[] (int Number) { return _Data[Number]; }
	int& at (int _line, int _column) 
	{
		if (_line < this->_line && _column < this->_column )
			return _Data[_line][_column];

		throw exception("You enter wrong size!");
	}

	~Matrix() { delete[]_Data; };

private:
	int** _Data, _line, _column;
};



int main()
{
	try 
	{
		Matrix a(5, 5);

		a.RandomMatrix(100);

		cout << a[0][0];

		return 0;
	}
	catch (exception & ex) { cout << ex.what(); }
}