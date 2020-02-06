#include <iostream>
using namespace std;

class Base{
public:
     virtual void show();
};
void Base::show(){
    cout << "Base::show" << endl;
}
class Derived: public Base {
public:
     void show();
};
void Derived::show(){
    cout<< "Derived::show"<<endl;
}

void printshow(Base* b){
    Derived* dptr = dynamic_cast<Derived*> (b);

    if (NULL != dptr )
        dptr->show();
    else
        cout<<"Dynamic cast returned null"<<endl;

}

int main(){
    Base* b = new Base();
    Derived *d = new Derived();
    // Call printshow with base object
    // with show method marked as virtual
    printshow(b);
}
