# Algorithms
## Sub-features
Bubble-sort demonstration, quicksort, GCD, recursive binary search.
## How to get to it (user POV)
Compile the individual source in Algorithms/ or simple_gcd.cpp, then run the executable. Binary-search main chooses random inputs; the function can be called directly from C++.
## Driving it with drive.py
Run drive. Assert sorted demonstration outputs, GCD4 and real binary-search returns for both ends, middle, absent value and empty range.
## Gotchas
Algorithms/fibonacci_memoization.cpp is not executed: source has a value-search instead of index cache check, memo sizing and small-n boundary issues, int overflow at the demonstration input50 and an exponential naive call. These remain unverified/unfixed, not a passing algorithm. Other data structures and algorithms are not covered by this bounded seed.
