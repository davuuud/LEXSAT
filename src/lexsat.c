#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
#include <errno.h>

char *prog;

void usage(void) {
    fprintf(stderr, "Usage: %s [options] dimacs", prog);
    fprintf(stderr, "-h, --help\tShow this.", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    prog = argv[0];
    if (argc > 2) {
        usage();
    }
    return EXIT_SUCCESS;
}