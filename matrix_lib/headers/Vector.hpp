#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <iomanip>
#include <vector>
#include "Matrix.hpp"

class Matrix;

class Vector
{
private:
	std::vector<float> vec;

public:
	Vector();
	Vector(std::vector<float> arrayIn);
	~Vector();

	std::vector<float> getVec();
	int getSize();

	void showVector();

	Matrix vecToMatrix(int n, int m);
	Matrix vecToMatrix(Vector vec, int n, int m);
};

#endif