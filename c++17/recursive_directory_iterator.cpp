#include <iostream>
#include <numeric>
#include <string>
namespace fs = std::filesystem;

std::uintmax_t fetch_dir_size(const fs::path& dir)
{
  auto iterator = fs::recursive_directory_iterator(dir,fs::directory_options::none);
  return std::accumulate(fs::begin(iterator), fs::end(iterator),
  0ull,
  []( const std::uintmax_t dsize,
	  const fs::directory_entry& dentry ) 
	  {
			return dsize + (fs::is_regular_file(dentry) ? fs::file_size(dentry.path()) : 0);
	  });
}

int main()
{
   std::string path;
   std::cout<< "Path: ";
   std::cin>> path;
   std::cout<< "Size: "<<fetch_dir_size(path)<< "\n";
}
