#include <benchmark/benchmark.h>
#include <iostream>

void strcpy__(char *a, const char *b) {
  while ((*a++ = *b++))
    ;
}

const char *data = "this string is long enough";

static void BM_strcpy__(benchmark::State &state) {
  char arr[256];
  while (state.KeepRunning()) {
    strcpy__(arr, data);
  }
}
BENCHMARK(BM_strcpy__);

static void BM_strcpy__msvc(benchmark::State &state) {
  char arr[256];
  while (state.KeepRunning()) {
    asm volatile(
        "mov      rdx, %0\n\t"
        "sub      rdx, %1\n\t"
        ".LL2strcpy___:\n\t"
        "movzx    eax, BYTE PTR [%1]\n\t"
        "mov     BYTE PTR [rdx+%1], al\n\t"
        "lea      %1, QWORD PTR [%1+1]\n\t"
        "test     al, al\n\t"
        "jne      .LL2strcpy___\n\t"
        : 
        : "r"(arr), "r"(data)
        : "eax", "cc", "rdx");
  }
}

BENCHMARK(BM_strcpy__msvc);
BENCHMARK_MAIN();
