#include <iostream>

#pragma pack(1)
# Enforcing 16 byte alignment with alignas
struct alignas(16) SimpleStruct {
    uint16_t data1;
    uint64_t data2;
};
#pragma pack()

int main()
{
    SimpleStruct s;
    std::cout << "addr: " << &s << "\n";
    std::cout << "size: " << sizeof(SimpleStruct) << "\n";
}
