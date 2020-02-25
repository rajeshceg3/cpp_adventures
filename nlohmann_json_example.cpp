 #include <json.hpp>
 using namespace nlohmann;
 using std::cout;

 int main()
 {
     // create JSON object
     json object =
     {
         {"key1", "value1"},
         {"key2", "value2"},
         {"key3", "value3"}
     };

	    // Access value for key1
     cout << object.at("key1") << '\n';

     // Change value for key2
     object.at("key2") = "new value";

     // Display the array using stream insertion operator
     cout << object << '\n';

     // Example for invalid access
     try
     {
         object.at("key4") = "bad attempt";
     }
     catch (std::out_of_range& e)
     {
         cout << "Invalid access: " << e.what() << '\n';
     }
 }
