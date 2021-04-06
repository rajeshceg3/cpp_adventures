#include "asio.hpp"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
      // Steps needed to run a server
      asio::io_context io_context;
      asio::ip::tcp::endpoint ep(asio::ip::tcp::v4(), 8080);
      asio::ip::tcp::acceptor acceptor(io_context, ep);
  
      while (true)
      {
          // Client connection is modelled by socket
          asio::ip::tcp::socket socket(io_context);
          acceptor.accept(socket);

          // Create paylod to be sent to client
          time_t now = time(nullptr);
          std::string message = ctime(&now);

          // Send payload to client
          error_code error;
          asio::write(socket, asio::buffer(message), error);

          // Error checking
          if (error) 
              std::cout << "Problem code " << error.value() << ": "<< error.message() << "\n;
      }
    return 0;
}
