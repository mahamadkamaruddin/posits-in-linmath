#include <iostream>
#include <chrono>
#include <cmath>
#include "linmath.h"
#include "linmath_posit.h"
#include "/workspaces/posits-in-linmath/softposit_cpp/include/softposit.h"
#include <cstdlib>
#include <ctime>

void benchmark() {
    // Example: Compare vec3 addition
    vec3 a = {1.0f, 2.0f, 3.0f}, b = {4.0f, 5.0f, 6.0f}, r;
    vec3_posit a_posit = {convertFloatToP32(1.0f), convertFloatToP32(2.0f), convertFloatToP32(3.0f)};
    vec3_posit b_posit = {convertFloatToP32(4.0f), convertFloatToP32(5.0f), convertFloatToP32(6.0f)};
    vec3_posit r_posit;

    auto start = std::chrono::high_resolution_clock::now();
    vec3_add(r, a, b);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Float addition time: " << std::chrono::duration<double>(end - start).count() << "s\n";

    start = std::chrono::high_resolution_clock::now();
    vec3_posit_add(r_posit, a_posit, b_posit);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Posit addition time: " << std::chrono::duration<double>(end - start).count() << "s\n";
}

void accuracy_test() {
    float a = 1e10f, b = 1e-10f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a + b;
    posit32_t posit_result = p32_add(a_posit, b_posit);

    std::cout << "Float result: " << float_result << "\n";
    std::cout << "Posit result: " << convertP32ToDouble(posit_result) << "\n";
}

void precision_loss_test() {
    float large = 1e10f, small = 1e-10f;
    posit32_t large_posit = convertFloatToP32(large);
    posit32_t small_posit = convertFloatToP32(small);

    float float_result = large + small;
    posit32_t posit_result = p32_add(large_posit, small_posit);

    std::cout << "Float result: " << float_result << "\n";
    std::cout << "Posit result: " << convertP32ToDouble(posit_result) << "\n";
}

void summation_test() {
    float sum_float = 0.0f;
    posit32_t sum_posit = convertFloatToP32(0.0f);

    for (int i = 0; i < 1000000; ++i) {
        float value = 1e-6f;
        posit32_t value_posit = convertFloatToP32(value);

        sum_float += value;
        sum_posit = p32_add(sum_posit, value_posit);
    }

    std::cout << "Float summation result: " << sum_float << "\n";
    std::cout << "Posit summation result: " << convertP32ToDouble(sum_posit) << "\n";
}

void large_dataset_test() {
    float sum_float = 0.0f;
    posit32_t sum_posit = convertFloatToP32(0.0f);

    for (int i = 0; i < 10000000; ++i) {
        float value = 1e-6f;
        posit32_t value_posit = convertFloatToP32(value);

        sum_float += value;
        sum_posit = p32_add(sum_posit, value_posit);
    }

    std::cout << "Float large dataset summation result: " << sum_float << "\n";
    std::cout << "Posit large dataset summation result: " << convertP32ToDouble(sum_posit) << "\n";
}

void division_test() {
    float a = 1.0f, b = 3.0f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a / b;
    posit32_t posit_result = p32_div(a_posit, b_posit);

    std::cout << "Float division result: " << float_result << "\n";
    std::cout << "Posit division result: " << convertP32ToDouble(posit_result) << "\n";
}

void division_by_zero_test() {
    float a = 1.0f, b = 0.0f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a / b;
    posit32_t posit_result = p32_div(a_posit, b_posit);

    std::cout << "Float division by zero result: " << float_result << "\n";
    std::cout << "Posit division by zero result: " << convertP32ToDouble(posit_result) << "\n";
}

void overflow_test() {
    float large = 1e38f, small = 1e-38f;
    posit32_t large_posit = convertFloatToP32(large);
    posit32_t small_posit = convertFloatToP32(small);

    float float_result = large * large;
    posit32_t posit_result = p32_mul(large_posit, large_posit);

    std::cout << "Float overflow result: " << float_result << "\n";
    std::cout << "Posit overflow result: " << convertP32ToDouble(posit_result) << "\n";
}

void error_analysis_test() {
    float a = 1e10f, b = 1e-10f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a + b;
    posit32_t posit_result = p32_add(a_posit, b_posit);

    double posit_as_float = convertP32ToDouble(posit_result);
    double relative_error = std::abs(float_result - posit_as_float) / std::abs(float_result);

    std::cout << "Relative error between float and posit: " << relative_error << "\n";
}

