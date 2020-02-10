#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main ()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:7000");
    while (true) 
	{
        zmq::message_t request;
        // Get the request from client
        socket.recv (&request);
        std::cout << "Received Client Request" <<"\n"

        sleep(1);

        //  Give response to client
        zmq::message_t reply (5);
        memcpy(reply.data(), "Floyd", 5);
        socket.send(reply);
    }
    return 0;
}
