#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		Vector<float> u(std::vector{.0f, .0f});
		Vector<float> v(std::vector{.1f, .1f});
		std::cout << v.dot(u) << std::endl; // 0.0
	}
	{
		Vector<float> u(std::vector{.1f, .1f});
		Vector<float> v(std::vector{.1f, .1f});
		std::cout << v.dot(u) << std::endl; // 2.0
	}
	{
		Vector<float> u(std::vector{-1.f, 6.f});
		Vector<float> v(std::vector{3.f, 2.f});
		std::cout << v.dot(u) << std::endl; // 9.0
	}
	return 0;
}