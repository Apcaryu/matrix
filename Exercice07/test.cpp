#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f}), Vector(std::vector{0.f, 1.f})});
		const Vector v(std::vector<float>{4.f, 2.f});
		std::cout << u.mul_vec(v) << std::endl;
		// [4.0, 2.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, 0.f}), Vector(std::vector{0.f, 2.f})});
		const Vector v(std::vector<float>{4.f, 2.f});
		std::cout << u.mul_vec(v) << std::endl;
		// [8.0, 4.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{2.f, -2.f}), Vector(std::vector{-2.f, 2.f})});
		const Vector v(std::vector<float>{4.f, 2.f});
		std::cout << u.mul_vec(v) << std::endl;
		// [4.0, -4.0]
	}

	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f}), Vector(std::vector{0.f, 1.f})});
		const Matrix v(std::vector{Vector(std::vector{1.f, 0.f}), Vector(std::vector{0.f, 1.f})});
		std::cout << u.mul_mat(v) << std::endl;
		// [1.0, 0.0]
		// [0.0, 1.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{1.f, 0.f}), Vector(std::vector{0.f, 1.f})});
		const Matrix v(std::vector{Vector(std::vector{2.f, 1.f}), Vector(std::vector{4.f, 2.f})});
		std::cout << u.mul_mat(v) << std::endl;
		// [2.0, 1.0]
		// [4.0, 2.0]
	}
	{
		const Matrix u(std::vector{Vector(std::vector{3.f, -5.f}), Vector(std::vector{6.f, 8.f})});
		const Matrix v(std::vector{Vector(std::vector{2.f, 1.f}), Vector(std::vector{4.f, 2.f})});
		std::cout << u.mul_mat(v) << std::endl;
		// [-14.0, -7.0]
		// [44.0, 22.0]
	}
	return 0;
}