Q.1) Write a C program that illustrates suspending and resuming processes using signals

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void suspend_handler(int sig) {
    printf("Suspended. Press Ctrl+Z to resume.\n");
    pause(); // Suspends the process until a signal is received
}

int main() {
    signal(SIGTSTP, suspend_handler); // Catch Ctrl+Z (SIGTSTP)
    
    while(1) {
        printf("Process running... Press Ctrl+Z to suspend.\n");
        sleep(1);  // Simulating some work
    }
    
    return 0;
}


Output:

Process running... Press Ctrl+Z to suspend.
Process running... Press Ctrl+Z to suspend.
Suspended. Press Ctrl+Z to resume.