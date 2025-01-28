#include "headers/Matrix.hpp"
#include "headers/Vector.hpp"

int main() {

	std::vector<float> vec = {1, 2, 3, 4, 5};
	Vector vector = Vector(vec);

	vector.showVector();
	return 0;
}