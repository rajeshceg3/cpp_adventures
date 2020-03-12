#include <assert.h>
#include <regex>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> fetch_valid_reg(const string& test)
{
   std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
   std::smatch match;
   vector<string> tokens;
   
   for(auto index = std::sregex_iterator(std::begin(test), std::end(test), rx); 
       index != std::sregex_iterator(); ++index) 
   {
      if((*index)[1].matched)
         tokens.emplace_back(index->str());
   }
   return tokens;
}

int main()
{
   std::vector<std::string> label = {"XYZ-AB 123", "ABC-DE 1234", "XYZ-WW 0001"};
   std::string test = "XYZ-AB 123qwe-ty 1234  ABC-DE 123456..XYZ-WW 0001";
   assert(label == fetch_valid_reg(test));
}
