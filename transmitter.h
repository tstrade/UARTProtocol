#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <pthread.h>

#define MARK 1
#define SPACE 0
#define PACKET_SIZE 8
#define PARITY_BIT 7

// Classic producer-consumer  :)
pthread_t transmitter;
pthread_t receiver;
int frame_state;

void *transmit(void *arg);
void *receive(void *arg);


#endif
