#include <iostream>
#include <thread>

using namespace std;

void threadfn(){
    cout << "Inside thread function"<<endl;
}

int main(){
    thread t1{threadfn};
    if (t1.joinable()){
        t1.join();
    }
    return 0;
}
