#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


using namespace std;
/*
void threadfn( int m,int& n){
    cout << n++ <<" " << m++<< endl;
 }
 */

int main()
{
    mutex mtx;
    int localvalue1 = 100;
    int localvalue2 = 200;
    cout << "Thread id in main = " << this_thread::get_id() << endl;
    thread t1([](int m, int&n){ cout << n++ <<" " << m++<< endl;cout << "Thread id inside thread = " << this_thread::get_id() << endl;
}, localvalue1, ref(localvalue2));
    /*
    if (t1.joinable()){
        t1.join();
    }
    */
    t1.join();
    cout << "Value in main function localvalue1: " << localvalue1 << endl;
    cout << "Value in main function localvalue2: " << localvalue2 << endl;
    return 0;
