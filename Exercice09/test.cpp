#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- TESTS -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f}),
									Vector(std::vector{0.f, 1.f})});
		const Matrix v(std::vector{Vector(std::vector{1.f, 0.f}),
									Vector(std::vector{0.f, 1.f})});
		if (u == v) {
			std::cout << "Example 0 is valid" << std::endl;
		} else {
			std::cout << "Example 0 is not valid" << std::endl;
		}
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, -5.f, 0.f}),
									Vector(std::vector{4.f, 3.f, 7.f}),
									Vector(std::vector{-2.f, 3.f, 4.f})});
		const Matrix v(std::vector{Vector(std::vector{2.f, 4.f, -2.f}),
									Vector(std::vector{-5.f, 3.f, 3.f}),
									Vector(std::vector{0.f, 7.f, 4.f})});
		if (u == v) {
			std::cout << "Example 1 is valid" << std::endl;
		} else {
			std::cout << "Example 1 is not valid" << std::endl;
		}
	}
	{
		const Matrix u(std::vector{Vector(std::vector{-2.f, -8.f, 4.f}),
									Vector(std::vector{1.f, -23.f, 4.f}),
									Vector(std::vector{0.f, 6.f, 4.f})});
		const Matrix v(std::vector{Vector(std::vector{-2.f, 1.f, 0.f}),
									Vector(std::vector{-8.f, -23.f, 6.f}),
									Vector(std::vector{4.f, 4.f, 4.f})});
		if (u == v) {
			std::cout << "Example 2 is valid" << std::endl;
		} else {
			std::cout << "Example 2 is not valid" << std::endl;
		}
	}
	return 0;
}