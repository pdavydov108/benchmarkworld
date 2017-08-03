#include <benchmark/benchmark.h>

#include <cstdio>
#include <fstream>

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

void BM_file_read_1M(benchmark::State &state) {
    std::vector<char> buffer(1024 * 1024, 0);
    {
        std::fstream f("text");
        f.write(buffer.data(), buffer.size());
    }
    std::ios::sync_with_stdio(false);
    while (state.KeepRunning()) {
        std::fstream f("text");
        f.read(buffer.data(), buffer.size());
    }
    remove("text");
}
BENCHMARK(BM_file_read_1M);

void BM_cfile_open_close(benchmark::State &state) {
    while (state.KeepRunning()) {
        if (auto f = std::fopen("main.cpp", "r")) {
            fclose(f);
        }
    }
}
BENCHMARK(BM_cfile_open_close);
