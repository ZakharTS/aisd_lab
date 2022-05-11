#ifndef TASK_HASHTAB_H
#define TASK_HASHTAB_H

#include <stdlib.h>
#include <string.h>

#define HASHTAB_SIZE 200000
#define HASHTAB_MUL 31

struct listnode {
    char *key;
    int value;
    struct listnode *next;
};
struct listnode *hashtab[HASHTAB_SIZE];

int hash(char *key);

void hashtab_init(struct listnode **hashtab);

void hashtab_add(struct listnode **hashtab, char *key, int value);

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);

#endif