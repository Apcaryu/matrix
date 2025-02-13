#include "../matrix_lib/headers/Matrix.hpp"

int main() {
	std::vector<float> vec{1, 2, 3, 4, 5};
	Vector<float> vector0(vec);
	Vector<float> vector1(vec);

	Matrix<float> matrix0(std::vector<Vector<float>>{vector0, vector1});
	Matrix<auto> matrix1(matrix0);

	vector0.add(vector1);
	matrix0.add(matrix1);

	vector0.substract(vector1);
	matrix0.substract(matrix1);

	vector0.scale(2.0);
	matrix0.scale(2.0);
	return 0;
}