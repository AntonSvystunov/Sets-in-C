#include "linkedList.h"

#include <stdio.h>

void iterate_list(list_node_p head, void (*f)(int)) {
    if (head == NULL) {
        return;
    }
    list_node_p itr = head;
    while (itr != NULL) {
        f(itr->value);
        itr=itr->next;
    }
}

list_node_p get_subset(list_node_p head, bool (*predicate)(int)) {
    if (head == NULL) {
        return NULL;
    }
    list_node_p result = NULL;
    list_node_p itr = head;
    while (itr != NULL) {
        if (predicate(itr->value)) {
            add_first(&result, itr->value);
        }
        itr=itr->next;
    }
    return result;
}

void print_list(list_node_p * head) {
    if(head == NULL || *head == NULL) {
        printf("List is empty!\n");
        return;
    }
    list_node_p itr = *head;
    while (itr != NULL) {
        printf("%d ", itr->value);
        itr = itr->next;
    }
    printf("\n");
}

void add_first(list_node_p * head, int value) {
    list_node_p new_node = (list_node_p)malloc(sizeof(list_node_t));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void add_last(list_node_p * head, int value) {
    list_node_p new_node = (list_node_p)malloc(sizeof(list_node_t));
    new_node->value = value;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    list_node_p last = *head;
    while (last->next!=NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insert_after(list_node_p * head, int value, int index) {
    if(index < 0) {
        return;
    }

    list_node_p itr = *head;
    int i = 0;
    while (itr->next!=NULL) {
        if (index == i) {
            list_node_p new_node = (list_node_p)malloc(sizeof(list_node_t));
            new_node->value = value;
            new_node->next = itr->next;
            itr->next = new_node;
            return;
        }
        itr=itr->next;
        ++i;
    }

    list_node_p new_node = (list_node_p)malloc(sizeof(list_node_t));
    new_node->value = value;
    new_node->next = NULL;
    itr->next = new_node;
}

void delete_index(list_node_p * head, int index) {
    if (index < 0) {
        return;
    }

    list_node_p itr = *head;
    int i = 0;

    if (i == index) {
        *head = (*head)->next;
        free(itr);
        return;
    }

    while (itr!=NULL) {
        if(i+1 == index && itr->next!=NULL) {
            itr->next = itr->next->next;
            free(itr->next);
            return;
        }
        ++i;
        itr=itr->next;
    }
}

void delete_value(list_node_p * head, int value) {
    list_node_p itr = *head;

    int t_val = (*head)->value;

    if ((*head)->value == value) {
        *head = (*head)->next;
        free(itr);
        return;
    }

    while (itr!=NULL) {
        if(itr->next!=NULL && itr->next->value == value) {
            itr->next = itr->next->next;
            free(itr->next);
            return;
        }
        itr=itr->next;
    }
}

void reverse_list(list_node_p * head) {
    list_node_p before = NULL;
    list_node_p here = *head;
    list_node_p after = NULL;

    while (here != NULL) {
        after = here->next;
        here->next = before;
        before = here;
        here = after;
    }
    *head = before;
}

bool contains(list_node_p * head, int value) {
    list_node_p itr = *head;
    while (itr != NULL) {
        if (itr->value == value) {
            return true;
        }
        itr=itr->next;
    }
    return false;
}

int count_list(list_node_p * head) {
    int i = 0;
    list_node_p itr = *head;
    while (itr != NULL) {
        itr = itr->next;
        ++i;
    }
    return i;
}

list_node_p union_simple(list_node_p * first_head, list_node_p * second_head) {
    list_node_p result = NULL;
    list_node_p f_itr = *first_head;
    list_node_p s_itr = *second_head;

    while (f_itr != NULL) {
        add_first(&result, f_itr->value);
        f_itr = f_itr->next;
    }

    while (s_itr != NULL) {
        if (!contains(&result, s_itr->value)) {
            add_first(&result, s_itr->value);
        }
        s_itr = s_itr->next;
    }

    return result;
}

list_node_p intersection_simple(list_node_p * first_head, list_node_p * second_head) {
    list_node_p result = NULL;
    list_node_p f_itr = *first_head;

    while (f_itr != NULL) {
        if (contains(second_head, f_itr->value)) {
            add_first(&result, f_itr->value);
        }
        f_itr = f_itr->next;
    }

    return result;
}

void split_half(list_node_p head, list_node_p * first_head, list_node_p * second_head) {
    if (head == NULL || head->next == NULL) {
        *first_head = head;
        *second_head = NULL;
        return;
    }

    list_node_p slow_p = head;
    list_node_p fast_p = head->next;

    while (fast_p != NULL) {
        fast_p = fast_p->next;
        if (fast_p != NULL) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
    }

    *first_head = head;
    *second_head = slow_p->next;
    slow_p->next = NULL;
}

list_node_p merge_sorted(list_node_p first_head, list_node_p second_head) {
    if (first_head == NULL) {
        return second_head;
    }
    if (second_head == NULL) {
        return first_head;
    }

    list_node_p result = NULL;

    if (first_head->value <= second_head->value) {
        result = first_head;
        result->next = merge_sorted(first_head->next, second_head);
    } else {
        result = second_head;
        result->next = merge_sorted(first_head, second_head->next);
    }
    return result;
}

void merge_sort(list_node_p * head) {
    list_node_p full = *head;
    if(full == NULL || full->next == NULL) {
        return;
    }

    list_node_p first_part = NULL;
    list_node_p second_part = NULL;

    split_half(full, &first_part, &second_part);

    merge_sort(&first_part);
    merge_sort(&second_part);

    *head = merge_sorted(first_part, second_part);
}

list_node_p union_merge(list_node_p * first_head, list_node_p * second_head) {
    if (*first_head == NULL) {
        return *second_head;
    }

    if (*second_head == NULL) {
        return *first_head;
    }

    merge_sort(first_head);
    merge_sort(second_head);

    list_node_p result = NULL;
    list_node_p f_itr = *first_head;
    list_node_p s_itr = *second_head;

    while (f_itr != NULL && s_itr != NULL) {
        if (f_itr->value < s_itr->value) {
            add_first(&result, f_itr->value);
            f_itr = f_itr->next;
        } else if (f_itr->value > s_itr->value) {
            add_first(&result, s_itr->value);
            s_itr = s_itr->next;
        } else {
            add_first(&result, f_itr->value);
            f_itr = f_itr->next;
            s_itr = s_itr->next;
        }
    }

    while (f_itr!=NULL) {
        add_first(&result, f_itr->value);
        f_itr = f_itr->next;
    }

    while (s_itr!=NULL) {
        add_first(&result, s_itr->value);
        s_itr = s_itr->next;
    }

    return result;
}

list_node_p intersection_merge(list_node_p * first_head, list_node_p * second_head) {
    if (*first_head == NULL) {
        return NULL;
    }

    if (*second_head == NULL) {
        return NULL;
    }

    merge_sort(first_head);
    merge_sort(second_head);

    list_node_p result = NULL;
    list_node_p f_itr = *first_head;
    list_node_p s_itr = *second_head;

    while (f_itr != NULL && s_itr != NULL) {
        if (f_itr->value < s_itr->value) {
            f_itr = f_itr->next;
        } else if (f_itr->value > s_itr->value) {
            s_itr = s_itr->next;
        } else {
            add_first(&result, f_itr->value);
            f_itr = f_itr->next;
            s_itr = s_itr->next;
        }
    }

    return result;
}
