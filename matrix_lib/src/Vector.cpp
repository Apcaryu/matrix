#include "../headers/Vector.hpp"

Vector::Vector() {}

Vector::Vector(std::vector<float> arrayIn) {
	vec = arrayIn;

}

Vector::~Vector() {}

std::vector<float> Vector::getVec() {
	return vec;
}

int Vector::getSize() {
	return vec.size();
}

void Vector::showVector() {
	for(float val : vec) {
		std::cout << std::fixed << "[" << val << "]" << std::endl;
	}
}

Matrix Vector::vecToMatrix(int n, int m) {}
Matrix Vector::vecToMatrix(Vector vec, int n, int m) {}
