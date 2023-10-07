/*
 *  Program: consumer.c
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
  unsigned y = 0;
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
  if (!psem_init (&mutex, 4321, -1))
    return 2;
  if (!psem_init (&empty, 4322, -1))
    return 2;
  if (!psem_init (&full, 4323, -1))
    return 2;

  i = MAXITERATION;				// Maximum number of iterations the consumption will continue
  while (i--)
    {
      psem_wait(&full);
      psem_wait (&mutex);
      if (buf_delete (sbuf, &y))
	     printf ("  Consumed => %d\n", y);
      else
	     puts ("Buffer EMPTY\n");
      buf_display (sbuf);
      psem_post (&mutex);
      psem_post(&empty);
      usleep (DELAY*2);
    }

  /* Performing the cleanup of semaphores used and the shared memory space before termination*/
  psem_destroy (&mutex);
  psem_destroy (&empty);
  psem_destroy (&full);
  buf_destroy (sbuf);
  shmdt ((void *) sbuf);
  shmctl (shmid, IPC_RMID, 0);
  return 0;
}

