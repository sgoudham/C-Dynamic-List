#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 20

void *fizzbuzz(void *arg) {
    int *number = (int *) arg;
    if (*number % 3 == 0) {
        printf("%d -> %s\n", *number, "fizz");
    } else if (*number % 5 == 0) {
        printf("%d -> %s\n", *number, "buzz");
    } else {
        printf("%d -> %s\n", *number, "no div");
    }

    pthread_exit(NULL);
}

int main() {

    pthread_t threads[20];
    int nums[20];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        nums[i] = i + 1;
        pthread_create(&threads[i], NULL, fizzbuzz, &nums[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        char *returnedStr;
        pthread_join(threads[i], (void **) &returnedStr);
    }

    pthread_exit(NULL);

}
