#include <iostream>
/*
if constexpr can replace SFINAE in many cases
ie when the condition under if constexpr evaluates
to false, the branch is totally discared, ie not
even considered for compilation
*/
int main()
{
    if constexpr (constexpr int i = 100; i > 0) 
        std::cout<<"Hola\n"; 
    else
        std::cout<<"This branch isn't even gonna compile\n";
}
