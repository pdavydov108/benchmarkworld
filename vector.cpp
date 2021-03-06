#include <benchmark/benchmark.h>

#include <vector>
#include <chrono>

void BM_vector_add_ints(benchmark::State &state) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        std::vector<int> ivector;
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

using namespace std::chrono;
void BM_vector_insert_middle(benchmark::State &state) {
    std::vector<int> ivector(2000, 0);
    while (state.KeepRunning()) {
        auto other = ivector;
        auto begin = high_resolution_clock::now();
        other.insert(std::next(other.begin(), 50), 0);
        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<duration<double>>(end - begin);
        state.SetIterationTime(elapsed.count());
    }
}

BENCHMARK(BM_vector_insert_middle)->UseManualTime();

struct Data {
    int a = 0;
    std::string b = "some";
};
void BM_vector_insert_middle_struct(benchmark::State &state) {
    std::vector<Data> ivector(2000);
    while (state.KeepRunning()) {
        auto other = ivector;
        auto begin = high_resolution_clock::now();
        other.insert(std::next(other.begin(), 50), Data{});
        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<duration<double>>(end - begin);
        state.SetIterationTime(elapsed.count());
    }
}

BENCHMARK(BM_vector_insert_middle_struct)->UseManualTime();
