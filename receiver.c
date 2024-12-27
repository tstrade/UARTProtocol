#include "receiver.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct controller {
  pthread_mutex_t wait_transmission;
  pthread_cond_t *signal_receiver;
  int *buffer;
};

void *receive(void *arg) {
  controller *control = (controller *)arg;
  pthread_mutex_t wait_transmission = control->wait_transmission;
  pthread_cond_t *signal_receiver = control->signal_receiver;

  while (1)
    {
      pthread_mutex_lock(&wait_transmission);
      pthread_cond_wait(signal_receiver, &wait_transmission);
    }

  pthread_exit(NULL);
}
