#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <iomanip>
#include <vector>

struct matrixShape
{
	int n;
	int m;
};

template <typename K>
class Vector;

template <typename K>
class Matrix
{
private:
	matrixShape shape;
	// Vector* content;

public:
	Matrix() {};
	// Matrix(Vector* vecList);
	~Matrix() {};

	// matrixShape getShape();
	// bool isSquare();
	// void printMatrix();

	Vector<K> matrixToVector() {
		Vector<K> vector;
		return vector;
	};
};

template <typename K>
class Vector
{
private:
	std::vector<K> vec;

public:
	Vector() {};
	Vector(std::vector<K> arrayIn) {
		vec = arrayIn;
	}
	~Vector() {};

	std::vector<K> getVec() {
		return vec;
	};
	int getSize() {
		return vec.size();
	};

	void showVector() {
		for(K val : vec) {
		std::cout << std::fixed << "[" << val << "]" << std::endl;
		}
	};

	Matrix<K> vecToMatrix(int n, int m) {
		Matrix<K> matrix;
		return matrix;
	};
	Matrix<K> vecToMatrix(Vector<K> vec, int n, int m) {
		Matrix<K> matrix;
		return matrix;
	};
};


#endif