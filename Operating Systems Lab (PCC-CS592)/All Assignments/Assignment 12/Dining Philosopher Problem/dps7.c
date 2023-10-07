#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef struct {
    int state[NUM_PHILOSOPHERS];
    sem_t forks[NUM_PHILOSOPHERS];
    sem_t mutex;
} SharedData;

void initialize_shared_data(SharedData *shared_data) {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        shared_data->state[i] = THINKING;
        sem_init(&shared_data->forks[i], 1, 1);
    }
    sem_init(&shared_data->mutex, 1, 1);
}

void take_forks(SharedData *shared_data, int philosopher_num) {
    int left_fork = philosopher_num;
    int right_fork = (philosopher_num + 1) % NUM_PHILOSOPHERS;

    sem_wait(&shared_data->mutex);
    shared_data->state[philosopher_num] = HUNGRY;
    printf("Philosopher %d is hungry. Picked up forks %d and %d.\n", philosopher_num, left_fork, right_fork);
    sem_post(&shared_data->mutex);

    sem_wait(&shared_data->forks[left_fork]);
    sem_wait(&shared_data->forks[right_fork]);
}

void put_forks(SharedData *shared_data, int philosopher_num) {
    int left_fork = philosopher_num;
    int right_fork = (philosopher_num + 1) % NUM_PHILOSOPHERS;

    sem_wait(&shared_data->mutex);
    shared_data->state[philosopher_num] = THINKING;
    printf("Philosopher %d put down forks %d and %d.\n", philosopher_num, left_fork, right_fork);
    sem_post(&shared_data->mutex);

    sem_post(&shared_data->forks[left_fork]);
    sem_post(&shared_data->forks[right_fork]);
}

void philosopher(SharedData *shared_data, int philosopher_num) {
    int left_neighbor = (philosopher_num + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS;
    int right_neighbor = (philosopher_num + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", philosopher_num);
        sleep(1);  // Simulate thinking for 1 second

        // Check if the conditions are met for the philosopher to eat
        if ((philosopher_num == 0 && shared_data->state[right_neighbor] == THINKING && shared_data->state[left_neighbor] == THINKING) ||
            (philosopher_num == 1 && shared_data->state[left_neighbor] == THINKING && shared_data->state[right_neighbor] == THINKING) ||
            (philosopher_num == 2 && shared_data->state[left_neighbor] == THINKING && shared_data->state[right_neighbor] == THINKING) ||
            (philosopher_num == 3 && shared_data->state[right_neighbor] == THINKING && shared_data->state[left_neighbor] == THINKING) ||
            (philosopher_num == 4 && shared_data->state[right_neighbor] == THINKING && shared_data->state[left_neighbor] == THINKING)) {
            take_forks(shared_data, philosopher_num);
            printf("Philosopher %d is eating.\n", philosopher_num);
            sleep(2);  // Simulate eating for 2 seconds
            put_forks(shared_data, philosopher_num);
        } else {
            printf("Philosopher %d is not eating.\n", philosopher_num);
        }
    }
}

int main() {
    int shmid;
    SharedData *shared_data;

    // Create shared memory for fork states and semaphores
    shmid = shmget(IPC_PRIVATE, sizeof(SharedData), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory");
        return 1;
    }

    // Attach to the shared memory
    shared_data = (SharedData *)shmat(shmid, NULL, 0);
    if ((void *)shared_data == (void *)-1) {
        perror("Failed to attach to shared memory");
        return 1;
    }

    initialize_shared_data(shared_data);

    // Create philosopher processes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pid_t pid = fork();

        if (pid == 0) {  // Child process
            philosopher(shared_data, i);
            return 0;
        } else if (pid < 0) {  // Error in forking
            perror("Failed to fork");
            return 1;
        }
    }

    // Wait for all philosopher processes to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        wait(NULL);
    }

    // Detach from shared memory
    shmdt((void *)shared_data);

    // Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

