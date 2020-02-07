#include <benchmark/benchmark.h>
#include <vector>
#include <string>
using namespace std;

static void stringOptimization(benchmark::State &s)
{
    int len = s.range(0);
    vector<string> vec;
    vec.reserve(100000);
    for(auto _ : s)
	{
        for(int i = 0; i < 100000; i++)
		{
			// Construct string of specified length
            string str(len, 's');
            vec.emplace_back(str);
        }
    }
}
BENCHMARK(stringOptimization)->DenseRange(0,32)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();
