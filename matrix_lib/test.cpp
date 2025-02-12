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
	try {
		matrix0.append(Vector<float>(std::vector{16.f, 17.f, 18.f, 19.f, 20.f, 21.f}));
	} catch (const std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}
	std::cout << "----------" << std::endl;
	matrix0.append(matrix1);
	matrix0.printMatrix(2);
	try {
		auto matrix2 = Matrix<float>(std::vector<Vector<float>>{Vector<float>(std::vector<float>{1, 2, 3, 4, 5, 6, 7}), Vector<float>(std::vector<float>{10, 20, 30, 40, 50, 60, 70})});
		matrix0.append(matrix2);
	} catch (const std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}

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
		std::cout << "convert and rollback succeed" << std::endl;
	} else {
		std::cout << "convert and rollback failed" << std::endl;
	}

	std::cout << "|----- convert vector to matrix and matrix to vec -----|" << std::endl;
	Vector<float> res1 = vector1.vecToMatrix(3, 2).matrixToVector();
	if (vector1.isEqual(res1)) {
		std::cout << "convert and rollback succeed" << std::endl;
	} else {
		std::cout << "convert and rollback failed" << std::endl;
	}

	float value = matrix1.getValue(2, 3);
	std::cout << "value: " << value << std::endl;
	try {
		[[maybe_unused]] float eValue = matrix1.getValue(1000, 3);
	} catch (std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}
	try {
		[[maybe_unused]] float eValue = matrix1.getValue(1, 2000);
	} catch (std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}

	std::vector<float> line = matrix1.getLine(2);
	std::cout << "line: " << std::endl;
	for (auto val : line) {
		std::cout << "[ " << val << " ]" << std::endl;
	}
	try {
		[[maybe_unused]] auto eValue = matrix1.getLine(1000);
	} catch (std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}

	std::vector<float> colum = matrix1.getColumn(3);
	std::cout << "colum: " << std::endl;
	for (auto val : colum) {
		std::cout << "[ " << val << " ]" << std::endl;
	}
	try {
		[[maybe_unused]] auto eValue = matrix1.getColumn(2000);
	} catch (std::exception& error) {
		std::cout << "exception throw: " << error.what() << std::endl;
	}

	std::cout << "|----- matrix set tests -----|" << std::endl;
	std::vector<float> vec5{1.f, 2.f, 3.f, 4.f, 5.f};

	matrix1.setValue(100.f, 4, 2);
	matrix1.printMatrix(2);
	try {
		matrix1.setValue(412.f, 1000, 2);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}
	try {
		matrix1.setValue(42.f, 2, 2000);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}

	matrix1.setLine(vec5, 2);
	matrix1.printMatrix(2);
	try {
		matrix1.setLine(std::vector<float>{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f}, 3);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}
	try {
		matrix1.setLine(std::vector<float>{1.f, 2.f, 3.f, 4.f, 5.f}, 1000);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}

	matrix1.setColumn(vec5, 3);
	matrix1.printMatrix(2);
	try {
		matrix1.setColumn(std::vector<float>{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f}, 2);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}
	try {
		matrix1.setColumn(std::vector<float>{1.f, 2.f, 3.f, 4.f, 5.f}, 2000);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}

	std::cout << "|----- vector set tests -----|" << std::endl;
	std::cout << "before setValue: ";
	vector.showVector(2);
	std::cout << std::endl;
	vector.setValue(8.f, 2);
	std::cout << "after setValue: ";
	vector.showVector(2);
	std::cout << std::endl;
	try {
		vector.setValue(8.f, 1000);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown : " << error.what() << std::endl;
	}

	std::cout << "value at 4: " << vector.getValue(4) << std::endl;
	try {
		[[maybe_unused]] auto eValue = vector.getValue(1000);
	} catch (std::invalid_argument const &error) {
		std::cout << "exception thrown: " << error.what() << std::endl;
	}

	return 0;
}