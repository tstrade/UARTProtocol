#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#define MARK 1
#define SPACE 0
#define PACKET_SIZE 10
#define PARITY_BIT 8

// Common Baud rates (bits per sec): 4800, 9600, 19.2K, 57.6K, and 115.2K
#define BAUD_4800 283.333 // microseconds per bit
#define BAUD_9600 104.167
#define BAUD_19_2K 52.083
#define BAUD_57_6K 17.361
#define BAUD_115_2K 8.681

typedef struct data data;

void *transmit(void *arg);
void endCommunication(int sig);

#endif
