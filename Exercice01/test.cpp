#include "../matrix_lib/headers/Matrix.hpp"

int main() {
	std::vector<float> vec{1, 2, 3, 4, 5};
	Vector<float> vector0(vec);
	Vector<float> vector1(vec);
	std::vector<Vector<float>> vector_list0{vector0, vector1};
	std::vector<float> coefs{10.f, 5.f};

	Vector<float>::linear_conbination(vector_list0, coefs);
	return 0;
}