#include <stdio.h>
#include <stdlib.h>
#include "simple.hpp"
#include "utils.hpp"
#include "cadical.hpp"

static inline void set_assumtions_up_to(CaDiCaL::Solver *solver, int *assignment, int d) {
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
        if (solver->solve() == CaDiCaL::UNSATISFIABLE) {
            // Check unsatisfiability by also checking d=true
            set_assumtions_up_to(solver, assignment, d);
            solver->assume(d);
            if (solver->solve() == CaDiCaL::UNSATISFIABLE) {
                printf("UNSAT\n");
                return CaDiCaL::UNSATISFIABLE;
            }
            assignment[d-1] = d;
        } else {
            assignment[d-1] = -d;
        }
    }

    printf("SAT\n");
    for (int i = 0; i < NUM_LITS; ++i) {
        printf("%d ", assignment[i]);
    }
    printf("\n");
    return CaDiCaL::SATISFIABLE;
}

int run_simple(const char *file) {
    CaDiCaL::Solver *solver = new CaDiCaL::Solver;
    int res;

    // Read dimacs
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        error("File not found.\n");
    }

    int vars;
    const char* err = solver->read_dimacs(f, file, vars, 1);
    if(err != NULL) {
        error(err);
    }

    fclose(f);

    // Run the algorithm
    if (vars < 1) {
        res = 0;
        printf("No literals. Problem is left as an exercise to the user.\n");
    } else if (vars == 1) {
        res = solver->solve();
        if (res == CaDiCaL::UNSATISFIABLE) {
            printf("UNSAT\n");
        } else {
            printf("SAT\n");
            printf("%d\n", solver->val(1)); // Technically could be != 1, but this is an edge case anyway.
        }
    } else {
        res = algo(solver);
    }

    delete solver;
    
    return res;
}