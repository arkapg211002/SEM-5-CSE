#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        exit(0); // Child exits immediately, becoming a zombie
    } else {
        // Parent process
        printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(10); // Parent sleeps for some time
        printf("Parent process: After sleeping\n");
    }

    return 0;
}
