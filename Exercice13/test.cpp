#include "../matrix_lib/headers/Matrix.hpp"

int main() {
	//----- SPECIAL TESTS -----//
	{
		const Vector x(std::vector{1.f, 0.f, 1.5f});
		const Vector y(std::vector{0.f, 0.f, 1.f});
		const Vector z(std::vector{0.f, 0.f, 0.f});

		std::cout << "x: " << x.isZeroVector() << std::endl;
		std::cout << "y: " << y.isZeroVector() << std::endl;
		std::cout << "z: " << z.isZeroVector() << std::endl;
	}

	//----- SUBJECT TESTS -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f, 0.f}),
									Vector(std::vector{0.f, 1.f, 0.f}),
									Vector(std::vector{0.f, 0.f, 1.f}),
									});

		std::cout << u.rank() << std::endl;
		// 3
	}
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 2.f, 0.f, 0.f}),
									Vector(std::vector{2.f, 4.f, 0.f, 0.f}),
									Vector(std::vector{-1.f, 2.f, 1.f, 1.f})
									});

		std::cout << u.rank() << std::endl;
		// 2
	}
	{
		const Matrix u(std::vector{Vector(std::vector{8.f, 5.f, -2.f}),
									Vector(std::vector{4.f, 7.f, 20.f}),
									Vector(std::vector{7.f, 6.f, 1.f}),
									Vector(std::vector{21.f, 18.f, 7.f})
									});

		std::cout << u.rank() << std::endl;
		// 3
	}
	return 0;
}