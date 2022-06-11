#include "hashtab.h"

int hash(std::string key) {
    int h = 0;
    for (auto p: key) {
        h = h * HASHTAB_MUL + (int) p;
    }
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab) {
    for (int i = 0; i < HASHTAB_SIZE; i++) {
        hashtab[i] = nullptr;
    }
}

void hashtab_add(struct listnode **hashtab, std::string key, int value) {
    struct listnode *node = new struct listnode;
    int index = hash(key);
    if (node != nullptr) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode *hashtab_lookup(struct listnode **hashtab, std::string key) {
    int index = hash(key);
    for (struct listnode *node = hashtab[index]; node != nullptr; node = node->next) {
        if (node->key == key) {
            return node;
        }
    }
    return nullptr;
}

void hashtab_delete(struct listnode **hashtab, std::string key) {
    int index = hash(key);
    struct listnode *prev = nullptr;
    for (struct listnode *p = hashtab[index]; p != nullptr; p = p->next) {
        if (p->key == key) {
            if (prev == nullptr)
                hashtab[index] = p->next;
            else
                prev->next = p->next;
            delete p;
            return;
        }
        prev = p;
    }
}