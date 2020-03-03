#include <iostream>
#include <array>
#include <sstream>
#include <assert.h>

class IPAddr
{
   std::array<unsigned char, 4> data;
public:
   constexpr IPAddr():data{}{} 
   constexpr IPAddr( const unsigned char a, const unsigned char b, 
                     const unsigned char c, const unsigned char d):data{a,b,c,d} {}
   IPAddr(const IPAddr& other) noexcept : data(other.data) {}
   IPAddr& operator=(const IPAddr& other) noexcept 
   {
      data = other.data;
      return *this;
   }

   // Provide conversion to string using strtingstream class
   std::string to_string() const
   {
      std::ostringstream oss;
      oss << *this;
      return oss.str();
   } 

    // Add stream support for our class
   friend std::ostream& operator<<(std::ostream& ost, const IPAddr& a)
   {
      ost << static_cast<uint16_t>(a.data[0]) << '.' 
         << static_cast<uint16_t>(a.data[1]) << '.'
         << static_cast<uint16_t>(a.data[2]) << '.'
         << static_cast<uint16_t>(a.data[3]);
      return ost;
   }

   friend std::istream& operator>>(std::istream& ist, IPAddr& a)
   {
      char d1, d2, d3;
      int b1, b2, b3, b4;
      ist >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
      if (d1 == '.' && d2 == '.' && d3 == '.')
         a = IPAddr(b1, b2, b3, b4);
      else
         ist.setstate(std::ios_base::failbit);

      return ist;
   }
};

int main()
{
   IPAddr a(168, 192, 0, 1);
   std::cout << a <<"\n";
   
   // Use Copy constructor and assignment operator
   IPAddr b = a;
   IPAddr c;
   c = b;

   // Receive an ip address from input via istream
   std::cout<<"Please enter a valid IP Address \n";
   IPAddr ip;
   std::cin >> ip;
   
   // Validate input with failbit status
   if(!std::cin.fail())
      std::cout << ip << std::endl;
}
