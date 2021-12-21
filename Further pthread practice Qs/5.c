#include <unistd.h>

// the rest is up to you! Implement a program which starts _two_ pthreads.
// One reads input from the user, and adds numbers to a total.
// the other prints the current total value every 3 seconds. 
// After 30 seconds, the main thread sets a bool to false that signals
// to both threads that they should join, just like in 3.c.
// You can use sleep(int seconds) from unistd.h to make your threads sleep.