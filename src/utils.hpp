#ifndef __UTILS_HPP
#define __UTILS_HPP

#include "cadical.hpp"

void error(const char *err);
static void print_lits(CaDiCaL::Solver *solver);

#endif // __UTILS_HPP