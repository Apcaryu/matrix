#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		Vector u(std::vector<float>{0.f, 0.f, 1.f});
		Vector v(std::vector<float>{1.f, 0.f, 0.f});
		std::cout << cross_product(u, v) << std::endl;
		// [0.0, 1.0, 0.0]
	}
	{
		Vector u(std::vector<float>{1.f, 2.f, 3.f});
		Vector v(std::vector<float>{4.f, 5.f, 6.f});
		std::cout << cross_product(u, v) << std::endl;
		// [-3.0, 6.0, -3.0]
	}
	{
		Vector u(std::vector<float>{4.f, 2.f, -3.f});
		Vector v(std::vector<float>{-2.f, -5.f, 16.f});
		std::cout << cross_product(u, v) << std::endl;
		// [17.0, -58.0, -16.0]
	}
	return 0;
}