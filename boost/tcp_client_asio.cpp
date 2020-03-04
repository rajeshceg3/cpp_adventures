#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;

int main()
{
    boost::asio::io_service io_service;
    tcp::socket socket_(io_service);
    socket_.connect( tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),1234 ));

    // Client Request
    const string msg = "I am a client\n";
    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg),error);
    if (!error) cout<<"Message sent successfully\n";
    else cout<<"Failure in sending\n";

    // Handling Server response
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer,boost::asio::transfer_all(),error);
    if( error && error != boost::asio::error::eof) cout<<"Receive failed "<<error.message()<<"\n";
    else
    {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout<<"Received Response from server \n";
        cout<<data<<"\n";
    }
    return 0;
}
