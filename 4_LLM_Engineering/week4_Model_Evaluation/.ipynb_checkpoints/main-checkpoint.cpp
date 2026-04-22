#include <cstdio>
#include <chrono>
#include <cstdint>

#if defined(__clang__)
#pragma clang fp push
#pragma clang fp reassociate(off)
#endif
static inline double calculate_general(uint32_t iterations, int param1, int param2) noexcept {
    double result = 1.0;
    const double p1 = static_cast<double>(param1);
    const double p2 = static_cast<double>(param2);

    uint32_t i = 1;
    const uint32_t limit = iterations & ~3u; // multiple of 4

    for (; i <= limit; i += 4) {
        double base = p1 * static_cast<double>(i);
        result -= 1.0 / (base - p2);
        result += 1.0 / (base + p2);

        base += p1;
        result -= 1.0 / (base - p2);
        result += 1.0 / (base + p2);

        base += p1;
        result -= 1.0 / (base - p2);
        result += 1.0 / (base + p2);

        base += p1;
        result -= 1.0 / (base - p2);
        result += 1.0 / (base + p2);
    }
    for (; i <= iterations; ++i) {
        double base = p1 * static_cast<double>(i);
        result -= 1.0 / (base - p2);
        result += 1.0 / (base + p2);
    }
    return result;
}
#if defined(__clang__)
#pragma clang fp pop
#endif

#if defined(__clang__)
#pragma clang fp push
#pragma clang fp reassociate(off)
#endif
static inline double calculate_special_4_1(uint32_t iterations) noexcept {
    double result = 1.0;
    double d = 3.0; // starts at 4*1 - 1
    uint32_t i = 0;
    const uint32_t limit = iterations & ~7u; // multiple of 8

    for (; i < limit; i += 8) {
        double t = d;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        result -= 1.0 / t;         result += 1.0 / (t + 2.0);  t += 4.0;
        d = t;
    }
    for (; i < iterations; ++i) {
        result -= 1.0 / d;
        result += 1.0 / (d + 2.0);
        d += 4.0;
    }
    return result;
}
#if defined(__clang__)
#pragma clang fp pop
#endif

int main() {
    using clock = std::chrono::high_resolution_clock;

    const uint32_t iterations = 200000000u;
    const int param1 = 4;
    const int param2 = 1;

    auto start = clock::now();

    double result;
    if (param1 == 4 && param2 == 1) {
        result = calculate_special_4_1(iterations) * 4.0;
    } else {
        result = calculate_general(iterations, param1, param2) * 4.0;
    }

    auto end = clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();

    std::printf("Result: %.12f\n", result);
    std::printf("Execution Time: %.6f seconds\n", elapsed);
    return 0;
}