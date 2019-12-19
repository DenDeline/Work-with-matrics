#include <iostream>

using namespace std;

class Matrix 
{
public:
	Matrix() { _line = _column = 1; CreateMatrix(_line, _column); }

	Matrix(int line_size): Matrix() { _line = line_size; }
	Matrix(int column_size, int line_size) : Matrix(line_size) { _column = column_size; }

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
		Matrix a(3, 3);
		a.at(3, 0) = 3;
		cout << a[0][0];

		return 0;
	}
	catch (exception & ex) { cout << ex.what(); }
}