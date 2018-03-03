#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdbool.h>

typedef struct list_node {
    int value;
    struct list_node * next;
} list_node_t, *list_node_p;

void iterate_list(list_node_p head, void (*f)(int));
list_node_p get_subset(list_node_p head, bool (*predicate)(int));

void print_list(list_node_p * head);
void reverse_list(list_node_p * head);
int count_list(list_node_p * head);

void add_first(list_node_p * head, int value);
void insert_after(list_node_p * head, int value, int index);
void add_last(list_node_p * head, int value);

void delete_index(list_node_p * head, int index);
void delete_value(list_node_p * head, int value);

bool contains(list_node_p * head, int value);

list_node_p union_simple(list_node_p * first_head, list_node_p * second_head);
list_node_p intersection_simple(list_node_p * first_head, list_node_p * second_head);

void split_half(list_node_p head, list_node_p * first_head, list_node_p * second_head);
list_node_p merge_sorted(list_node_p first_head, list_node_p second_head);
void merge_sort(list_node_p * head);

list_node_p union_merge(list_node_p * first_head, list_node_p * second_head);
list_node_p intersection_merge(list_node_p * first_head, list_node_p * second_head);

#endif // LINKEDLIST_H_INCLUDED
