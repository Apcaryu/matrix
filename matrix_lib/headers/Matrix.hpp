#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <algorithm>
#include <cmath>
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
	explicit Matrix(const matrixShape matrixShape) {
		shape.m = matrixShape.m;
		for (int i = 0; i < matrixShape.n; i++) {
			Vector<K> vec = Vector<K>(matrixShape.m);
			this->append(vec);
		}
	};
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
	void setLine(Vector<K> lineIn, int nPos) { //TODO make tests for this function
		if (lineIn.size() != shape.m)
			throw std::invalid_argument("Matrix line size must match");
		if (nPos >= shape.n)
			throw std::invalid_argument("Matrix nPos out of range");
		content[nPos] = lineIn;
	}
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
	void setColumn(Vector<K> columnIn, int mPos) { //TODO make tests for this function
		if (columnIn.size() != shape.n)
			throw std::invalid_argument("Matrix column size must match");
		if (mPos >= shape.m)
			throw std::invalid_argument("Matrix mPos out of range");
		for (auto nPos = 0; nPos < columnIn.getSize(); nPos++) {
			content[nPos].setValue(columnIn.getValue(nPos), mPos);
		}
	}

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
	[[nodiscard]] Vector<K> getLine(int nPos) {//TODO make tests for this funcion
		if (nPos >= shape.n)
			throw std::invalid_argument("Matrix nPos out of range");
		return content[nPos];
	}
	[[nodiscard]] std::vector<K> getColumn(int mPos) const {
		if (mPos >= shape.m)
			throw std::invalid_argument("Matrix mPos out of range");
		std::vector<K> result;
		for (u_int64_t i = 0; i < shape.n; i++) {
			result.push_back(content[i].getValue(mPos));
		}
		return result;
	};
	[[nodiscard]] Vector<K> getColumn(int mPos) {//TODO make tests for this function
		if (mPos >= shape.m)
			throw std::invalid_argument("Matrix mPos out of range");
		Vector<K> result;
		// std::vector<K> result;
		for (u_int64_t i = 0; i < shape.n; i++) {
			result.append(content[i].getValue(mPos));
			// result.push_back(content[i].getValue(mPos));
		}
		return result;
	}
	[[nodiscard]] std::vector<Vector<K>> getMatrix() const { return content; };
	[[nodiscard]] matrixShape getShape() const { return shape; };
	[[nodiscard]] bool isSquare() const {
		if(shape.n == shape.m) return true;
		return false;
	};
	bool isSameSize(Matrix const &other) const {
		if (shape.n != other.shape.n || shape.m != other.shape.m) {
			return false;
		}
		return true;
	}

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

	void add(Matrix<K> matrixIn) {
		if (this->getShape().n != matrixIn.getShape().n || this->getShape().m != matrixIn.getShape().m) {
			throw std::invalid_argument("the shape of matrices must be the same");
		}

		for (int yPos = 0; yPos < this->getShape().n; yPos++) {
			Vector<K> tmp_vec(this->getLine(yPos));
			tmp_vec.add(Vector<K>(matrixIn.getLine(yPos)));
			this->setLine(tmp_vec.getVec(), yPos);
		}

	}
	void subtract(Matrix<K> matrixIn) {
		if (this->getShape().n != matrixIn.getShape().n || this->getShape().m != matrixIn.getShape().m) {
			throw std::invalid_argument("the shape of matrices must be the same");
		}

		for (int yPos = 0; yPos < this->getShape().n; yPos++) {
			Vector<K> tmp_vec(this->getLine(yPos));
			tmp_vec.subtract(Vector<K>(matrixIn.getLine(yPos)));
			this->setLine(tmp_vec.getVec(), yPos);
		}

	}
	void scale(K const scl) {
		for (int yPos = 0; yPos < this->getShape().n; yPos++) {
			Vector<K> tmp_vec(this->getLine(yPos));
			tmp_vec.scale(scl);
			this->setLine(tmp_vec.getVec(), yPos);
		}
	}

	Vector<K> mul_vec(Vector<K> vecIn) const {
		if (vecIn.getSize() != this->getShape().m) {
			throw std::invalid_argument("Matrix mul_vec size must match");
		}
		Vector<K> result(vecIn.getSize());
		for (int yPos = 0; yPos < vecIn.getSize(); yPos++) {
			Vector<K> tmp_vec(this->getColumn(yPos));
			tmp_vec.scale(vecIn.getValue(yPos));
			result.add(tmp_vec);
		}
		return result;
	}
	Matrix mul_mat(Matrix matrixIn) const{
		if (!this->isSameSize(matrixIn)) {
			throw std::invalid_argument("Matrix mul_mat does not support same size");
		}
		Matrix result(matrixIn.getShape());
		// std::cout << result.getShape().n << ", " << result.getShape().m << std::endl;
		for (int yPos = 0; yPos < matrixIn.getShape().m; yPos++) {
			Vector<K> tmp_vec(this->mul_vec(matrixIn.getColumn(yPos)));
			result.setLine(tmp_vec.getVec(), yPos);
		}
		return result;
	}

	K trace() const {
		if (this->getShape().n != this->getShape().m) {
			throw std::invalid_argument("Matrix must be a square");
		}

		K res;
		return res;
	}
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
	explicit Vector(int const sizeIn) {
		for (int i = 0; i < sizeIn; i++) {
			this->append(0);
		}
	}
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

	void add(const Vector<K> vecIn) {
		if (vecIn.getSize() != this->getSize())
			throw std::invalid_argument("Vector size must match");
		for (int i=0; i<vec.size(); i++) {
			vec[i] += vecIn.getVec()[i];
		}
	}
	void subtract(Vector<K> vecIn) {
		if (vecIn.getSize() != this->getSize())
			throw std::invalid_argument("Vector size must match");
		for (int i=0; i<vec.size(); i++) {
			vec[i] -= vecIn.getVec()[i];
		}
	}
	void scale(K const scl) {
		for (int i=0; i<vec.size(); i++) {
			vec[i] *= scl;
		}
	}

	static Vector<K> linear_combination(const std::vector<Vector<K>>& u, const std::vector<K>& coefs) {
		if (u.empty() || coefs.empty() || u.size() != coefs.size()) { throw std::invalid_argument("invalid arguments"); }
		int size_of_vectors = u[0].getSize();
		for (auto vec: u) {
			if (vec.getSize() != size_of_vectors) { throw std::invalid_argument("size of vector must be the same"); }
		}

		Vector<K> vector_out;
		for (int idx = 0; idx < size_of_vectors; idx++) {
			K tmp_res = 0;
			for (int jdx = 0; jdx < coefs.size(); jdx++) {
				tmp_res += u[jdx].getValue(idx) * coefs[jdx];
			}
			vector_out.append(tmp_res);
		}
		return vector_out;
	}

	K dot(Vector<K> vecIn) const {
		//(v.x*u.x) + (v.y*u.y)
		if (vecIn.getSize() != this->getSize()) {
			throw std::invalid_argument("Vector size must match");
		}
		if (vecIn.getSize() <= 0) {
			throw std::invalid_argument("Vector size must be at least 1");
		}

		K result = vecIn.getValue(0) * this->getValue(0);
		for (int idx = 1; idx < vecIn.getSize(); idx++) {
			result += vecIn.getValue(idx) * this->getValue(idx);
		}
		return result;
	}

	float norm_1() const {
		if (this->getSize() <= 0) {
			throw std::invalid_argument("Vector size must be at least 1");
		}
		float result = 0;
		for (int idx = 0; idx < this->getSize(); idx++) {
			result += std::abs(this->getValue(idx));
		}
		return result;
	}
	float norm() const {
		if (this->getSize() <= 0) {
			throw std::invalid_argument("Vector size must be at least 1");
		}
		float result = 0;
		for (int idx = 0; idx < this->getSize(); idx++) {
			result += pow(this->getValue(idx), 2);
		}
		return std::sqrt(result);
	}
	float norm_inf() const {
		if (this->getSize() <= 0) {
			throw std::invalid_argument("Vector size must be at least 1");
		}
		float result = 0;
		for (auto val: this->getVec()) {
			K tmp = std::abs(val);
			if (result < tmp) {
				result = tmp;
			}
		}
		return result;
	}
};