void iterative_precision_test() {
    float sum_float = 0.0f;
    posit32_t sum_posit = convertFloatToP32(0.0f);

    for (int i = 0; i < 1000000; ++i) {
        float value = 1e-6f;
        posit32_t value_posit = convertFloatToP32(value);

        sum_float += value;
        sum_posit = p32_add(sum_posit, value_posit);
    }

    std::cout << "Float iterative summation result: " << sum_float << "\n";
    std::cout << "Posit iterative summation result: " << convertP32ToDouble(sum_posit) << "\n";
}

void edge_case_test() {
    float small_float = 1e-38f, large_float = 1e38f;
    posit32_t small_posit = convertFloatToP32(small_float);
    posit32_t large_posit = convertFloatToP32(large_float);

    std::cout << "Small float: " << small_float << "\n";
    std::cout << "Small posit: " << convertP32ToDouble(small_posit) << "\n";
    std::cout << "Large float: " << large_float << "\n";
    std::cout << "Large posit: " << convertP32ToDouble(large_posit) << "\n";
}

void multiplication_test() {
    float a = 1e5f, b = 1e-5f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a * b;
    posit32_t posit_result = p32_mul(a_posit, b_posit);

    std::cout << "Float multiplication result: " << float_result << "\n";
    std::cout << "Posit multiplication result: " << convertP32ToDouble(posit_result) << "\n";
}

void subtraction_test() {
    float a = 1e10f, b = 1e-10f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a - b;
    posit32_t posit_result = p32_sub(a_posit, b_posit);

    std::cout << "Float subtraction result: " << float_result << "\n";
    std::cout << "Posit subtraction result: " << convertP32ToDouble(posit_result) << "\n";
}

void trigonometric_test() {
    float angle = 0.5f; // Radians
    posit32_t angle_posit = convertFloatToP32(angle);

    float float_result = std::sin(angle);
    posit32_t posit_result = convertFloatToP32(std::sin(convertP32ToDouble(angle_posit)));

    std::cout << "Float sine result: " << float_result << "\n";
    std::cout << "Posit sine result: " << convertP32ToDouble(posit_result) << "\n";
}

void randomized_stress_test() {
    std::srand(std::time(0));
    float sum_float = 0.0f;
    posit32_t sum_posit = convertFloatToP32(0.0f);

    for (int i = 0; i < 100000; ++i) {
        float value = static_cast<float>(std::rand()) / RAND_MAX;
        posit32_t value_posit = convertFloatToP32(value);

        sum_float += value;
        sum_posit = p32_add(sum_posit, value_posit);
    }

    std::cout << "Float randomized summation result: " << sum_float << "\n";
    std::cout << "Posit randomized summation result: " << convertP32ToDouble(sum_posit) << "\n";
}

void matrix_multiplication_test() {
    float matrix_float[2][2] = {{1.0f, 2.0f}, {3.0f, 4.0f}};
    posit32_t matrix_posit[2][2] = {
        {convertFloatToP32(1.0f), convertFloatToP32(2.0f)},
        {convertFloatToP32(3.0f), convertFloatToP32(4.0f)}};

    float result_float[2][2] = {0};
    posit32_t result_posit[2][2] = {convertFloatToP32(0.0f)};

    // Perform matrix multiplication for float
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result_float[i][j] += matrix_float[i][k] * matrix_float[k][j];
            }
        }
    }

    // Perform matrix multiplication for posit
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result_posit[i][j] = p32_add(
                    result_posit[i][j],
                    p32_mul(matrix_posit[i][k], matrix_posit[k][j]));
            }
        }
    }

    std::cout << "Float matrix multiplication result: " << result_float[0][0] << ", " << result_float[0][1] << ", "
              << result_float[1][0] << ", " << result_float[1][1] << "\n";
    std::cout << "Posit matrix multiplication result: " << convertP32ToDouble(result_posit[0][0]) << ", "
              << convertP32ToDouble(result_posit[0][1]) << ", " << convertP32ToDouble(result_posit[1][0]) << ", "
              << convertP32ToDouble(result_posit[1][1]) << "\n";
}

int main() {
    benchmark();
    accuracy_test();
    precision_loss_test();
    summation_test();
    large_dataset_test();
    division_test();
    overflow_test();
    error_analysis_test();
    iterative_precision_test();
    edge_case_test();
    multiplication_test();
    subtraction_test();
    trigonometric_test();
    division_by_zero_test();
    randomized_stress_test();
    matrix_multiplication_test();
    return 0;
}