#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

int g_bool = false;
using namespace std;
void threadfn(condition_variable& condvar){
        this_thread::sleep_for(chrono::milliseconds(500));
        g_bool = true;
        condvar.notify_all();
    }


int main(){
    condition_variable condvar;
    mutex mutexvar;
    unique_lock<mutex> ulock(mutexvar);
    thread newThread(threadfn,ref(condvar));

    condvar.wait(ulock);
    if(g_bool)
        cout<<"Condition activated\n";

    if (newThread.joinable())
        newThread.join();
}
