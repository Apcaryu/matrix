#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		const Vector u(std::vector{.0f, .0f, .0f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
		// 0.0, 0.0, 0.0
	}
	{
		const Vector u(std::vector{1.f, 2.f, 3.f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
		// 6.0, 3.74165738, 3.0
	}
	{
		const Vector u(std::vector{-1.f, -2.f});
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;
		// 3.0, 2.236067977, 2.0
	}
	return 0;
}