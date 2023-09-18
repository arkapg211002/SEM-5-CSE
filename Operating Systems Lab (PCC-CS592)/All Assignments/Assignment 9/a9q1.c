#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define PARENT_SEM_NAME "/pa_semaphore"
#define CHILD_SEM_NAME "/ch_semaphore"
#define COUNTER_SHM_NAME "/counter_shm"

sem_t *sem_parent, *sem_child;
int *counter;  // Pointer to shared counter in shared memory

void parent_process() {
    while (1) {
        sem_wait(sem_parent);
        if (*counter >= 3) {
            sem_post(sem_child);  // Signal child to end the program
            break;
        }
        printf("baab");
        fflush(stdout);
        (*counter)++;
        sem_post(sem_child);
        sleep(1);  // Add a delay of 1 second for better visualization
    }
}

void child_process() {
    while (1) {
        sem_wait(sem_child);
        if (*counter >= 3) {
            sem_post(sem_parent);  // Signal parent to end the program
            break;
        }
        printf("baab");
        fflush(stdout);
        (*counter)++;
        sem_post(sem_parent);
        sleep(1);  // Add a delay of 1 second for better visualization
    }
}

int main() {
    // Create shared memory for counter
    int shm_fd = shm_open(COUNTER_SHM_NAME, O_CREAT | O_RDWR, 0644);
    ftruncate(shm_fd, sizeof(int));
    counter = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    *counter = 0;

    // Initialize the semaphores
    sem_parent = sem_open(PARENT_SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
    sem_child = sem_open(CHILD_SEM_NAME, O_CREAT | O_EXCL, 0644, 0);

    if (sem_parent == SEM_FAILED || sem_child == SEM_FAILED) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        child_process();
    } else {
        // Parent process
        parent_process();
    }

    // Wait for the child process to finish
    wait(NULL);

    // Close and unlink the semaphores
    sem_close(sem_parent);
    sem_close(sem_child);
    sem_unlink(PARENT_SEM_NAME);
    sem_unlink(CHILD_SEM_NAME);

    // Unmap and unlink shared memory
    munmap(counter, sizeof(int));
    shm_unlink(COUNTER_SHM_NAME);
    printf("\n");
    return 0;
}

