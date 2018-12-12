#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
template <class T, int capacity>
class Myvector{
private:
    T  m_pdata[capacity];
    int m_Index;
public:
    Myvector():
        m_Index(0)
    {

    };

    void addtoMyvector( T value){
        if ( m_Index < capacity ){
            m_pdata[m_Index] = value;
            m_Index++;
            cout<<"Data added to my vector "<<value<<endl;
        }
        else
            cerr<< "Capacity exceeded" << endl;
    }

    void printBo(){
        int n = sizeof(m_pdata)/sizeof(m_pdata[0]);
        cout<< "Myvector Contents"<<endl;
        cout<< "Size of Myvector "<<n<<endl;
        int printIndex = 0;
        while(n > 0){
            cout<<m_pdata[printIndex]<<" ";
            n--;
            printIndex++;
        }
    }
};

int main(){
    Myvector<int, 3> bv;
    bv.addtoMyvector(5);
    bv.addtoMyvector(4);
    bv.addtoMyvector(3);
    bv.addtoMyvector(21);
    bv.printBo();
}

