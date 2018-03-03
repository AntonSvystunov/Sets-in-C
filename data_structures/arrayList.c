#include "arrayList.h"
#include <stdio.h>

array_list_p create_array_list() {
    array_list_p new_list = (array_list_p)malloc(sizeof(array_list_t));
    if (new_list == NULL) {
        return NULL;
    }
    new_list->length = 0;
    new_list->max_size = SLEN;
    new_list->arr = (int *)calloc(new_list->max_size, sizeof(int));

    if (new_list->arr == NULL) {
        free(new_list);
        return NULL;
    }

    return new_list;
}

void print_array_list(array_list_p arr_list) {
    if (arr_list == NULL) {
        return;
    }
    int i;
    for (i = 0; i<arr_list->length; ++i) {
        printf("%d ", arr_list->arr[i]);
    }
    if (i = 0) {
        printf("List is empty!");
    }
    printf("\n");
}

void grow_array(array_list_p arr_list) {
    int * new_arr = (int *)calloc(arr_list->max_size * 2, sizeof(int));
    if(new_arr == NULL) {
        new_arr = (int *)calloc((int)(arr_list->max_size*3)/2 + 1 , sizeof(int));
        if (new_arr == NULL) {
            printf("Unable to allocate memory");
            exit(1);
            //return;
        }
        arr_list->max_size = (int)(arr_list->max_size*3)/2 + 1;
    } else {
        arr_list->max_size = arr_list->max_size * 2;
    }
    int i;
    for (i = 0; i<arr_list->length; ++i) {
        new_arr[i] = arr_list->arr[i];
    }
    free(arr_list->arr);
    arr_list->arr = new_arr;
}

void arr_add_last(array_list_p arr_list, int value) {
    if (arr_list->length + 1 > arr_list->max_size) {
        grow_array(arr_list);
    }
    arr_list->arr[arr_list->length++] = value;
}

void arr_add_first(array_list_p arr_list, int value) {
    if (arr_list->length + 1 > arr_list->max_size) {
        grow_array(arr_list);
    }
    int i;
    arr_list->length++;
    for(i = arr_list->length-1; i>=0; --i) {
        arr_list->arr[i] = arr_list->arr[i-1];
    }
    arr_list->arr[0] = value;
}
