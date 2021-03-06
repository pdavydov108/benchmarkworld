#include <benchmark/benchmark.h>

#include <list>

void BM_list_add_ints(benchmark::State &state) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        std::list<int> ilist;
        for (auto i : arr) {
            ilist.push_back(i);
        }
    }
}

BENCHMARK(BM_list_add_ints);

void BM_list_copy(benchmark::State &state) {
    std::list<int> ilist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        auto other = ilist;
        (void)other;
    }
}

BENCHMARK(BM_list_copy);
