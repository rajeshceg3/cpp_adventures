#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    vector<string> tokens;
    string str = "This is a string we want to tokenize";
    stringstream iss(str);
    copy(istream_iterator<string> (iss),
         istream_iterator<string> (),
         back_inserter(tokens));
    
     cout << "Extracted tokens "<< endl;     
     copy(begin(tokens),end(tokens),ostream_iterator<string>(cout, "\n"));
}
