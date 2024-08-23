#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
#include <errno.h>
#include "cadical.hpp"
#include "simple.hpp"

char *prog;

static void usage(void) {
    fprintf(stderr, "Usage: %s dimacs\n\n", prog);
    fprintf(stderr, "Basic LEXSAT solver.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    prog = argv[0];
    if (argc > 2) {
        usage();
    }

    run_simple(argv[1]);

    return EXIT_SUCCESS;
}