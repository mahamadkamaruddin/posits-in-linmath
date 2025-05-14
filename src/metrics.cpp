#include <iostream>
#include <chrono>
#include "linmath.h"
#include "linmath_posit.h"
#include "/workspaces/posits-in-linmath/softposit_cpp/include/softposit.h"

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

void division_test() {
    float a = 1.0f, b = 3.0f;
    posit32_t a_posit = convertFloatToP32(a);
    posit32_t b_posit = convertFloatToP32(b);

    float float_result = a / b;
    posit32_t posit_result = p32_div(a_posit, b_posit);

    std::cout << "Float division result: " << float_result << "\n";
    std::cout << "Posit division result: " << convertP32ToDouble(posit_result) << "\n";
}

int main() {
    benchmark();
    accuracy_test();
    precision_loss_test();
    summation_test();
    division_test();
    return 0;
}