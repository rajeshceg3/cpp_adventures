#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::literals::chrono_literals;

struct Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;
        cout<<"Time spent in function = "<<duration.count()<<"\n";
    }
};

void functionToMeasure(){
    Timer tp;
    for(int index = 0;index < 10;index++){
        std::this_thread::sleep_for(100ms);
    }
}

int main(){
    functionToMeasure();
}
