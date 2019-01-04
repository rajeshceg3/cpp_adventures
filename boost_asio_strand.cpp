#include <iostream>
#include <boost/asio.hpp>
using namespace std;

int main(){
    boost::asio::io_service service;
	boost::asio::io_service::strand strand(service);
    boost::asio::deadline_timer timer1( service, boost::posix_time::seconds(5));    
	boost::asio::deadline_timer timer2( service, boost::posix_time::seconds(3));    
    timer1.async_wait(strand.wrap([](auto err){ cout<<"Timer1 expired \n";}));
	timer2.async_wait(strand.wrap([](auto err){ cout<<"Timer2 expired \n";}));
	
	thread t1([&](){
		cout<<"Before run t1 \n";
		service.run();
		cout<<"After run t1\n";
	});
	
	thread t2([&](){
		cout<<"Before run t2\n";
		service.run();
		cout<<"After run t2\n";
	});

	t1.join();
	t2.join();
}
