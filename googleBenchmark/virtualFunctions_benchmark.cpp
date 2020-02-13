#include <benchmark/benchmark.h>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

struct Animal {
  virtual int getValue(){ return 10; }
};

struct Racoon : Animal {
  virtual int getValue() override { return 20; }
};

struct Horse : Animal {
  virtual int getValue() override { return 30; }
};

static void organizedForest(benchmark::State& s)
{
  vector<Animal*> forest;
  fill_n(back_inserter(forest), 10000, new Animal());
  fill_n(back_inserter(forest), 10000, new Racoon());
  fill_n(back_inserter(forest), 10000, new Horse());
  int sum = 0;

  for( auto _ : s)
  {
    for (auto* animal : forest) 
      sum += animal->getValue();
  }
}
BENCHMARK(organizedForest);

static void shuffledForest(benchmark::State& s) {

  vector<Animal*> forest;
  fill_n(back_inserter(forest), 10000, new Animal);
  fill_n(back_inserter(forest), 10000, new Racoon);
  fill_n(back_inserter(forest), 10000, new Horse);

  // Shuffle forest randomly, use merenne-twister rng
  random_device rd;
  mt19937 mt(rd());
  shuffle(forest.begin(), forest.end(), mt);


  int sum = 0;
  for( auto _ : s) 
  {
	// Branch predictor efficiency will take a hit,as the
	// objects are shuffled randomly
    for (auto* animal : forest) 
      sum += animal->getValue();    
  }
}
BENCHMARK(shuffledForest);

// Main function
BENCHMARK_MAIN();
