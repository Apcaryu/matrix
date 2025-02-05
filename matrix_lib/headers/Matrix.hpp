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
	Matrix(const Matrix<K> &matrixIn) { *this = matrixIn; };
	~Matrix() {};

	Matrix<K> & operator=(Matrix<K> const &rhs) {
		shape = rhs.getShape();
		content = rhs.getMatrix();
		return *this;
	};

	std::vector<Vector<K>> getMatrix() const { return content; };
	matrixShape getShape() const { return shape; };
	bool isSquare() {
		if(shape.n == shape.m) return true;
		return false;
	};

	bool isEqual(Matrix<K> &rhs) const {
		const matrixShape selfShape = this->getShape();
		const matrixShape rhsShape = rhs.getShape();
		if (selfShape.n == rhsShape.n && selfShape.m == rhsShape.m) {
			for (int i; i<selfShape.m; i++) {
				if (!content[i].isEqual(rhs.getMatrix()[i]))
					return false;
			}
			return true;
		}
		return false;
	}

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

	void printMatrix(u_int64_t precision) {
		for (auto vec : content) {
			std::cout << "[ ";
			vec.showVector(precision);
			std::cout << " ]" << std::endl;
		}
	};

	Vector<K> matrixToVector() {
		Vector<K> vectorOut;
		for (auto vec : content) {
			vectorOut.append(vec);
		}
		return vectorOut;
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

	std::vector<K> getVec() const {
		return vec;
	};
	int getSize() const {
		return vec.size();
	};

	bool isEqual(Vector<K> &rhs) const {
		if (this->getVec() == rhs.getVec())
			return true;
		return false;
	}

	void append(K value) {
		vec.push_back(value);
	};
	void append(Vector<K> vecIn) {
		std::vector<K> tmpVec = vecIn.getVec();
		for(auto val : tmpVec)
		vec.push_back(val);
	};

	void showVector(u_int64_t precision) {
		const auto default_precision{std::cout.precision()};
		std::cout << std::setprecision(precision) << std::fixed;

		for(K val : vec) {
		std::cout << "[" << val << "]" ;//<< std::endl;
		}

		std::cout << std::setprecision(default_precision) << std::defaultfloat;
	};

	Matrix<K> vecToMatrix(int n, int m) {
		std::vector<Vector<K>> vecList;

		for(int i=0; i<m; i++) {
			Vector<K> tmpVec;
			for (int j=0; j<n; j++) {
				tmpVec.append(this->getVec()[j + n*i]);
			}
			vecList.push_back(tmpVec);
		}
		return Matrix<K>(vecList);
	};
};


#endif