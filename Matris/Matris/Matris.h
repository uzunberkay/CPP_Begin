#pragma once


#include<iostream>
using namespace std;

class Matrix {
	int row, col;
	int** matrix;
public:
	Matrix(int r = 5, int col = 5);
	~Matrix();
	Matrix(const Matrix& oth);
	int getRowNumber();
	int getColumnNumber();
	void setValue(int r, int c, int value);
	void randomSet();
	void identityMatrixSet();
	void display();
	Matrix addMatrix(const Matrix& othMatrix);
};

Matrix::Matrix(int r, int c)
{
	if (r > 0 && c > 0)
	{
		this->row = r;
		this->col = c;
	}
	else {
		this->row = 5;
		this->col = 5;
	}

	this->matrix = new int* [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->matrix[i] = new int[this->col];
	}
	cout << "Matrix created." << endl;
	cout << "Col: " << this->col << " Row : " << this->row << endl;

}

Matrix::~Matrix()
{
	for (size_t i = 0; i < this->row; i++)
	{
		delete[] this->matrix[i];
	}
	delete[]this->matrix;

	cout << "Matrix destroyed " << endl;
}

Matrix::Matrix(const Matrix& oth)
{
	this->row = oth.row;
	this->col = oth.col;
	this->matrix = new int* [this->row];
	for (size_t i = 0; i < row; i++)
	{
		this->matrix[i] = new int [this->col];
	}
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			this->matrix[i][j] = oth.matrix[i][j];
		}

	}
}
void Matrix::setValue(int r, int c, int value)
{
	/*if (this->col < c || this->row < r) { return; }*/
	this->matrix[r][c] = value;
}
void Matrix::display()
{
	cout << "Matrix : " << endl;
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			cout <<matrix[i][j] << " ";
		}
		cout << endl;

	}
	cout << endl;
}

void Matrix::randomSet()
{
	srand(time(NULL));

	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			this->matrix[i][j] = rand() % 100 +1;
		}
	}
}

void Matrix::identityMatrixSet()
{
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			this->matrix[i][j] = i == j ? 1 : 0;
		}

	}
}

Matrix Matrix::addMatrix(const Matrix& oth)
{
	if (this->row != oth.row || this->col != oth.col)
	{
		cout << "Row and column should be equal" << endl;
		return NULL;
	}
	Matrix result(this->row, this->col);
	for (size_t i = 0; i < result.row; i++)
	{
		for (size_t j = 0; j < result.col; j++)
		{
			result.matrix[i][j] = this->matrix[i][j] + oth.matrix[i][j];

		}

	}

	return result;

}