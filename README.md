# C++, STL Algorithms and Containers

This repository is a personal collection of C++ code examples covering various topics, including but not limited to STL algorithms and containers. It is intended for learning, practice, and reference.

The code examples provided here are for illustrative purposes and may not always represent the most optimal or production-ready solutions. Users are encouraged to explore further and adapt the code to their specific needs.

## Categories

Here's a breakdown of the categories of C++ examples you can find in this repository:

- **Algorithms**: Illustrates fundamental algorithms such as sorting, searching, and recursion, providing practical implementations and explanations.
- **Data Structures**: Contains examples of custom data structures like vectors, linked lists, and matrices, demonstrating their implementation and usage.
- **C++17 Features**: Explores modern C++17 features including `std::optional`, `std::variant`, filesystem manipulation, and structured bindings with concise examples.
- **Concurrency and Multithreading**: Covers the basics of concurrent programming in C++ using mutexes, condition variables, threads, and asynchronous operations.
- **Networking**: Provides examples of network programming, including TCP server/client implementations and usage of libraries like Boost.Asio and ZeroMQ.
- **Qt**: Includes basic examples to get started with Qt for building graphical user interfaces.
- **CUDA**: Offers introductory programs for parallel computing using NVIDIA CUDA.
- **Benchmarking**: Demonstrates how to measure code performance using tools like Google Benchmark and `std::chrono`.
- **C++ Basics & Core Concepts**: Focuses on fundamental C++ language features, object-oriented programming (OOP), optimization techniques, templates, JSON handling, and regular expressions.
- **STL (Standard Template Library)**: Showcases the use of various STL components like algorithms, containers, and iterators to write efficient and expressive C++.

## How to Compile and Run

Most of the examples in this repository are single C++ files and can be compiled using a standard C++ compiler like g++. You will need a compiler that supports C++17.

For a typical single-file example, you can compile it using a command similar to this:

```bash
g++ -std=c++17 filename.cpp -o output_name
```

Replace `filename.cpp` with the actual name of the source file and `output_name` with your desired executable name.

Some examples may have specific dependencies on external libraries such as:

- Boost
- Qt
- CUDA
- ZeroMQ
- Google Benchmark

If an example requires such libraries, you will need to have them installed on your system. The specific installation process for these libraries varies depending on your operating system and package manager. Please refer to the official documentation for each library for installation instructions.

For more complex examples or those involving multiple files, a `CMakeLists.txt` or other build system configuration file may be provided in the future.

## Contributing

Contributions to this repository are welcome! Whether you want to add new examples, improve existing code, fix bugs, or enhance documentation, your input is valuable.

Here are some ways you can contribute:

- **Add New Examples**: If you have a C++ example that fits within the scope of this repository and demonstrates a useful concept or feature, feel free to suggest it.
- **Improve Existing Code**: You can help by making existing code clearer, more efficient, or by updating it to showcase newer C++ features.
- **Fix Bugs**: If you find any bugs in the code, please report them or submit a fix.
- **Improve Documentation or Comments**: Enhancements to the README, code comments, or example explanations are always appreciated.

To ensure a smooth process, please **open an issue first** to discuss any potential changes or additions you'd like to make. This allows for discussion and coordination before you invest time in development.
