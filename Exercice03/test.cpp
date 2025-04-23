#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		const Vector u(std::vector{.0f, .0f});
		const Vector v(std::vector{1.f, 1.f});
		std::cout << v.dot(u) << std::endl; // 0.0
	}
	{
		const Vector u(std::vector{1.f, 1.f});
		const Vector v(std::vector{1.f, 1.f});
		std::cout << v.dot(u) << std::endl; // 2.0
	}
	{
		const Vector u(std::vector{-1.f, 6.f});
		const Vector v(std::vector{3.f, 2.f});
		std::cout << v.dot(u) << std::endl; // 9.0
	}
	return 0;
}