#ifndef TASK_HASHTAB_H
#define TASK_HASHTAB_H

#include <stdlib.h>
#include <string>

#define HASHTAB_SIZE 200000
#define HASHTAB_MUL 31

struct listnode {
    std::string key;
    int value;
    struct listnode *next;
};

int hash(std::string key);

void hashtab_init(struct listnode **hashtab);

void hashtab_add(struct listnode **hashtab, std::string key, int value);

struct listnode *hashtab_lookup(struct listnode **hashtab, std::string key);

void hashtab_delete(struct listnode **hashtab, std::string key);

#endif