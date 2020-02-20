#include <iostream>
#include <string>

/*
When an exception is thrown, stack unwinding happens to leave
the object in a valid state, this can be seen by the execution 
of destructor for invalid case, for valid case, this happens
naturally when the object goes out of scope
*/

class FILEClass
{
    FILE* m_file;
public:
    FILEClass(std::string filename) :
    m_file(fopen(filename, "rb"))
    {
        if (m_file == 0) 
            throw std::runtime_error("File Cannot be opened");
        
    }

    ~FILEClass()
    {
        fclose(m_file);
        std::clog << "Destructor executed \n";
    }
};

int main(void)
{
    FILEClass FileObj1("valid_file.txt");

    try 
	  {
        FILEClass FileObj2("file_does_not_exist.txt");
    }
    catch(const std::exception &e) 
	  {
        std::cout << "exception: " << e.what() << "\n";
    }
}
