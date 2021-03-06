#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void threadFunction(int tid)
 {
	  std::lock_guard<mutex> lock(mtx);
	  std::cout << "Hello from thread - " << tid << endl;
}

int main() 
{
	  std::thread t[10];
	  for (int i = 0; i < 10; i++) 
	  {
		t[i] = std::thread(threadFunction, i);
	  }

	  // Send a print from main thread
	  threadFunction(10);

	  // Wait for threads to complete
	  for (int i = 0; i < 10; i++) 
	  {
		if(t[i].joinable())
			t[i].join();
	  }
	  return 0;
}
