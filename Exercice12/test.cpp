#include "../matrix_lib/headers/Matrix.hpp"

int main() {
	//----- SPECIAL TESTS -----//
	{
		const Matrix<float> u(2);
		std::cout << u << std::endl;
	}
	{
		const Matrix u(std::vector{Vector(std::vector{5.f, 2.f}),
									Vector(std::vector{3.f, 9.f})
									});
		std::cout << u.augmented_matrix(Matrix<float>(2)) << std::endl;
	}
	//----- SUBJECT TESTS -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f, 0.f}),
									Vector(std::vector{0.f, 1.f, 0.f}),
									Vector(std::vector{0.f, 0.f, 1.f}),
									});

		std::cout << u.inverse() << std::endl;
		// [1.0, 0.0, 0.0]
		// [0.0, 1.0, 0.0]
		// [0.0, 0.0, 1.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, 0.f, 0.f}),
									Vector(std::vector{0.f, 2.f, 0.f}),
									Vector(std::vector{0.f, 0.f, 2.f})
									});

		std::cout << u.inverse() << std::endl;
		// [0.5, 0.0, 0.0]
		// [0.0, 0.5, 0.0]
		// [0.0, 0.0, 0.5]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{8.f, 5.f, -2.f}),
									Vector(std::vector{4.f, 7.f, 20.f}),
									Vector(std::vector{7.f, 6.f, 1.f})
									});

		std::cout << u.inverse() << std::endl;
		// [0.649425287, 0.097701149, -0.655172414]
		// [-0.781609195, -0.126436782, 0.965517241]
		// [0.143678161, 0.074712644, -0.206896552]
	}
	return 0;
}