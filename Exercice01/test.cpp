#include "../matrix_lib/headers/Matrix.hpp"

int main() {

	Vector vector1_0(std::vector{1.f});
	Vector vector1_1(std::vector{2.f});
	Vector vector1_2(std::vector{3.f});

	Vector vector2_0(std::vector{0.f, 1.f});
	Vector vector2_1(std::vector{2.f, 3.f});
	Vector vector2_2(std::vector{10.f, 1.f});

	Vector vector3_0(std::vector{0.f, 1.f, 2.f});
	Vector vector3_1(std::vector{2.f, 1.f, 0.f});
	Vector vector3_2(std::vector{1.f, 2.f, 0.f});

	std::vector coefs1{3.f};
	std::vector coefs2{2.f, 6.f};
	std::vector coefs3{-5.f, 10.f, 4.f};

	//----- SIZE OF VECTORS IN LIST TEST -----//
	printf("|----- SIZE OF VECTORS IN LIST TEST -----|\n");
	try {
		Vector<float>::linear_combination(std::vector{vector1_0, vector2_0}, std::vector{0.f, 0.f});
		throw std::exception();
	} catch (std::invalid_argument&) {
		printf("verification size of vectors in list succeed\n");
	} catch (std::exception&) {
		printf("verification size of vectors in list failed\n");
	}

	try {
		Vector<float>::linear_combination(std::vector{vector3_0, vector2_0}, std::vector{0.f, 0.f});
		throw std::exception();
	} catch (std::invalid_argument&) {
		printf("verification size of vectors in list succeed\n");
	} catch (std::exception&) {
		printf("verification size of vectors in list failed\n");
	}

	try {
		Vector<float>::linear_combination(std::vector{vector1_0, vector1_0}, std::vector{0.f, 0.f});
		printf("verification size of vectors in list succeed\n");
	} catch (std::exception&) {
		printf("verification size of vectors in list failed\n");
	}
	printf("\n");

	//----- SIZE OF LIST IN PARAMETERS TEST -----//
	printf("|----- SIZE OF LIST IN PARAMETERS TEST -----|\n");
	try {
		Vector<float>::linear_combination(std::vector{vector1_0}, coefs2);
		throw std::exception();
	} catch (std::invalid_argument&) {
		printf("verification size of list succeed\n");
	} catch (std::exception&) {
		printf("verification size of lists failed\n");
	}

	try {
		Vector<float>::linear_combination(std::vector{vector1_0,vector1_1}, coefs1);
		throw std::exception();
	} catch (std::invalid_argument&) {
		printf("verification size of list succeed\n");
	} catch (std::exception&) {
		printf("verification size of lists failed\n");
	}

	try {
		Vector<float>::linear_combination(std::vector{vector1_0}, coefs1);
		printf("verification size of list succeed\n");
	} catch (std::exception&) {
		printf("verification size of lists failed\n");
	}
	printf("\n");

	//----- RESULT TEST -----//
	printf("|----- RESULT TEST -----|\n");
	Vector res1 = Vector<float>::linear_combination(std::vector{vector1_0}, coefs1);
	if (res1.getVec() == std::vector{3.f}) { printf("res1 succeed\n"); } else { printf("res1 failed\n"); }

	Vector res2 = Vector<float>::linear_combination(std::vector{vector2_0, vector2_1}, coefs2);
	if (res2.getVec() == std::vector{12.f, 20.f}) { printf("res2 succeed\n"); } else { printf("res2 failed\n"); }

	Vector res3 = Vector<float>::linear_combination(std::vector{vector3_0, vector3_1, vector3_2}, coefs3);
	if (res3.getVec() == std::vector{24.f, 13.f, -10.f}) { printf("res3 succeed\n"); } else { printf("res3 failed\n"); }

	Vector res4 = Vector<float>::linear_combination(std::vector{vector2_0}, coefs1);
	if (res4.getVec() == std::vector{0.f, 3.f}) { printf("res4 succeed\n"); } else { printf("res4 failed\n"); }

	printf("\n");
	//------ SUBJECT TEST -----//
	printf("|----- SUBJECT TEST -----|\n");
	const Vector e1(std::vector{1.f, 0.f, 0.f});
	const Vector e2(std::vector{0.f, 1.f, 0.f});
	const Vector e3(std::vector{0.f, 0.f, 1.f});

	Vector v1(std::vector{1.f, 2.f, 3.f});
	Vector v2(std::vector{0.f, 10.f, -100.f});

	Vector res_e(Vector<float>::linear_combination(std::vector{e1, e2, e3}, std::vector{10.f, -2.f, .5f}));
	// res_e.showVector(2);
	try {
		std::vector expected_result{10.f, -2.f, .5f};
		if (res_e.getVec() != expected_result) {
			throw std::exception();
		}
		printf("res_e is valid\n");
	} catch ([[maybe_unused]] std::exception& e) {
		printf("res_e have not the expected value\n");
	}
	Vector res_v(Vector<float>::linear_combination(std::vector{v1, v2}, std::vector{10.f, -2.f}));
	// res_v.showVector(2);
	try {
		std::vector expected_result{10.f, 0.f, 230.f};
		if (res_v.getVec() != expected_result) {
			throw std::exception();
		}
		printf("res_v is valid\n");
	} catch (std::exception&) {
		printf("res_v have not the expected value\n");
	}

	return 0;
}