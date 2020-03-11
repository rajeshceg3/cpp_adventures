#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <class Iter>
std::string merge_strings(Iter begin, Iter end,const char* delimiter)
{
   std::ostringstream os;
   std::copy(begin, end-1, std::ostream_iterator<std::string>(os, delimiter));
   os << *(end-1);
   return os.str();
}

template <class Container>
std::string merge_strings(const Container& c, const char* delimiter)
{
   if (c.size() == 0) return {};
   return merge_strings(std::begin(c), std::end(c), delimiter);
}

int main()
{
   std::vector<std::string> vec1 = { "A","set","of","separate","tokens" };
   std::vector<std::string> vec2 = { "Lonely" };
   std::vector<std::string> vec3 = { };
   
   std::cout<<merge_strings(vec1," ")<<"\n";
   std::cout<<merge_strings(vec2," ")<<"\n";
   std::cout<<merge_strings(vec3," ");   
   return 0;
}
