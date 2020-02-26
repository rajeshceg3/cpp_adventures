#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> v1;
  cout << "Vector size    : " << v1.size() << "\n";
  cout << "Vector capacity: " << v1.capacity() << "\n";
  v1.push_back(10);
  v1.emplace_back(20); // in-place construction

  // See the new values of size and capacity after inserting two elements
  cout << "Vector size 2 elements    : " << v1.size() << "\n";
  cout << "Vector capacity 2 elements: " << v1.capacity() << "\n";

  // Push one more element and observe the result
  v1.push_back(3);
  cout << "Vector size 3 elements    : " << v1.size() << "\n";
  cout << "Vector capacity 3 elements: " << v1.capacity() << "\n";

  // Allocate in oneshot if we know the size in advance, single heap allocation
  v1.reserve(100);
  cout << "Vector size after reserve(100)    : " << v1.size() << "\n";
  cout << "Vector capacity reserve(100)      : " << v1.capacity() << "\n";

  // Remove space if we have allocated excess memory
  v1.shrink_to_fit();
  cout << "Vector size after shrink_to_fit    : " << v1.size() << "\n";
  cout << "Vector capacity after shrink_to_fit: " << v1.capacity() << "\n";

  // We can also resize the container, which can change both the size and
  // capacity
  v1.resize(10, 5);
  cout << "Vector size after resize(10, 5)    : " << v1.size() << "\n";
  cout << "Vector capacity after resize(10, 5): " << v1.capacity() << "\n";

  // Range based for loop for easily iterating a vector
  for (const auto& i : v1) cout << i << " ";
  cout << "\n";

  // If resize gets smaller value, vector content gets sliced out
  v1.resize(5);
  cout << "Vector size after resize(5)    : " << v1.size() << "\n";
  cout << "Vector capacity after resize(5): " << v1.capacity() << "\n";
  for (auto i : v1) cout << i << " ";
  cout << "\n";

  // Remove last element
  v1.pop_back();
  cout << "Vector size    : " << v1.size() << "\n";
  cout << "Vector capacity: " << v1.capacity() << "\n";
  for (auto i : v1) cout << i << " ";
  cout << "\n";

  // Remove element at specific index using an iterator
  v1.erase(begin(v1) +2);
  cout << "Vector size    : " << v1.size() << "\n";
  cout << "Vector capacity: " << v1.capacity() << "\n";
  for (auto i : v1) cout << i << " ";
  cout << "\n";

  // Access with [] operator, it returns a ref to element,
  // hence can be used for assignment of vector elements as well
  cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << ", v1[2] = " << v1[2]
       << "\n";

  // Access elements with at() method
  cout << "v1.at(0) = " << v1.at(0) << ", v1.at(1) = " << v1.at(1)
       << ", v1.at(2) = " << v1.at(2) << "\n";

  return 0;
}
