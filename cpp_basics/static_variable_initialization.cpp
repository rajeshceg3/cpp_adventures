#include <iostream>
using namespace std;

struct Painting{
static int paint_color_int;

};
// without the following line, linker error
// will be thrown

int Painting::paint_color_int = 5;

int main()
{
    cout<< Painting::paint_color_int;
}

// https://wandbox.org/permlink/3clQXFGURQPT6NBf
