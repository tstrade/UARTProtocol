#include "transmitter.c"
#include "receiver.c"
#include "char2binary.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
  Cases to consider:
  Basic string: "Hello, World!"
  Character set test: "aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#$%^&*()_+"
  Number sequence: "1234567890"
  Repeating pattern: "AAAAAAA" or "12121212"
*/

#define BASIC_SIZE 13
char *basic = "Hello, world!";

#define CH_SET_SIZE 48
char *ch_set = "aBcDeFgHiJkLmNoPqRsTuVwXyZ0123456789!@#456&*()_+";

#define NUM_SEQ_SIZE 10
char *num_seq = "1234567890";

#define PATTERN_1_SIZE 24
char *pattern1 = "AAAAAAAAHHHHHHHH!!!!!!!!";

#define PATTERN_2_SIZE 27
char *pattern2 = "13.13.13.13.13.13.13.13.13.";

pthread_t threads[2];
void *(*func_ptrs[2])(void *) = { transmit, receive };

int main() {
  pthread_mutex_t wait_transmission = PTHREAD_MUTEX_INITIALIZER;
  pthread_cond_t signal_receiver = PTHREAD_COND_INITIALIZER;

  int *data_stream = malloc(BASIC_SIZE * sizeof(int));
  int *basic_converted = malloc(sizeof(char) * BASIC_SIZE * sizeof(int));
  basic_converted = convertString(basic_converted, basic);

  data data_basic = { basic_converted, BASIC_SIZE, 1, data_stream, &signal_receiver };
  controller control_basic = { wait_transmission, &signal_receiver, data_stream };
  void *args_basic[2] = { (void *)(&data_basic), (void *)(&control_basic) };

  for (int i = 0; i < 2; i++) {
    pthread_create(&threads[i], NULL, func_ptrs[i], args_basic[i]);
  }



  return 0;
}
