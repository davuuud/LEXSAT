# LEXSAT

A lexsat solver that uses the SIMPLE algorithm as described in [1].

## Specifics
It has undefined behaviour, if literals are not from 1 to #NUM_OF_LITERALS.
Example: {1, 2, 4, 5} does not work as a set of literals, as 3 is missing.

## Building
It uses g++ as the default compiler.
With `make CXX=clang++` it can be changed to `clang++` or any other c++ compiler.

The only dependencies are libc and libcadical.
A precompiled static x86_64 archive is already in lib/.
Best case scenario: `make` simply works.
If not, then lib/libcadical.a probably needs to be replaced with a version compiled on the host system.
If that does not solve the issue, then the host system needs to be replaced... sorry :c

Please do not try cross-compilation without the necessary safety equipment!
Safety goggles, a stress ball, and a floppy disk to sacrifice to the computing gods.

## Usage
Call the LEXSAT solver with a file in DIMACS format of the problem and it does the rest.

```bash
./lexsat path/to/problem.dimacs
```

## References
[1] Petkovska, A., Mishchenko, A., Soeken, M., De Micheli, G., Brayton, R., & Ienne, P. (2016, November). Fast generation of lexicographic satisfiable assignments: Enabling canonicity in SAT-based applications. In 2016 IEEE/ACM International Conference on Computer-Aided Design (ICCAD) (pp. 1-8). IEEE.


@ David Blagojevic 2024