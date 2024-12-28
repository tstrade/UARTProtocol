#include "transmitter.h"

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int data_bit;

struct data {
  int *message;
  int data_size;
  volatile int idle_state;
  int *buffer;
  pthread_cond_t *signal_receiver;
};


void *transmit(void *arg) {
  data *TRANSMISSION = (data *)arg;
  pthread_cond_t *signal_receiver = TRANSMISSION->signal_receiver;
  int *buffer = TRANSMISSION->buffer;
  int *message = TRANSMISSION->message;

  clock_t end = clock(), start = clock();
  char character;
  int bit = 0;

  while (1)
    {

      while (end - start < BAUD_9600) { start = end; end = clock(); }
      if (TRANSMISSION->idle_state) {
	TRANSMISSION->buffer[bit] = 1;
	pthread_cond_signal(signal_receiver);
	bit = (bit + 1) % TRANSMISSION->data_size;
      }

      // Write start by dropping to logical low
      TRANSMISSION->buffer
	start = clock(), end = clock();
    }

  pthread_exit(NULL);
}
