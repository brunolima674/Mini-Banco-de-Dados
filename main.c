#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorted_linked_list.h"

int main() {
    list_t *l = create();

    int code;
    char *key, *name, c;

    key = malloc(sizeof(char) * 10);
    name = malloc(sizeof(char) * 60);

    while ((c = getchar()) != EOF) {
        ungetc(c, stdin);

        scanf("%s ", key);

        if (strcmp(key, "INSERE") == 0) {
            scanf("%d ", &code);

            fgets(name, sizeof(char) * 60, stdin);
            name[strlen(name) - 2] = '\0';

            if (list_contains_elem(l , code) == 1) {
                printf("INVALIDO\n");
                continue;
            }

            insert_elem(l, code, name);
        }
        if (strcmp(key, "REMOVE") == 0) {
            scanf("%d ", &code);
            if (remove_elem(l, code) != 1) {
                printf("INVALIDO\n");
            }
        }
        if (strcmp(key, "IMPRIMIR") == 0) {
            if (is_empty(l) == 1) {
                printf("VAZIA\n");
            } else {
                print_list(l);
            }
        }
    }

    free(key);
    free(name);
    free_list(l);

    return 0;
}