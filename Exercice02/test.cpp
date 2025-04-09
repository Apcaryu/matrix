#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	std::cout << lerp(0.f, 1.f, 0.) << std::endl;
	//0.0
	std::cout << lerp(0.f, 1.f, 1.f) << std::endl;
	//1.0
	std::cout << lerp(0.f, 1.f, .5f) << std::endl;
	//0.5
	std::cout << lerp(21.f, 42.f, .3f) << std::endl;
	//27.3
	std::cout << lerp(Vector<float>(std::vector{2.f, 1.f}), Vector<float>(std::vector{4.f, 2.f}), 0.3) << std::endl;
	//[2.6, 1.3]
	std::cout << lerp(Matrix<float>(std::vector{Vector(std::vector{2.f, 1.f}), Vector(std::vector{3.f, 4.f})}),
	                  Matrix<float>(std::vector{Vector(std::vector{20.f, 10.f}), Vector(std::vector{30.f, 40.f})}),
	                  .5f) << std::endl;
	// [11.0, 05.5]
	// [16.5, 22.0]
	return 0;
}