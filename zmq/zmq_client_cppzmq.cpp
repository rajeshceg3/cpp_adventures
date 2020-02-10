#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    // connect the client socket to server
    socket.connect ("tcp://localhost:7000");

    //  Do 10 requests, waiting each time for a response
    for (int i = 0; i < 10; i++)
	{
        zmq::message_t request (4);
        memcpy (request.data (), "Pink", 4);
        std::cout << "Sending Pink " << i <<"\n";
        socket.send (request);

        //  Receive the reply from server
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received Floyd " << i <<"\n"
    }
    return 0;
}
