#include <assert.h>
#include <regex>
#include <string_view>
using std::string_view;

bool verify_vehicle_registration(string_view str)
{
   std::regex rex(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
   return std::regex_match(str.data(), rex);
}

int main()
{
   assert(verify_vehicle_registration("XYZ-MN 123"));
   assert(verify_vehicle_registration("XYZ-MP 9876"));
   assert(!verify_vehicle_registration("XYZ-LRZ 12345"));
   assert(!verify_vehicle_registration("lmn-op 1234"));
   return 0;
}
