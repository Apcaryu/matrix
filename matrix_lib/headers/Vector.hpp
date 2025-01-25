#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include "Matrix.hpp"

class Vector
{
private:
	std::vector<float>* vec = new std::vector<float>;

public:
	Vector();
	Vector(float* arrayIn);
	~Vector();

	std::vector<float>& getVec();
	int getSize();
	int getSize(Vector vec);

	void showVector();
	void showVector(Vector vec);

	Matrix vecToMatrix();
	Matrix vecToMatrix(Vector vec);
};

#endif