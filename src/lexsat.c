#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
#include <errno.h>

char *prog;

void usage(void) {
    fprintf(stderr, "Usage: %s [options] dimacs\n\n", prog);
    fprintf(stderr, "Basic LEXSAT solver.\n\n", prog);
    fprintf(stderr, "\t-h, --help\tShow this.\n", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    prog = argv[0];
    if (argc > 2) {
        usage();
    }
    return EXIT_SUCCESS;
}