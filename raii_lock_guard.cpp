#include <iostream>
#include <mutex>
#include <thread>

// Global mutex
std::mutex g_mutex;

// Function executed by multiple threads
void print()
{
  my_mutex.lock();
  std::cout << "Printing from thread "<<std::this_thread::get_id()<<"\n";
  my_mutex.unlock();
}

// Sync with lock guard, lock_guard
// consturctor & destructor takes care of locking & unlocking mutex
void raii_print()
{
  std::lock_guard<std::mutex> lg(g_mutex);
  std::cout << "Printing from thread "<<std::this_thread::get_id()<<"\n";
}

int main() {
  // Manual locking and unlocking
  std::thread t1(print);
  std::thread t2(print);
  t1.join();
  t2.join();

  // RAII based mutex sync
  std::thread t3(raii_print);
  std::thread t4(raii_print);
  t3.join();
  t4.join();

  return 0;
}
