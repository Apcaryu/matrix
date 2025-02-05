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
	std::vector<Vector<K>> content;

public:
	Matrix() {};
	Matrix(std::vector<Vector<K>> vecList) :
	content(vecList)
	{
		shape.n = vecList[0].getSize();
		shape.m = vecList.size();
		
	};
	~Matrix() {};

	std::vector<Vector<K>> getMatrix() { return content; };
	matrixShape getShape() { return shape; };
	bool isSquare() {
		if(shape.n == shape.m) return true;
		return false;
	};

	bool append(Vector<K> vecIn) {
		if (vecIn.getSize() == shape.n) {
			content.push_back(vecIn);
			shape.m++;
			return true;
		}
		return false;
	};
	bool append(Matrix<K> matrixIn) {
		std::vector<Vector<K>> tmpMatrix = matrixIn.getMatrix();
		for (auto vec : tmpMatrix) {
			if (this->append(vec)) {
				shape.m++;
			} else {
				return false;
			}
		}
		return true;
	};

	void printMatrix(u_int64_t precision, u_int16_t width) {
		for (auto vec : content) {
			std::cout << "[ ";
			vec.showVector(precision, width);
			std::cout << " ]" << std::endl;
		}
	};

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

	void append(K value) {
		vec.push_back(value);
	};
	void append(Vector<K> vecIn) {
		std::vector<K> tmpVec = vecIn.getVec();
		for(auto val : tmpVec)
		vec.push_back(val);
	};

	void showVector(u_int64_t precision, u_int16_t width) {
		const auto default_precision{std::cout.precision()};
		std::cout << std::setprecision(precision) << std::fixed;

		for(K val : vec) {
		std::cout << "[" << val << "]" ;//<< std::endl;
		}

		std::cout << std::setprecision(default_precision) << std::defaultfloat;
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