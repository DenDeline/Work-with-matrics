#include <iostream>

using namespace std;

class Matrix 
{
public:
	Matrix() { _line = _column = 1; CreateMatrix(_line, _column); }

	int** CreateMatrix(int line_size, int colum_size)
	{
		_Data = new int* [line_size];
		for (int i = 0; i < line_size; i++) { _Data[i] = new int[colum_size]; };

		return _Data;
	}



	~Matrix() { delete[]_Data; };

private:
	int** _Data, _line, _column;
};

int main()
{
	Matrix a;


}