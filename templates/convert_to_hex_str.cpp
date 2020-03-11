#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

template <class Iter>
std::string convert_to_hex_str(Iter begin, Iter end)
{
   std::ostringstream oss;
   for (; begin != end; ++begin)
      oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*begin);
   return oss.str();
}

template <class Container>
std::string convert_to_hex_str(const Container& c)
{
   return convert_to_hex_str(std::begin(c), std::end(c));
}


int main()
{
   std::vector<unsigned char> v = { 0xBC, 0xA2, 0xF1, 0x0D };
   unsigned char buf[5] = {0x11, 0xA2, 0x23, 0x43, 0x55};

   std::cout<<convert_to_hex_str(v)<<"\n";
   std::cout<<convert_to_hex_str(buf)<<"\n";
}
