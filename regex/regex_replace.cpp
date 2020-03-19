#include <iostream>
#include <string>
#include <regex>

int main()
{
   // Usage of capture groups along with regex_replace
   std::string text = "today is 31.12.2019!";
   std::regex rex( R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" );
   std::string result = std::regex_replace(text, rex, R"($5-$3-$1)");	
   std::cout<<result<<"\n";
}
