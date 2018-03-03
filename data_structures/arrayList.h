#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#define SLEN 10;

typedef struct array_list {
    int * arr;
    int max_size;
    int length;
} array_list_t, * array_list_p;

array_list_p create_array_list();
void print_array_list(array_list_p arr_list);
void grow_array(array_list_p arr_list);

void arr_add_last(array_list_p arr_list, int value);
void arr_add_first(array_list_p arr_list, int value);

#endif // ARRAYLIST_H_INCLUDED
