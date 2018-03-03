#include "bitvector.h"
#include <stdio.h>

bitvector_p create_bitvector() {
    bitvector_p new_vect = (bitvector_p)malloc(sizeof(bitvector));
    if (new_vect != NULL) {
        *new_vect = 0;
    }
    return new_vect;
}

void dispose_bitvector(bitvector_p vect) {
    if (vect != NULL) {
        free(vect);
    }
}

void set_bit(bitvector_p vect, int index, bool value) {
    if(index > sizeof(*vect) * 8 - 1) {
        return;
    }
    bitvector temp = 1;
    temp = temp << index;
    if (value) {
        *vect = *vect | temp;
    } else {
        temp = ~temp;
        *vect = *vect & temp;
    }
}

int get_bit(bitvector_p vect, int index) {
    if(index > sizeof(*vect) * 8 - 1) {
        return 0;
    }
    bitvector result = 1;
    result = result << index;
    result = *vect & result;
    result = result >> index;
    return result;
}

void print_bitvector(bitvector_p vect) {
    int i;
    for (i = sizeof(*vect)*8-1; i >= 0; --i) {
        printf("%c", get_bit(vect, i) ? '1' : '0');
    }
    printf("\n");
}

void set_0(bitvector_p vect) {
    *vect = 0;
}

void set_1(bitvector_p vect) {
    *vect = ~(bitvector)0;
}
