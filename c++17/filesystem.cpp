#include <fstream>
#include <string>
namespace fs = std::filesystem;

void shrink_file(fs::path filepath)
{
   std::ifstream ifile(filepath.native(), std::ios::in);
   if (!ifile.is_open())
      throw std::runtime_error("Specified File cannot be opened");

   auto tmp = fs::temp_directory_path() / "temp.txt";
   std::ofstream fileout(tmp.native(), std::ios::out | std::ios::trunc);
   if (!fileout.is_open())
      throw std::runtime_error("Temporary file couldn't be created");

   std::string line;
   while(std::getline(ifile, line))
   {
      if (line.size() > 0 && line.find_first_not_of(' ') != line.npos)
         fileout << line << "\n";      
   }

   ifile.close();
   fileout.close();

   fs::remove(filepath);
   fs::rename(tmp, filepath);
}

int main()
{
   shrink_file("file_with_empty_lines.txt");
}
