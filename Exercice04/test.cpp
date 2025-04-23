#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		const Vector u(std::vector{.0f, .0f, .0f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
	}
	{
		const Vector u(std::vector{1.f, 2.f, 3.f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
	}
	{
		const Vector u(std::vector{-1.f, -2.f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
	}
	return 0;
}