#include <stdio.h>
#include <stdlib.h>
#include "simple.hpp"
#include "utils.hpp"
#include "cadical.hpp"

static void set_assumtions_up_to(CaDiCaL::Solver *solver, int *assignment, int d) {
    for (int i = 1; i < d; ++i) {
        solver->assume(assignment[i-1]);
    }
}

static int algo(CaDiCaL::Solver *solver) {
    const int NUM_LITS = solver->vars();
    int assignment[NUM_LITS];
    for (int d = 1; d <= NUM_LITS; ++d) {
        set_assumtions_up_to(solver, assignment, d);
        solver->assume(-d);
        if (solver->solve() == CaDiCaL::UNSATISFIED) {
            // Check unsatisfiability by also checking d=true
            set_assumtions_up_to(solver, assignment, d);
            solver->assume(d);
            if (solver->solve() == CaDiCaL::UNSATISFIABLE) {
                return CaDiCaL::UNSATISFIABLE; // UNSATISFIABLE
            }
            assignment[d-1] = d;
        } else {
            assignment[d-1] = -d;
        }
    }

    for (int i = 0; i < NUM_LITS; ++i) {
        printf("%d ", assignment[i]);
    }
    printf("\n");
    return CaDiCaL::SATISFIABLE;
}

int run_simple(const char *file) {
    CaDiCaL::Solver *solver = new CaDiCaL::Solver;
    int res;

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        error("File not found.\n");
    }
    int vars;
    solver->read_dimacs(f, file, vars, 1);
    fclose(f);

    if (solver->vars() <= 1) {
        res = solver->solve();
    } else {
        res = algo(solver);
    }

    delete solver;
    
    return res;
}