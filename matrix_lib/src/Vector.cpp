#include "../headers/Vector.hpp"

Vector::Vector() {}
Vector::Vector(float* arrayIn) {}

Vector::~Vector() {}

std::vector<float>& Vector::getVec() {}
int Vector::getSize() {}
int Vector::getSize(Vector vec) {}

void Vector::showVector() {}
void Vector::showVector(Vector vec) {}

Matrix Vector::vecToMatrix(int n, int m) {}
Matrix Vector::vecToMatrix(Vector vec, int n, int m) {}
