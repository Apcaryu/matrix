#include "headers/Matrix.hpp"

int main() {

	std::vector<float> vec0{01.f, 02.f, 03.f, 04.f, 05.f};
	std::vector<float> vec1{06.f, 07.f, 08.f, 09.f, 10.f};
	std::vector<float> vec2{11.f, 12.f, 13.f, 14.f, 15.f};

	Vector<float> vector = Vector<float>(vec0);
	
	vector.showVector(2, 4);
	std::cout << std::endl;


	std::vector<Vector<float>> vecList{vec0, vec1, vec2};

	Matrix<float> matrix0(vecList);	
	matrixShape matrix0Shape = matrix0.getShape();
	std::cout << std::boolalpha;
	std::cout << "[ n:" << matrix0Shape.n << " | m:" << matrix0Shape.m << " ]" << std::endl;
	std::cout << "isSquare: " << matrix0.isSquare() << std::endl;

	std::cout << "add two Vector" << std::endl;
	vecList.push_back(Vector<float>(std::vector<float>{16.f, 17.f, 18.f, 19.f, 20.f}));
	vecList.push_back(Vector<float>(std::vector<float>{21.f, 22.f, 23.f, 24.f, 25.f}));
	
	Matrix<float> matrix1(vecList);
	matrixShape matrix1Shape = matrix1.getShape();
	std::cout << "[ n:" << matrix1Shape.n << " | m:" << matrix1Shape.m << " ]" << std::endl;
	std::cout << "isSquare: " << matrix1.isSquare() << std::endl;

	std::cout << "matrix0" << std::endl;
	matrix0.printMatrix(2, 4);
	std::cout << "matrix1" << std::endl;
	matrix1.printMatrix(2, 4);

	return 0;
}