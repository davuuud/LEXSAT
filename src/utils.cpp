#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"

void error(const char * err) {
    perror(err);
    exit(EXIT_FAILURE);
}

static void print_lits(CaDiCaL::Solver *solver) {
    for (int i = 1; i <= solver->vars(); ++i) {
        printf("%d ", solver->val(i));
    }
    printf("\n");
}
