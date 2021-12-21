#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>  // gives us sleep(). Replace with windows.h for compiling on windows!

#define NUM_THREADS 20

typedef struct _threadinfo {
    bool * keepRunning;
    int * total;
} threadinfo_t;

void * getInput(void * arg) {
    threadinfo_t * args = (threadinfo_t *) arg;
    
    int currInput;
    printf("Input as much as you can --- you have 10 seconds!\n");
    while (*args->keepRunning) {
        printf("Add another number!  : ");
        scanf("%d", &currInput);
        *args->total += currInput;
    }
    pthread_exit(NULL);
}

int main() {

    pthread_t thread;
    bool keepRunning = true;
    int total = 0;
    threadinfo_t args = {&keepRunning, &total};

    pthread_create(&thread, NULL, getInput, &args);

    sleep(10); // sleep for 10 secs
    keepRunning = false;
    pthread_join(thread, NULL);
    printf("\n\nYou managed to enter a total of: %d!\n", total);

    pthread_exit(NULL);

}

