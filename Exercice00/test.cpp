#include "../matrix_lib/headers/Matrix.hpp"

int main() {
	std::vector<float> vec{1, 2, 3, 4, 5};
	Vector<float> vector0(vec);
	Vector<float> vector1(vec);

	Matrix<float> matrix0(std::vector<Vector<float>>{vector0, vector1});
	Matrix<float> matrix1(matrix0);

	std::cout << "|----- adder tests -----|" << std::endl;
	std::cout << "vector0: " << vector0 << std::endl;
	std::cout << "vector1: " << vector1 << std::endl;
	std::cout << "vector0 + vector1: " << std::endl;
	vector0.add(vector1);
	std::cout << "vector0: " << vector0 << std::endl;

	try {
		const std::vector<float> badVector{1, 2, 3, 4};
		vector0.add(Vector(badVector));
	} catch(std::exception& e) {
		std::cout << "exception throw: " << e.what() << std::endl;
	}

	std::cout << "matrix0:\n" << matrix0 << std::endl;
	std::cout << "matrix1:\n" << matrix1 << std::endl;
	matrix0.add(matrix1);
	std::cout << "matrix0 + matrix1:\n" << matrix0 << std::endl;

	std::cout << "|----- subtract tests -----|" << std::endl;
	std::cout << "vector0: " << vector0 << std::endl;
	std::cout << "vector1: " << vector1 << std::endl;
	std::cout << "vector0 - vector1: " << std::endl;
	vector0.subtract(vector1);
	std::cout << "vector0: " << vector0 << std::endl;

	try {
		const std::vector<float> badMatrix{1, 2, 3, 4};
		vector0.subtract(Vector(badMatrix));
	} catch(std::exception& e) {
		std::cout << "exception throw: " << e.what() << std::endl;
	}
	std::cout << "matrix0:\n" << matrix0 << std::endl;
	std::cout << "matrix1:\n" << matrix1 << std::endl;
	matrix0.subtract(matrix1);
	std::cout << "matrix0 - matrix1:\n" << matrix0 << std::endl;

	std::cout << "|----- scale tests -----|" << std::endl;
	std::cout << "vector0: " << vector0 << std::endl;
	std::cout << "vector1: " << vector1 << std::endl;
	std::cout << "vector0 * 2.0: " << std::endl;
	vector0.scale(2.0);
	std::cout << "vector0: " << vector0 << std::endl;

	std::cout << "matrix0:\n" << matrix0 << std::endl;
	std::cout << "matrix1:\n" << matrix1 << std::endl;
	matrix0.scale(2.0);
	std::cout << "matrix0 * 2:\n" << matrix0 << std::endl;


	return 0;
}