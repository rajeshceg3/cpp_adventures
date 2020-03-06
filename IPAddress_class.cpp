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

    // Convert IP address to numeric form
   constexpr unsigned long to_numeric() const noexcept
   {
      return
         (static_cast<unsigned long>(data[0]) << 24) |
         (static_cast<unsigned long>(data[1]) << 16) |
         (static_cast<unsigned long>(data[2]) << 8) |
         static_cast<unsigned long>(data[3]);
   }

    // Operations which help us identify additional info about
    // the ip address class details we are dealing with
   constexpr bool is_loopback() const noexcept
   {
      return (to_numeric() & 0xFF000000) == 0x7F000000;
   }

   constexpr bool is_unspecified() const noexcept
   {
      return to_numeric() == 0;
   }

   constexpr bool is_class_a() const noexcept
   {
      return (to_numeric() & 0x80000000) == 0;
   }

   constexpr bool is_class_b() const noexcept
   {
      return (to_numeric() & 0xC0000000) == 0x80000000;
   }

   constexpr bool is_class_c() const noexcept
   {
      return (to_numeric() & 0xE0000000) == 0xC0000000;
   }

   constexpr bool is_multicast() const noexcept
   {
      return (to_numeric() & 0xF0000000) == 0xE0000000;
   }
   
   
   friend bool operator==(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return IP1.data == IP2.data;
   }

   friend bool operator!=(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return !(IP1 == IP2);
   }

   friend bool operator<(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return IP1.to_numeric() < IP2.to_numeric();
   }

   friend bool operator>(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return IP2 < IP1;
   }

   friend bool operator<=(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return !(IP1 > IP2);
   }

   friend bool operator>=(IPAddr const & IP1, IPAddr const & IP2) noexcept
   {
      return !(IP1 < IP2);
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
   IPAddr addr(168, 192, 0, 1);
   std::cout << addr <<"\n";
   
   // Use Copy constructor and assignment operator
   IPAddr b = addr;
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
