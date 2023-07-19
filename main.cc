#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

extern "C" void __gcov_dump();

static void catch_function(int signal) {
    std::cout << "print something" << std::endl;
   __gcov_dump();
}

int main(void) {
    if (signal(SIGINT, catch_function) == SIG_ERR) {
        fputs("An error occurred while setting a signal handler.\n", stderr);
        return EXIT_FAILURE;
    }
    while(1);
}