#include <benchmark/benchmark.h>
#include <cstdlib>

static void cacheAssociativity(benchmark::State &s) {
  int stride = 1 << s.range(0);

  // 1 Million elements
  int N = 1 << 20;
  char *a = new char[N];

  // Fill with random values of range 0-99
  for (int i = 0; i < N; i++) 
    a[i] = rand() % 100;

  // Profile with multiple stride sizes
 for( auto _ : s)
 {
    int i = 0;
    for (int iter = 0; iter < 10000; iter++) 
	{
	  // Increment an int and wrap to beginning of array	
      a[i]++;      
      i = (i + stride) % N;
    }
  }

  // Release memory
  delete[] a;
}
// Register the benchmark
BENCHMARK(cacheAssociativity)->DenseRange(0, 16)->Unit(benchmark::kMicrosecond);
BENCHMARK_MAIN();