template <typename K>
K lerp(K u, K v, float t) {
	return 	((v - u) * t) + u;
}

template <typename K>
Vector<K> lerp(Vector<K> u, Vector<K> v, float t) {
	const u_int32_t vector_size = u.getSize();
	Vector<K> res;
	for (u_int32_t idx = 0; idx < vector_size; idx++) {
		res.append(lerp(u.getValue(idx), v.getValue(idx), t));
	}
	return res;
};

template <typename K>
Matrix<K> lerp(Matrix<K> u, Matrix<K> v, float t) {
	const int n_size = u.getShape().n;
	Matrix<K> res = Matrix<K>(std::vector<Vector<K>>{
		lerp(u.getLine(0), v.getLine(0), t)
	});

	for (auto yPos = 1; yPos < n_size; yPos++) {
		res.append(lerp(u.getLine(yPos), v.getLine(yPos), t));
	}
	return res;
}

inline float angle_cos(Vector<float>& u, Vector<float>& v) {
	if (u.getSize() != v.getSize()) {
		throw std::invalid_argument("Vector size must match");
	}
	if (u.getSize() <= 0 || v.getSize() <= 0) {
		throw std::invalid_argument("Vector size must be at least 1");
	}

	return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(Vector<K>& u, Vector<K>& v) {
	if (u.getSize() != v.getSize()) {
		throw std::invalid_argument("Vector size must match");
	}
	if (u.getSize() != 3 || v.getSize() != 3) {
		throw std::invalid_argument("Vector size must be 3");
	}

	K x_res = (u.getValue(1) * v.getValue(2)) - (u.getValue(2) * v.getValue(1));
	K y_res = (u.getValue(2) * v.getValue(0)) - (u.getValue(0) * v.getValue(2));
	K z_res = (u.getValue(0) * v.getValue(1)) - (u.getValue(1) * v.getValue(0));

	return Vector<K>(std::vector{x_res, y_res, z_res});
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &matrix) {
	for (auto vec : matrix.getMatrix()) {
		os << "[ " << vec << " ]" << std::endl;
	}
	return os;
}

template <typename K>
std::ostream & operator<<(std::ostream &os, const Vector<K> &vecIn) {
	for (auto val : vecIn.getVec()) {
		os << "[" << val << "]";
	}
	return os;
}

#endif