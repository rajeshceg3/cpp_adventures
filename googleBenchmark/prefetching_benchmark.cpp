#include <benchmark/benchmark.h>
#include <cstdlib>

// Access array elements in row major fashion
static void rowMajorAccess(benchmark::State &s) {
  // Create an array of 1M * 1M elements
  int N = 1 << 20;
  int *collection = new int[N * N];

  // Traverse the array 
  for ( auto _ : s) 
  {
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
        collection[i * N + j] += j;      
  }
}
BENCHMARK(rowMajorAccess)->Unit(benchmark::kMillisecond);

// Access array elements in column major fashion
static void columnMajorAccess(benchmark::State &s) {
  // Create an array of 1M * 1M elements
  int N = 1 << 20;
  int *collection = new int[N * N];

  // Traverse the array 
   for ( auto _ : s)  
   {
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
        collection[j * N + i] += j;
   }	
}
// Register the benchmark
BENCHMARK(columnMajorAccess)->Unit(benchmark::kMillisecond);

// Accesses an array fairly randomly
static void randomStep(benchmark::State &s) {
  // Create an array of 1M * 1M elements
  int N = 1 << 20;
  int *collection = new int[N * N];

  // Traverse the array 
  for ( auto _ : s)
  {
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
        collection[j * N + rand() % N] += j;      
  }
}
// Register the benchmark
BENCHMARK(randomStep)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();
