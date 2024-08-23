#include <stdio.h>
#include <stdlib.h>
#include "simple.hpp"
#include "utils.hpp"
#include "cadical.hpp"

void run_simple(const char *file) {

    CaDiCaL::Solver *solver = new CaDiCaL::Solver;

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        error("File not found.\n");
    }
    int vars;
    solver->read_dimacs(f, file, vars, 1);
    fclose(f);

    printf("%d\n", solver->solve());

    delete solver;
}