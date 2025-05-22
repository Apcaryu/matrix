#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f}),
									Vector(std::vector{0.f, 1.f})});
		std::cout << u.trace() << std::endl;
		// 2
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, -5.f, 0.f}),
									Vector(std::vector{4.f, 3.f, 7.f}),
									Vector(std::vector{-2.f, 3.f, 4.f})});
		std::cout << u.trace() << std::endl;
		// 9
	}
	{
		const Matrix u(std::vector{Vector(std::vector{-2.f, -8.f, 4.f}),
									Vector(std::vector{1.f, -23.f, 4.f}),
									Vector(std::vector{0.f, 6.f, 4.f})});
		std::cout << u.trace() << std::endl;
		// -21
	}
	return 0;
}