#include <benchmark/benchmark.h>
#include <algorithm>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::fill_n;
using std::vector;

// Struct fits on whole cache line, 64 bytes
struct IntStruct {
  // Struct with a 16 integer fields
  int v0 = 0;
  int v1 = 0;
  int v2 = 0;
  int v3 = 0;
  int v4 = 0;
  int v5 = 0;
  int v6 = 0;
  int v7 = 0;
  int v8 = 0;
  int v9 = 0;
  int v10 = 0;
  int v11 = 0;
  int v12 = 0;
  int v13 = 0;
  int v14 = 0;
  int v15 = 0;

  // Increment the field
  void inc_v0() { v0++; }
};

// Structure of Arrays
struct SoA {
  // Resize vector to store N values
  SoA(int N) 
  {
    v0s.resize(N);
    v1s.resize(N);
    v2s.resize(N);
    v3s.resize(N);
    v4s.resize(N);
    v5s.resize(N);
    v6s.resize(N);
    v7s.resize(N);
    v8s.resize(N);
    v9s.resize(N);
    v10s.resize(N);
    v11s.resize(N);
    v12s.resize(N);
    v13s.resize(N);
    v14s.resize(N);
    v15s.resize(N);
  }

  // Increment a value
  void update_v0() 
  {
    for (auto &i : v0s) 
      i++;
  }

  // Vector of values
  vector<int> v0s;
  vector<int> v1s;
  vector<int> v2s;
  vector<int> v3s;
  vector<int> v4s;
  vector<int> v5s;
  vector<int> v6s;
  vector<int> v7s;
  vector<int> v8s;
  vector<int> v9s;
  vector<int> v10s;
  vector<int> v11s;
  vector<int> v12s;
  vector<int> v13s;
  vector<int> v14s;
  vector<int> v15s;
};

// Object oriented approach
static void ArrayOfStructs(benchmark::State &s) 
{
  int N = 1 << s.range(0);

  vector<IntStruct> v;
  fill_n(back_inserter(v), N, IntStruct());

  // Profile the increment operation
  while (s.KeepRunning())
  {
    for (auto &i : v)
      i.inc_v0();
  }
}
BENCHMARK(ArrayOfStructs)->DenseRange(8, 16);

// Data oriented approach
static void StructOfArrays(benchmark::State &s) 
{
  int N = 1 << s.range(0);
  SoA struct_of_arrays(N);
  
  // Profile the increment operation
  while (s.KeepRunning()) 
    struct_of_arrays.update_v0();
}
BENCHMARK(StructOfArrays)->DenseRange(8, 16);
BENCHMARK_MAIN();
