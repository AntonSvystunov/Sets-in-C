#ifndef BITVECTOR_H_INCLUDED
#define BITVECTOR_H_INCLUDED
#include <stdbool.h>

typedef unsigned long bitvector, *bitvector_p;

bitvector_p create_bitvector();
void dispose_bitvector(bitvector_p vect);

void set_bit(bitvector_p vect, int index, bool value);
int get_bit(bitvector_p vect, int index);

void print_bitvector(bitvector_p vect);

void set_0(bitvector_p vect);
void set_1(bitvector_p vect);

#endif // BITVECTOR_H_INCLUDED
