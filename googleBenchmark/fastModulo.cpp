#include <benchmark/benchmark.h>
#include <random>
#include <vector>
using namespace std;

// Function for generating argument pairs
static void custom_args(benchmark::internal::Benchmark *b) 
{
  for (int i = 1 << 4; i <= 1 << 10; i <<= 2) 
  {
    // Collect stats at 1/8, 1/2, and 7/8
    for (int j : {32, 128, 224}) 
	{
      b = b->ArgPair(i, j);
    }
  }
}

// Baseline for modulo calculation
static void baseModulo(benchmark::State &s) 
{
  // Number of elements & Max for mod operator
  int N = s.range(0);
  int ceil = s.range(1);

  // Vector for input and output of modulo
  vector<int> input;
  vector<int> output;
  input.resize(N);
  output.resize(N);

  // Generate random inputs
  mt19937 rng;
  rng.seed(random_device()());
  uniform_int_distribution<int> dist(0, 255);
  for (int &i : input) 
    i = dist(rng);

  while (s.KeepRunning()) 
  {
    // Compute modulo and save it
    for (int i = 0; i < N; i++) 
      output[i] = input[i] % ceil;
  }
}
// Register the benchmark
BENCHMARK(baseModulo)->Apply(custom_args);

// Baseline for fast modulo operation
static void fastModulo(benchmark::State &s) {
  // Number of elements & Max for mod operator
  int N = s.range(0);
  int ceil = s.range(1);

  // Vector for input and output of modulo
  vector<int> input;
  vector<int> output;
  input.resize(N);
  output.resize(N);

  // Generate random inputs
  mt19937 rng;
  rng.seed(random_device()());
  uniform_int_distribution<int> dist(0, 255);
  for (int &i : input) 
    i = dist(rng);
  
  while (s.KeepRunning()) 
  {
    // Skip the expensive operation using a simple compare
	// Depending on the situation, branch misprediction might
	// actually work against us while taking this approach
	// for the purposes of this benchmarking we are ignoring
	// the effects branch misprediction might have
    for (int i = 0; i < N; i++) 
      output[i] = (input[i] >= ceil) ? input[i] % ceil : input[i];
    
  }
}
// Register the benchmark
BENCHMARK(fastModulo)->Apply(custom_args);
// Benchmark main function
BENCHMARK_MAIN();
