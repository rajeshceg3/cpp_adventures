#include <iostream>
#include "json.hh"

using namespace std;
using namespace JSON;

int main(int argc, char** argv)
{
    // Read JSON from a string
    Value v = parse_string(<your_json_string>);
    cout << v << endl;

    // Read JSON from a file
    v = parse_file("<your_json_file>.json");
    cout << v << endl;

    // Or build the object manually
    Object obj;

    obj["foo"] = true;
    obj["bar"] = 3;

    Object o;
    o["given_name"] = "John";
    o["family_name"] = "Boags";

    obj["baz"] = o;

    Array a;
    a.push_back(true);
    a.push_back("asia");
    a.push_back("europe");
    a.push_back(55);

    obj["test"] = a;

    cout << o << endl;

    return 0;
}
