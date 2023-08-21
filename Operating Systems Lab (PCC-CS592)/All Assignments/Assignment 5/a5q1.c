#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int child_pid;

    child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
	sleep(15);
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        // Parent process
	sleep(15);
        printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    return 0;
}
