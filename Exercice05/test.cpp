#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	//----- SUBJECT TEST -----//
	{
		Vector u(std::vector<float>{1.f, 0.f});
		Vector v(std::vector<float>{1.f, 0.f});
		std::cout << angle_cos(u, v) << std::endl;
		// 1.0
	}
	{
		Vector u(std::vector<float>{1.f, 0.f});
		Vector v(std::vector<float>{1.f, 0.f});
		std::cout << angle_cos(u, v) << std::endl;
		// 0.0
	}
	{
		Vector u(std::vector<float>{1.f, 0.f});
		Vector v(std::vector<float>{1.f, 0.f});
		std::cout << angle_cos(u, v) << std::endl;
		// -1.0
	}
	{
		Vector u(std::vector<float>{1.f, 0.f});
		Vector v(std::vector<float>{1.f, 0.f});
		std::cout << angle_cos(u, v) << std::endl;
		// 1.0
	}
	{
		Vector u(std::vector<float>{1.f, 0.f});
		Vector v(std::vector<float>{1.f, 0.f});
		std::cout << angle_cos(u, v) << std::endl;
		// 0.974631846
	}
	return 0;
}