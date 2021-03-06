#include <benchmark/benchmark.h>

#include <set>

void BM_set_add_ints(benchmark::State &state) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        std::set<int> iset;
        for (auto i : arr) {
            iset.insert(i);
        }
    }
}

BENCHMARK(BM_set_add_ints);

void BM_set_copy(benchmark::State &state) {
    std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        auto other = iset;
        (void)other;
    }
}

BENCHMARK(BM_set_copy);

void BM_set_copy_one(benchmark::State &state) {
    std::set<int> iset = {0};
    while (state.KeepRunning()) {
        auto other = iset;
        (void)other;
    }
}

BENCHMARK(BM_set_copy_one);
