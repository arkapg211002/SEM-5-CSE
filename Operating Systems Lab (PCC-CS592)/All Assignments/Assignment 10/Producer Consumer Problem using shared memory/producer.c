/*
 *  Program: producer.c
 *  Purpose: Demonstrates the Producer-Consumer problem
 *           with bounded buffer (circular queue) in shared memory
 *           using process semaphore for synchronization.
 *  Author : Dipankar Pal
 *  Last updated: 27.09.2022
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "buffer.h"
#include "psem.h"

#define  DELAY         1000000	  // Micro-seconds
#define  MAXITERATION  30

int
main (void)
{
  int shmid, smem_size, i;
  unsigned x = 0;
  buffer *sbuf = NULL;
  psem_t mutex;
  psem_t empty, full;

  smem_size = sizeof (buffer);
  shmid = shmget (1234, smem_size, 0666 | IPC_CREAT);		// Allocating space for shared memory
  if (shmid == -1)
    {
      perror ("shmget");
      return 1;
    }

  sbuf = (buffer *) shmat (shmid, NULL, 0);		// Attaching the shared memory space to the local space, to be used as buffer
  buf_init (sbuf);								// Initialising the Buffer space before use
  if (!psem_init (&mutex, 4321, 1))
    return 2;
  if (!psem_init (&empty, 4322, BUFFSIZE))
    return 2;
  if (!psem_init (&full, 4323, 0))
    return 2;

  i = MAXITERATION;				// Maximum number of iterations the production will continue
  while (i--)
    {
      x++;
      psem_wait(&empty);
      psem_wait (&mutex);
      if (buf_insert (sbuf, x))
	  printf ("Produced => %d\n", x);
      else
	  {
	     x--;
	     puts ("Buffer FULL\n");
	  }
      buf_display (sbuf);
      psem_post (&mutex);
      psem_post(&full);
      usleep (DELAY);
    }

  /* Waiting for the Consumer to finish before termination*/
  psem_holdon(&full);
  return 0;
}

