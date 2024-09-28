#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"

void error(const char * err) {
    perror(err);
    exit(EXIT_FAILURE);
}
