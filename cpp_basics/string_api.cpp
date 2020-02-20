#include <iostream> 
#include <string> 

int main()
{
    std::string str("Hello World");

    std::cout << str.front() << "\n";
    std::cout << str.back() << "\n";
    std::cout << str.at(1) << "\n";
    std::cout << str.data() << "\n";
	std::cout << str.size() << "\n";
    std::cout << str.max_size() << "\n";
    std::cout << str.empty() << "\n";
	std::cout << str.substr(0, 5) << "\n";
	
    if (str.compare("Hello World") == 0) 
        std::cout << "Hello World\n";
    

    std::cout << str.compare("Hello") << "\n";
    std::cout << str.compare("World") << "\n";	
	
    str = "Hello this is a test of Hello World";
	
	// Returns the index of corresponding search results
    std::cout << str.find("Hello") << "\n";
    std::cout << str.rfind("Hello") << "\n";
    std::cout << str.find_first_of("Hello") << "\n";
    std::cout << str.find_last_of("Hello") << "\n";
    std::cout << str.find_first_not_of("Hello") << "\n";
    std::cout << str.find_last_not_of("Hello") << "\n";	
	
	return 0;
}
