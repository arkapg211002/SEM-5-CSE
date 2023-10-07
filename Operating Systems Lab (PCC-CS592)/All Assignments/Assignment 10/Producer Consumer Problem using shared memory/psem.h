/*
 *  Program: psem.h 
 *  Purpose: Definition of the semun union and process semaphore operations.
 *  Author : Dipankar Pal
 *  Last updated: 21.09.2022
 */

#include <unistd.h>
#include <sys/sem.h>

union semun {
	int val;				 /* Value for SETVAL */
	struct semid_ds *sem;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};


typedef struct psem {
	int id, val;
	unsigned key;
} psem_t;


int psem_init(psem_t *sem, unsigned key, int ival)
{
	union semun argu;
	sem->id = semget(key, 1, 0666|IPC_CREAT);
	if(sem->id == -1)
		return 0;
	sem->key = key;
	if(ival < 0)
		return -1;
	argu.val = ival;
	if(semctl(sem->id, 0, SETVAL, argu) == -1)
		return 0;
	sem->val = ival;
	return 1;
}

int psem_wait(psem_t *sem)
{
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = -1;
	operation.sem_flg = SEM_UNDO;
	if(semop(sem->id, &operation, 1) == -1)
		return 0;
	return 1;
}

int psem_post(psem_t *sem)
{
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = 1;
	operation.sem_flg = SEM_UNDO;
	if(semop(sem->id, &operation, 1) == -1)
		return 0;
	return 1;
}

int psem_holdon(psem_t *sem)
{
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = 0;
	operation.sem_flg = 0;
	if(semop(sem->id, &operation, 1) == -1)
		return 0;
	return 1;
}

int psem_destroy(psem_t *sem)
{
	union semun no_argu;
	if(semctl(sem->id, 0, IPC_RMID, no_argu) == -1)
		return 0;
	return 1;
}

