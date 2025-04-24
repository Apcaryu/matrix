#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		Vector u(std::vector<float>{1.f, 0.f, 1.f});
		Vector v(std::vector<float>{1.f, 0.f, 1.f});
		std::cout << cross_product(u, v) << std::endl;
		// [0.0, 1.0, 0.0]
	}
	{
		Vector u(std::vector<float>{1.f, 0.f, 1.f});
		Vector v(std::vector<float>{1.f, 0.f, 1.f});
		std::cout << cross_product(u, v) << std::endl;
		// [-3.0, 6.0, -3.0]
	}
	{
		Vector u(std::vector<float>{1.f, 0.f, 1.f});
		Vector v(std::vector<float>{1.f, 0.f, 1.f});
		std::cout << cross_product(u, v) << std::endl;
		// [17.0, -58.0, -16.0]
	}
	return 0;
}