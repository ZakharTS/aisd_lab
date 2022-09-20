#ifndef TASK_BSTREE_H
#define TASK_BSTREE_H

#include <stdlib.h>
#include <string>

struct bstree {
    std::string key;
    int value;
    struct bstree *left;
    struct bstree *right;
};

struct bstree *bstree_create(std::string key, int value);

void bstree_add(struct bstree *tree, std::string key, int value);

struct bstree *bstree_lookup(struct bstree *tree, std::string key);

struct bstree *bstree_min(struct bstree *tree);

struct bstree *bstree_max(struct bstree *tree);

#endif