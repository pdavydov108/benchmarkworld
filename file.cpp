#include <benchmark/benchmark.h>

#include <fstream>
#include <cstdio>

void BM_file_open_close(benchmark::State &state) {
    std::ios::sync_with_stdio(true);
    while (state.KeepRunning()) {
        std::fstream f("main.cpp");
    }
}
BENCHMARK(BM_file_open_close);

void BM_file_open_close_no_sync(benchmark::State &state) {
    std::ios::sync_with_stdio(false);
    while (state.KeepRunning()) {
        std::fstream f("main.cpp");
    }
}
BENCHMARK(BM_file_open_close_no_sync);

void BM_cfile_open_close(benchmark::State &state) {
    while (state.KeepRunning()) {
        auto f = std::fopen("main.cpp", "r");
        fclose(f);
    }
}
BENCHMARK(BM_cfile_open_close);
