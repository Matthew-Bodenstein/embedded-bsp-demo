#include "memory_test.h"
#include <stdlib.h>
#include <time.h>

void memory_test_init(void) {
    // In real hardware: usse ECC, BIST, watchdog, etc.
    // Here: just seed randomness for simulated test results
    srand((unsigned int)time(NULL));
}

bool memory_test_run(void) {
    // Simulate memory check: 90% chance of passing, 10% chance of failure
    int result = rand() % 10;
    return (result != 0);  // fail if 0, pass otherwise
}
