#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class Matrix 
{
public: 
	Matrix(int line_size = 1, int column_size = 1) 
	{
		_line = line_size; _column = column_size; 
		CreateMatrix(_line, _column); 
	}

	Matrix(Matrix& OtherMatrix) 
	{
		_line = OtherMatrix._line; _column = OtherMatrix._column;

		CreateMatrix(_line, _column);
		for (int i = 0;i < _line;i++)
			for (int j = 0;j < _column;j++)
				_Data[i][j] = OtherMatrix[i][j];
	};

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
			{
				if (rand()%2 == 0)
					_Data[i][j] = rand() % Eps;
				else
					_Data[i][j] = -(rand()%Eps);
			}
	}

	void ShowData ()
	{
		for (int i = 0;i < _line;i++) 
		{
			cout << setw(5);
			for (int j = 0;j < _column;j++)
				cout << _Data[i][j] << setw(5);
			cout << endl;
		}
	}

	Matrix operator+ (Matrix& OtherMatrix) 
	{
		if (this->_line != OtherMatrix._line && this->_column != OtherMatrix._column)
			throw exception("You choose matrix with different size!");
		Matrix NewMatrix(_line, _column);
		for (int i = 0;i < _line;i++)
			for (int j = 0;j < _column;j++)
				NewMatrix[i][j] = _Data[i][j] + OtherMatrix[i][j];
		return NewMatrix;
	}

	int* operator[] (int Number) { return _Data[Number]; }
	int& at (int _line, int _column) 
	{
		if (_line < this->_line && _column < this->_column )
			return _Data[_line][_column];

		throw exception("You enter wrong size!");
	}

	~Matrix() { delete[]_Data; };

protected:
	int** _Data, _line, _column;
};

class Square_Matrix : public Matrix
{
public:
	Square_Matrix(int Size) : Matrix(Size, Size) { };

	int MatrixDeterminant()
	{
		if (_line == 2)
			return _Data[0][0] * _Data[1][1] - _Data[1][0] - _Data[0][1];
		else if (_line == 3)
			return _Data[0][0] * _Data[1][1] * _Data[2][2] + _Data[0][1] * _Data[1][2] * _Data[2][0] + _Data[1][0] * _Data[0][2] * _Data[2][1] - _Data[0][2] * _Data[1][1] * _Data[2][0] - _Data[0][1] * _Data[1][0] * _Data[2][2] - _Data[0][0] * _Data[1][2] * _Data[2][1];
		else
			return 0;
	}

	int MatrixDeterminant2()
	{
		for (int i =0; i<_line; i++)
		{
		
		}
	}

};

int main()
{
	try 
	{
		
		Square_Matrix a (3);
		a.RandomMatrix(10);
		a.ShowData();

		cout << a.MatrixDeterminant();
		
	}
	catch (exception & ex) { cout << ex.what(); }
}