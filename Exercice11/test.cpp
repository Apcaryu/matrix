#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- PERSONAL TESTS -----//

	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 2.f, 3.f}),
									Vector(std::vector{1.f, 2.f, 3.f})
									});
		try {
			[[maybe_unused]] float det = u.determinant();
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	// 2x2 matrix
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 3.f}),
									Vector(std::vector{7.f, 4.f})
									});

		std::cout << u.determinant() << std::endl;
		// -17
	}

	// 3x3
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, 4.f, -5.f}),
									Vector(std::vector{8.f, 1.f, -3.f}),
									Vector(std::vector{-9.f, 6.f, 7.f}),
									});

		std::cout << u.determinant() << std::endl;
		// -351
	}

	//----- SUBJECT TESTS -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, -1.f}),
									Vector(std::vector{-1.f, 1.f}),
									});

		std::cout << u.determinant() << std::endl;
		// 0
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, 0.f, 0.f}),
									Vector(std::vector{0.f, 2.f, 0.f}),
									Vector(std::vector{0.f, 0.f, 2.f})
									});

		std::cout << u.determinant() << std::endl;
		// 8
	}
	{
		const Matrix u(std::vector{Vector(std::vector{8.f, 5.f, -2.f}),
									Vector(std::vector{4.f, 7.f, 20.f}),
									Vector(std::vector{7.f, 6.f, 1.f})
									});

		std::cout << u.determinant() << std::endl;
		// -174
	}
	{
		const Matrix u(std::vector{Vector(std::vector{8.f, 5.f, -2.f, 4.f}),
									Vector(std::vector{4.f, 2.5f, 20.f, 4.f}),
									Vector(std::vector{8.f, 5.f, 1.f, 4.f}),
									Vector(std::vector{28.f, -4.f, 17.f, 1.f})
									});

		std::cout << u.determinant() << std::endl;
		// 1032
	}
	return 0;
}