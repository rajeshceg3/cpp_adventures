#include <iostream>
#include <functional>
#include <boost/asio.hpp>
#include <memory>

using namespace std;
using boost::asio::ip::tcp;

// Building blocks for creating an Asynchronous
// Server with Boost asio

class con_handler : public std::enable_shared_from_this<con_handler>
{
  tcp::socket sock;
  std::string message="I am your Server and I say Hello";
  enum {max_length = 1024};
  char data[max_length];
public:
  using pointer =  std::shared_ptr<con_handler>;
  con_handler(boost::asio::io_service& io_service):sock(io_service){}
  static pointer create(boost::asio::io_service& io_service)
  {
      return make_shared<con_handler>(io_service);
  }
  tcp::socket& socket()
  {
       return sock;
  };
  void start()
  {
    sock.async_read_some(boost::asio::buffer(data,max_length),
                           std::bind(&con_handler::handle_read,
                           shared_from_this(),
                           boost::asio::placeholders::error,
                           boost::asio::placeholders::bytes_transferred));

    sock.async_write_some(boost::asio::buffer(message,max_length),
                          std::bind(&con_handler::handle_write,
                          shared_from_this(),
                          boost::asio::placeholders::error,
                          boost::asio::placeholders::bytes_transferred));
  }

  void handle_read(boost::system::error_code& err, size_t bytes_transferred)
  {
      if (!err) cout<<data<<"\n";
      else 
      {
          cerr<<err.message()<<"\n";
          sock.close();
      }
  }

  void handle_write(boost::system::error_code& err, size_t bytes_transferred)
  {
      if(!err) cout<<"Server sent the response \n";
      else
      {
          cerr<<err.message()<<"\n";
          sock.close();
      }
  }
};
int main()
{

    return 0;
}
