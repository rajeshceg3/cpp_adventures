#include <benchmark/benchmark.h>
#include <limits>
#include <vector>
#include <cstdlib>

std::vector<int> rng(int begin, int end, int count) 
{
  std::vector<int> v;
  v.reserve(count);
  for (int i = 0; i < count; i++) 
	v.emplace_back((std::rand() % end) + begin);

  return v;
}

static void cacheAccess(benchmark::State &s) 
{
  // Get the size from the input
  int bytes = 1 << s.range(0);

  // Share the size between data and indices
  int count = (bytes / sizeof(int) / 2);

  // Initialize this vector with random values
  std::vector<int> v;
  for (auto i : rng(std::numeric_limits<int>::min(),
                    std::numeric_limits<int>::max(), count)) 
    v.emplace_back(i);
  

  // Initialize this vector with random indices
  std::vector<int> indices;
  for (auto i : rng(0, count, count)) 
    indices.emplace_back(i);
  

  // Randomly access values using the indices
  while (s.KeepRunning()) 
  {
    long sum = 0;
    for (int i : indices) 
      sum += v[i];
    // Ensure sum isn't optimized out
    benchmark::DoNotOptimize(sum);
  }

  // We can set the number of bytes we have processed
  s.SetBytesProcessed(long(s.iterations()) * long(bytes));
  // Insert a custom label
  s.SetLabel(std::to_string(bytes / 1024) + "kb");
}
// Register the benchmark
// DenseRange => Generate set of inputs
// ReportAggregatesOnly => Limits output
BENCHMARK(cacheAccess)->DenseRange(13, 26)->ReportAggregatesOnly(true);
BENCHMARK_MAIN();

// Supply -lbenchmark -lpthread flags to gcc while creating executable
