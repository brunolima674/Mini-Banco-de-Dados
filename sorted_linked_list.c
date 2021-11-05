#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "sorted_linked_list.h"

typedef struct node node_t;

struct node {
    elem info;
    char *name;
    node_t *prev, *next;
};

struct list {
    node_t *beginning, *end;
    int n_elem;
};

list_t *create() {
    list_t *p;
    p = (list_t *) malloc(sizeof(list_t));
    p->beginning = NULL;
    p->end = NULL;
    p->n_elem = 0;

    return p;
}

void free_list(list_t *l) {
    if (l != NULL) {
        node_t *aux = l->beginning;
        while (aux != NULL) {
            l->beginning = l->beginning->next;
            free(aux);
            aux = l->beginning;
        }
        free(l);
    }
}

int insert_elem(list_t *l, elem x, char *name) {
    assert(l != NULL);

    node_t *p = (node_t *) malloc(sizeof(node_t));
    p->name = (char *) malloc(sizeof(char) * 50);
    p->info = x;
    strcpy(p->name, name);
    p->next = NULL;
    p->prev = NULL;

    node_t *aux, *previous;
    previous = NULL;
    aux = l->beginning;

    while (aux != NULL && x > aux->info) {
        previous = aux;
        aux = aux->next;
    }

    // caso onde x ja existe na lista
    if (aux != NULL && x == aux->info) {
        free(p);
        return 0;
    }

    // inserindo no inicio, lista vazia ou
    // lista com elementos
    if (previous == NULL) {
        p->next = l->beginning;
        if (l->beginning != NULL) {
            l->beginning->prev = p;
        } else {
            l->end = p;
        }
        l->beginning = p;
        l->n_elem++;
    } else { // inserindo no meio ou fim da lista
        p->next = previous->next;
        previous->next = p;
        if (p->next != NULL) {
            p->next->prev = p;
        } else {
            l->end = p;
        }
        p->prev = previous;
        l->n_elem++;
    }

    return 1;
}

int  list_contains_elem(list_t *l, elem x) {
    if (l != NULL) {
        node_t *p = l->beginning;
        while (p != NULL) {
            if (p->info == x) {
                return 1;
            }
            p = p->next;
        }
    }

    return 0;
}

int remove_elem(list_t *l, elem x) {
    assert(l != NULL);

    node_t *p = l->beginning;
    node_t *previous = NULL;

    while (p != NULL && x > p->info) {
        previous = p;
        p = p->next;
    }

    if (p == NULL || p->info != x) {
        return 0;
    }

    // remocao do primeiro elemento
    if (previous == NULL) {
        l->beginning = l->beginning->next;
        if (l->beginning != NULL) {
            l->beginning->prev = NULL;
        } else {
            l->end = NULL;
        }
        l->n_elem--;
        free(p->name);
        free(p);
    } else { // remocao de elemento no meio ou no fim
        if (p->next == NULL) { //remocao do fim da lista
            l->end = p->prev;
            previous->next = NULL;
            l->n_elem--;
            free(p->name);
            free(p);
        } else { // remocao do meio da lista
            previous->next = p->next;
            p->next->prev = previous;
            l->n_elem--;
            free(p->name);
            free(p);
        }
    }

    return 1;
}

int is_empty(list_t *l) {
    assert(l != NULL);

    if (l->n_elem == 0) {
        return 1;
    }

    return 0;
}

void print_list(list_t *l) {
    assert(l != NULL);
    node_t *p = l->beginning;

    while (p != NULL) {
        printf("%d, %s; ", p->info, p->name);

        p = p->next;
    }
    printf("\n");
}

void print_inv_list(list_t *l) {
    assert(l != NULL);
    node_t *p = l->end;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prev;
    }
    printf("\n");
}


