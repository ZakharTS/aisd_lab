#include "hashtab.h"

int hash(char *key) {
    int h = 0;
    char *p;
    for (p = key; *p != '\0'; p++) {
        h = h * HASHTAB_MUL + (int) *p;
    }
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab) {
    for (int i = 0; i < HASHTAB_SIZE; i++) {
        hashtab[i] = NULL;
    }
}

void hashtab_add(struct listnode **hashtab, char *key, int value) {
    struct listnode *node;
    int index = hash(key);
    node = (listnode *) (malloc(sizeof(*node)));
    if (node != NULL) {
        strcpy(node->key, key);
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key) {
    int index = hash(key);
    for (struct listnode *node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }
    return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key) {
    int index = hash(key);
    struct listnode *prev = NULL;
    for (struct listnode *p = hashtab[index]; p != NULL; p = p->next) {
        if (strcmp(p->key, key) == 0) {
            if (prev == NULL)
                hashtab[index] = p->next;
            else
                prev->next = p->next;
            free(p);
            return;
        }
        prev = p;
    }
}