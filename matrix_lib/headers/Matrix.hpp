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

	//This is constructor for a generation of square matrix with a list of value
	Matrix(const Vector<K> valueList, const int size) {
		shape.n = size;
		shape.m = size;
		for (int i = 0; i < size; i++) {
			Vector<K> tmp_vec;
			for (int j = 0; j < size; j++) {
				tmp_vec.append(valueList.getValue(j+size*i));
			}
			content.push_back(tmp_vec);
		}
	}

	// create identity matrix
	explicit Matrix(const int size) {
		shape.n = size;
		shape.m = size;
		Vector<K> zero_vec;
		for (int i = 0; i < size; i++) {
			zero_vec.append(0);
		}
		for (int i = 0; i < size; i++) {
			//std::cout << *this << std::endl;
			content.push_back(zero_vec);
			this->setValue(1, i, i);
		}
	}

	~Matrix() = default;

	Matrix<K> & operator=(Matrix<K> const &rhs) {
		shape = rhs.getShape();
		content = rhs.getMatrix();
		return *this;
	};

	int operator==(Matrix const &rhs) const {
		if (shape.m != rhs.shape.m || shape.n != rhs.shape.n) {
			return 0;
		}
		for (auto i = 0; i < shape.n; i++) {
			for (auto j = 0; j < shape.m; j++) {
				if (this->getValue(i, j) != rhs.getValue(i, j)) {
					return 0;
				}
			}
		}
		return 1;
	}

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
		if (lineIn.getSize() != shape.m)
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
	[[nodiscard]] Vector<K> getLineVec(int nPos) const {//TODO make tests for this funcion
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
		K res = 0;
		for (int yPos = 0; yPos < this->getShape().n; yPos++) {
			res += this->getValue(yPos, yPos);
		}
		return res;
	}

	Matrix transpose() const {
		Matrix result(this->getShape());
		for (int yPos = 0; yPos < this->getShape().n; yPos++) {
			Vector<K> tmp_vec(this->getColumn(yPos));
			result.setLine(tmp_vec.getVec(), yPos);
		}
		return result;
	}

	Matrix row_echelon() const {
		Matrix result(*this);
		int h = 0;
		int k = 0;

		while (h < result.getShape().n && k < result.getShape().m) {
			int i_max = h;
			K max_val = std::abs(result.getValue(h, k));

			for (int i = h + 1; i < result.getShape().n; i++) {
				K val = std::abs(result.getValue(i, k));
				if (val > max_val) {
					max_val = val;
					i_max = i;
				}
			}

			if (result.getValue(i_max, k) == 0) {
				k++;
				continue;
			}

			if (i_max != h) {
				Vector<K> tmp = result.getLineVec(h);
				result.setLine(result.getLine(i_max), h);
				result.setLine(tmp, i_max);
			}

			K pivot = result.getValue(h, k);
			for (int j = k; j < result.getShape().m; j++) {
				result.setValue(result.getValue(h, j) / pivot, h, j);
			}

			for (int i = 0; i < result.getShape().n; i++) {
				if (i != h) {
					K factor = result.getValue(i, k);
					for (int j = k; j < result.getShape().m; j++) {
						K new_val = result.getValue(i, j) - factor * result.getValue(h, j);
						result.setValue(new_val, i, j);
					}
				}
			}
			h++;
			k++;
		}

		return result;
	}

	// case 2x2 matrix determinant
	K det2() const {
		K res = 0;

		K a = this->getValue(0, 0);
		K b = this->getValue(0, 1);
		K c = this->getValue(1, 0);
		K d = this->getValue(1, 1);

		res = a*d - b*c;

		return res;

	}

	// case 3x3 matrix determinant
	K det3() const {
		K res = 0;

		K a = this->getValue(0, 0);
		K b = this->getValue(0, 1);
		K c = this->getValue(0, 2);
		K d = this->getValue(1, 0);
		K e = this->getValue(1, 1);
		K f = this->getValue(1, 2);
		K g = this->getValue(2, 0);
		K h = this->getValue(2, 1);
		K i = this->getValue(2, 2);

		res = a*e*i + d*h*c + b*f*g - (g*e*c + d*b*i + a*h*f);

		return res;
	}

	K det() const {
		K res = 0;
		bool isPlus = true;

		for (int i = 0; i < this->getShape().n; i++) {
			K val = this->getValue(i, 0);
			std::vector<K> tmp_vec{};
			for (int y = 1; y < this->getShape().n; y++) {
				for (int x = 0; x < this->getShape().n; x++) {
					if (x != i) {
						tmp_vec.push_back(this->getValue(x, y));
					}
				}
			}

			Matrix tmp_mat{Vector<K>(tmp_vec), this->getShape().n-1};
			K tmp_res = 0;
			if (!isPlus) {
				tmp_res = val * tmp_mat.determinant() * -1;
			} else {
				tmp_res = val * tmp_mat.determinant();
			}
			res += tmp_res;
			isPlus = !isPlus;
		}

		return res;
	}

	K determinant() const {
		if (!this->isSquare()) {
			throw std::invalid_argument("Matrix must be a square");
		}

		K res = 0;
		if (this->getShape().n == 2) {
			res = det2();
		} else if (this->getShape().n == 3) {
			res = det3();
		} else {
			res = det();
		}

		return res;
	}

	Matrix augmented_matrix(Matrix right) const {
		matrixShape am_shape;
		am_shape.n = this->getShape().n;
		am_shape.m = this->getShape().m + right.getShape().m;
		Matrix res(am_shape);

		for (int i = 0; i < am_shape.n; i++) {
			Vector<K> tmp = this->getLineVec(i);
			tmp.append(right.getLineVec(i));
			res.setLine(tmp, i);
		}
		return res;
	}

	Matrix inverse() const {
		Matrix res{this->getShape()};
		Matrix tmp = this->augmented_matrix(Matrix{this->getShape().n}).row_echelon();

		std::cout << tmp.getValue(0, 3) << std::endl;
		for (int i = 0; i < res.getShape().n; i++) {
			for (int j = 0; j < res.getShape().m; j++) {
				res.setValue(tmp.getValue(i, j+res.getShape().m),i,j);
			}
		}
		return res;
	}

	size_t rank() const {
		size_t res = 0;
		const Matrix echelon_form = this->row_echelon();

		for (int i = 0; i < echelon_form.getShape().n; i++) {
			if (!echelon_form.getLineVec(i).isZeroVector()) { res++; }
		}
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

	bool isZeroVector() const {
		for (int i = 0; i < this->getSize(); i++) {
			if (vec[i] != 0) { return false; }
		}
		return true;
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