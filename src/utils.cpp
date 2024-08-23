#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"

void error(const char * err) {
    fprintf(stderr, "ERROR: %s", err);
    exit(EXIT_FAILURE);
}