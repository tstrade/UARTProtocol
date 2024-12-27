#ifndef RECEIVER_H
#define RECEIVER_H

/* Defined in transmitter.h
   #define MARK 1
   #define SPACE 0
   #define PACKET_SIZE 10
   #define PARITY_BIT 8

   Unit = microseconds per bit
   #define BAUD_4800 283.333
   #define BAUD_9600 104.167
   #define BAUD_19_2K 52.083
   #define BAUD_57_6K 17.361
   #define BAUD_115_2K 8.681
*/

typedef struct controller controller;
void *receive(void *arg);

#endif
