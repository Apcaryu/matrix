#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TESTS -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f, 0.f}),
									Vector(std::vector{0.f, 1.f, 0.f}),
									Vector(std::vector{0.f, 0.f, 1.f})});

		std::cout << u.row_echelon() << std::endl;
		// [1.0, 0.0, 0.0]
		// [0.0, 1.0, 0.0]
		// [0.0, 0.0, 1.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 2.f}),
									Vector(std::vector{3.f, 4.f})});

		std::cout << u.row_echelon() << std::endl;
		// [1.0, 0.0]
		// [0.0, 1.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 2.f}),
									Vector(std::vector{2.f, 4.f})});

		std::cout << u.row_echelon() << std::endl;
		// [1.0, 2.0]
		// [0.0, 0.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{8.f, 5.f, -2.f, 4.f, 28.f}),
									Vector(std::vector{4.f, 2.5f, 20.f, 4.f, -4.f}),
									Vector(std::vector{8.f, 5.f, 1.f, 4.f, 17.f})});

		std::cout << u.row_echelon() << std::endl;
		// [1.0, 0.625, 0.0, 0.0, -12.1666667]
		// [0.0, 0.0, 1.0, 0.0, -3.6666667]
		// [0.0, 0.0, 0.0, 1.0, 29.5]
	}
	return 0;
}