#include <benchmark/benchmark.h>

#include <deque>
#include <chrono>

void BM_deque_add_ints(benchmark::State &state) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        std::deque<int> ideque;
        for (auto i : arr) {
            ideque.push_back(i);
        }
    }
}

BENCHMARK(BM_deque_add_ints);

void BM_deque_copy(benchmark::State &state) {
    std::deque<int> ideque = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (state.KeepRunning()) {
        auto other = ideque;
        (void)other;
    }
}

BENCHMARK(BM_deque_copy);

using namespace std::chrono;
void BM_deque_insert_middle(benchmark::State &state) {
    std::deque<int> ideque(2000, 0);
    while (state.KeepRunning()) {
        auto other = ideque;
        auto begin = high_resolution_clock::now();
        other.insert(std::next(other.begin(), 50), 0);
        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<duration<double>>(end - begin);
        state.SetIterationTime(elapsed.count());
    }
}

BENCHMARK(BM_deque_insert_middle)->UseManualTime();

struct Data {
    int a = 0;
    std::string b = "some";
};
void BM_deque_insert_middle_struct(benchmark::State &state) {
    std::deque<Data> ideque(2000);
    while (state.KeepRunning()) {
        auto other = ideque;
        auto begin = high_resolution_clock::now();
        other.insert(std::next(other.begin(), 50), Data{});
        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<duration<double>>(end - begin);
        state.SetIterationTime(elapsed.count());
    }
}

BENCHMARK(BM_deque_insert_middle_struct)->UseManualTime();
