#include <iostream>
using namespace std;

// Base class 
class Base{
public:
     virtual void show();
};
void Base::show(){
    cout << "Base::show" << endl;
}

// Derived class 
class Derived: public Base {
public:
     void show();
};
void Derived::show(){
    cout<< "Derived::show"<<endl;
}


// printshow method which takes a pointer to base 
void printshow(Base* b){
    // we know that, pointer that is passed is of derived type
    // So, we inititate a dynamic cast, to check whether it is
    // really the case, and whether it can be safely done
    // As this is a downcast, base -> derived, this check is necessary
    // upcast is always safe and guaranteed to succeed
    Derived* dptr = dynamic_cast<Derived*> (b);
    
    // if resulting pointer is not null, then dynamic_cast is success
    if (NULL != dptr )
        dptr->show();
    else
        cout<<"Dynamic cast returned null"<<endl;

}

int main(){
    Base* b = new Base();
    Derived *d = new Derived();
    // Call printshow with derived object
    // Notice that, this call is succeding as base class show is a virtual
    // function, else this will result in failure
    printshow(d);
}
