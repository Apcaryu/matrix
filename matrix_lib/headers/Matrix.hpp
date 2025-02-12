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
	matrixShape shape{};
	std::vector<Vector<K>> content;

public:
	Matrix() = default;
	explicit Matrix(std::vector<Vector<K>> vecList) :
	content(vecList)
	{
		shape.m = vecList[0].getSize();
		shape.n = vecList.size();
		
	};
	Matrix(const Matrix<K> &matrixIn) { *this = matrixIn; };
	~Matrix() = default;

	Matrix<K> & operator=(Matrix<K> const &rhs) {
		shape = rhs.getShape();
		content = rhs.getMatrix();
		return *this;
	};

	void setValue(K valueIn, u_int64_t nPos, u_int64_t mPos) {
		if (nPos >= shape.n || mPos >= shape.m)
			throw std::invalid_argument("Matrix nPos or mPos out of range");
		content[nPos].setValue(valueIn, mPos);
	};
	void setLine(std::vector<K> lineIn, int nPos) {
		if (lineIn.size() != shape.m)
			throw std::invalid_argument("Matrix line size must match");
		if (nPos >= shape.n)
			throw std::invalid_argument("Matrix nPos out of range");
		content[nPos] = Vector<K>(lineIn);
	};
	void setColumn(std::vector<K> columnIn, int mPos) {
		if (columnIn.size() != shape.n)
			throw std::invalid_argument("Matrix column size must match");
		if (mPos >= shape.m)
			throw std::invalid_argument("Matrix mPos out of range");
		int n = 0;
		for (auto val : columnIn) {
			content[n++].setValue(val, mPos);
		}
	};

	[[nodiscard]] K getValue(u_int64_t nPos, u_int64_t mPos) const {
		if (nPos >= shape.n || mPos >= shape.m)
			throw std::invalid_argument("Matrix nPos or mPos out of range");
		return content[nPos].getValue(mPos);
	};
	[[nodiscard]] std::vector<K> getLine(int nPos) const {
		if (nPos >= shape.n)
			throw std::invalid_argument("Matrix nPos out of range");
		return content[nPos].getVec();
	};
	[[nodiscard]] std::vector<K> getColumn(int mPos) const {
		if (mPos >= shape.m)
			throw std::invalid_argument("Matrix mPos out of range");
		std::vector<K> result;
		for (u_int64_t i = 0; i < shape.n; i++) {
			result.push_back(content[i].getValue(mPos));
		}
		return result;
	};
	[[nodiscard]] std::vector<Vector<K>> getMatrix() const { return content; };
	[[nodiscard]] matrixShape getShape() const { return shape; };
	[[nodiscard]] bool isSquare() const {
		if(shape.n == shape.m) return true;
		return false;
	};

	bool isEqual(const Matrix<K> &rhs) const {
		const matrixShape selfShape = this->getShape();
		const matrixShape rhsShape = rhs.getShape();
		if (selfShape.n == rhsShape.n && selfShape.m == rhsShape.m) {
			for (int i=0; i<selfShape.m; i++) {
				if (!content[i].isEqual(rhs.getMatrix()[i]))
					return false;
			}
			return true;
		}
		return false;
	}

	void append(Vector<K> vecIn) {
		if (vecIn.getSize() != shape.m) {
			throw std::invalid_argument("Matrix vecIn size must match");
		}
		content.push_back(vecIn);
		shape.n++;
	};
	void append(const Matrix<K> matrixIn) {
		std::vector<Vector<K>> tmpMatrix = matrixIn.getMatrix();
		for (auto vec : tmpMatrix) {
			try {
				this->append(vec);
			} catch (...) {
				throw std::invalid_argument("Matrix append failed");
			}
		}
	};

	void printMatrix(u_int64_t precision) const {
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
	Vector() = default;
	explicit Vector(std::vector<K> arrayIn) { vec = arrayIn; };
	Vector(const Vector<K> &vectorIn) { *this = vectorIn; };
	~Vector() = default;

	Vector<K> & operator=(Vector<K> const &rhs) {
		vec = rhs.getVec();
		return *this;
	}

	void setValue(K valueIn, int nPos) {
		if (nPos >= vec.size())
			throw std::invalid_argument("Vector nPos out of range");
		vec[nPos] = valueIn;
	};

	[[nodiscard]] K getValue(int nPos) const {
		if (nPos >= vec.size())
			throw std::invalid_argument("Vector nPos out of range");
		return vec[nPos];
	};
	[[nodiscard]] std::vector<K> getVec() const { return vec; };
	[[nodiscard]] int getSize() const {	return vec.size(); };

	bool isEqual(const Vector<K> &rhs) const {
		if (this->getVec() == rhs.getVec())
			return true;
		return false;
	}

	void append(K value) {
		vec.push_back(value);
	};
	void append(const Vector<K> vecIn) {
		std::vector<K> tmpVec = vecIn.getVec();
		for(auto val : tmpVec)
			vec.push_back(val);
	};

	void showVector(const u_int64_t precision) const {
		const int default_precision{static_cast<int>(std::cout.precision())};
		std::cout << std::setprecision(static_cast<int>(precision)) << std::fixed;

		for(K val : vec) {
			std::cout << "[" << val << "]" ;//<< std::endl;
		}

		std::cout << std::setprecision(default_precision) << std::defaultfloat;
	};

	Matrix<K> vecToMatrix(const int n, const int m) {
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