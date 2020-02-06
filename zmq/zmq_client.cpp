#include <string.h>
#include <iostream>
#include <unistd.h>
#include "zmq.h"

int main () 
{
  void* context = zmq_ctx_new();
  void* request = zmq_socket(context, ZMQ_REQ);
  zmq_connect(request, "tcp://localhost:7070");

  int count = 0;
  while(true)
  {
    zmq_msg_t req;
    zmq_msg_init_size(&req, strlen("hello"));
    memcpy(zmq_msg_data(&req), "hello", 5);
    cout<<"Sending: hello "<<count<<"\n";
    zmq_msg_send(&req, request, 0);
    zmq_msg_close(&req);
    
    zmq_msg_t reply;
    zmq_msg_init(&reply);
    zmq_msg_recv(&reply, request, 0);
	cout<<"Received: hello "<<count<<"\n";
    zmq_msg_close(&reply);
    count++;
  }
  zmq_close(request);
  zmq_ctx_destroy(context);
  
  return 0;
}
