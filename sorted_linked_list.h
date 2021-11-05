#ifndef LISTA_ORDENADA_SORTED_LINKED_LIST_H
#define LISTA_ORDENADA_SORTED_LINKED_LIST_H

typedef int elem;
typedef struct list list_t;
typedef struct node node_t;

list_t *create();

void free_list(list_t *l);

int insert_elem(list_t *l, elem x, char *name);

int  list_contains_elem(list_t *l, elem x);

int remove_elem(list_t *list, elem x);

int is_empty(list_t *l);

void print_list(list_t *l);

void print_inv_list(list_t *l);

#endif //LISTA_ORDENADA_SORTED_LINKED_LIST_H
