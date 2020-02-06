#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zmq.h"

int main () {
  
  void* context = zmq_ctx_new();
  void* respond = zmq_socket(context, ZMQ_REP);
  zmq_bind(respond, "tcp://*:7070");

  while(true)
  {
    zmq_msg_t request;
    zmq_msg_init(&request);
    zmq_msg_recv(&request, respond, 0);
    printf("Received: hello\n");
    zmq_msg_close(&request);
    sleep(1); // sleep for a second
    
    zmq_msg_t reply;
    zmq_msg_init_size(&reply, strlen("gutentag"));
    memcpy(zmq_msg_data(&reply), "gutentag", 8);
    zmq_msg_send(&reply, respond, 0);
    zmq_msg_close(&reply);
  }
  zmq_close(respond);
  zmq_ctx_destroy(context);
  
  return 0;
}
