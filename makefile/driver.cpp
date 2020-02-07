#include <iostream>
#include "sampleClass.h"
using namespace std;

void print_vector1(vector1 v)
{
    cout << "Start x: " << v.start_x << ", Start y: " << v.start_y << endl;
    cout << "End x: " << v.end_x << ", End y: " << v.end_y << endl;
}

int main()
{
    vector1 single_object;
    single_object.start_x = 1.0;
    single_object.start_y = 2.0;
    single_object.end_x = 3.0;
    single_object.end_y = 4.0;
    print_vector1(single_object);
    single_object.print();

    vector2 multiple_objects_1;
    multiple_objects_1.start.x = 1.0;
    multiple_objects_1.start.y = 2.0;
    multiple_objects_1.end.x = 3.0;
    multiple_objects_1.end.y = 4.0;
    vector2 multiple_objects_2 = multiple_objects_1;

    return 0;
}
