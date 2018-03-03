#include <stdio.h>
#include <stdlib.h>

#include "bitvector.h"

int main()
{
    bitvector_p v = create_bitvector();
    print_bitvector(v);
    set_1(v);
    print_bitvector(v);
    set_bit(v, 3, 0);
    print_bitvector(v);
    set_0(v);
    print_bitvector(v);
    set_bit(v, 2, 1);
    set_bit(v, 7, 1);
    print_bitvector(v);

    printf("7:%d\t2:%d\t0:%d\n", get_bit(v, 7), get_bit(v, 2), get_bit(v, 0));

    dispose_bitvector(v);
    return 0;
}
