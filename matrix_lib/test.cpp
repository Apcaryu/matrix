#include "headers/Matrix.hpp"

int main() {

	std::vector<float> vec{1.f, 2.f, 3.f, 4.f, 5.f};
	Vector<float> vector = Vector<float>(vec);

	vector.showVector();
	return 0;
}