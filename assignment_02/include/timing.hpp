#pragma once
#include <chrono>

template <typename Func>
double measure_ms(Func&& f) {
    const auto start = std::chrono::steady_clock::now();
    f();
    const auto stop = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(stop - start).count();
}
