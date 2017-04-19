#include <benchmark/benchmark.h>

#include <vector>

void BM_vector_add_ints(benchmark::State &state) {
    std::vector<int> ivector;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        for (auto i : arr) {
            ivector.push_back(i);
        }
    }
}

BENCHMARK(BM_vector_add_ints);

void BM_vector_copy(benchmark::State &state) {
    std::vector<int> ivector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        auto other = ivector;
        (void)other;
    }
}

BENCHMARK(BM_vector_copy);

void BM_vector_copy_one(benchmark::State &state) {
    std::vector<int> ivector = {0};
    while (state.KeepRunning()) {
        auto other = ivector;
        (void)other;
    }
}

BENCHMARK(BM_vector_copy_one);
