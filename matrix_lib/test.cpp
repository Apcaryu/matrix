#include "headers/Matrix.hpp"

int main() {

	std::vector<float> vec0{01.f, 02.f, 03.f, 04.f, 05.f};
	std::vector<float> vec1{06.f, 07.f, 08.f, 09.f, 10.f};
	std::vector<float> vec2{11.f, 12.f, 13.f, 14.f, 15.f};
	std::vector<float> vec3{16.f, 17.f, 18.f, 19.f, 20.f};

	Vector<float> vector = Vector<float>(vec0);
	
	vector.showVector(2);
	std::cout << std::endl;
	

	std::vector<Vector<float>> vecList{Vector<float>(vec0), Vector<float>(vec1), Vector<float>(vec2)};

	Matrix<float> matrix0(vecList);	
	matrixShape matrix0Shape = matrix0.getShape();
	std::cout << std::boolalpha;
	std::cout << "[ n:" << matrix0Shape.n << " | m:" << matrix0Shape.m << " ]" << std::endl;
	std::cout << "isSquare: " << matrix0.isSquare() << std::endl;

	std::cout << "add two Vector" << std::endl;
	vecList.emplace_back(std::vector<float>{16.f, 17.f, 18.f, 19.f, 20.f});
	vecList.emplace_back(std::vector<float>{21.f, 22.f, 23.f, 24.f, 25.f});
	
	Matrix<float> matrix1(vecList);
	matrixShape matrix1Shape = matrix1.getShape();
	std::cout << "[ n:" << matrix1Shape.n << " | m:" << matrix1Shape.m << " ]" << std::endl;
	std::cout << "isSquare: " << matrix1.isSquare() << std::endl;

	std::cout << "matrix0" << std::endl;
	matrix0.printMatrix(2);
	std::cout << "matrix1" << std::endl;
	matrix1.printMatrix(2);


	std::cout << "|----- vec append tests -----|" << std::endl;
	vector.append(6.f);
	vector.showVector(2);
	std::cout << std::endl;

	vector.append(Vector<float>(vec2));
	vector.showVector(2);
	std::cout << std::endl;

	std::cout << "|----- matrix append tests -----|" << std::endl;
	matrix0.append(Vector<float>(vec3));
	matrix0.printMatrix(2);
	std::cout << "----------" << std::endl;
	matrix0.append(matrix1);
	matrix0.printMatrix(2);

	std::cout << "|----- convertion matrix to vector -----|" << std::endl;
	Vector<float> superVec = matrix1.matrixToVector();
	superVec.showVector(2);
	std::cout << std::endl;

	std::cout << "|----- convertion vector to matrix -----|" << std::endl;
	Vector<float>vector1(std::vector<float>{16.f, 17.f, 18.f, 19.f, 20.f, 21.f});
	Matrix<float> superMatrix0 = vector1.vecToMatrix(2,3);
	superMatrix0.printMatrix(2);
	
	std::cout << "|----- convert matrix to vec and vec to matrix -----|" << std::endl;
	Matrix<float> initMatrix1(matrix1);
	Matrix<float> res = matrix1.matrixToVector().vecToMatrix(5, 5);
	if (matrix1.isEqual(res)){
		std::cout << "convert and rollback succed" << std::endl;
	} else {
		std::cout << "convert and rollback failled" << std::endl;
	}

	std::cout << "|----- convert vector to matrix and matrix to vec -----|" << std::endl;
	Vector<float> res1 = vector1.vecToMatrix(3, 2).matrixToVector();
	if (vector1.isEqual(res1)) {
		std::cout << "convert and rollback succed" << std::endl;
	} else {
		std::cout << "convert and rollback failled" << std::endl;
	}

	return 0;
}