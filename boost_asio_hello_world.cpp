#include <iostream>
#include <boost/asio.hpp>
using namespace std;

int main(){
    boost::asio::io_service service;
    boost::asio::deadline_timer timer( service, boost::posix_time::seconds(15));    
    timer.async_wait([](auto err){ cout<<"Timer expired \n";});
	cout<<"Before run \n";
	service.run();
	cout<<"After run \n";
}
