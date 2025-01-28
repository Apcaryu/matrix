#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"

class Vector;

struct matrixShape
{
	int n;
	int m;
};


class Matrix
{
private:
	matrixShape shape;
	Vector* content;

public:
	Matrix();
	Matrix(Vector* vecList);
	~Matrix();

	matrixShape getShape();
	bool isSquare();
	void printMatrix();

	Vector matrixToVector();
};

#endif