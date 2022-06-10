#include "bstree.h"

struct bstree *bstree_create(std::string key, int value) {
    struct bstree *node;
    node = (bstree *)(malloc(sizeof(*node)));
    if (node != nullptr) {
        node->key = key;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
    }
    return node;
}

void bstree_add(struct bstree *tree, std::string key, int value) {
    struct bstree *parent, *node;
    if (tree == nullptr) return;
    while (tree != nullptr) {
        if (key < tree->key)
            tree = tree->left;
        else if (key > tree->key)
            tree = tree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (key < tree->key)
        tree->left = node;
    else
        tree->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, const char * key) {
    while (tree != NULL) {
        if (key == tree->key) {
            return tree;
        } else if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

struct bstree *bstree_min(struct bstree *tree) {
    if (tree == nullptr)
        return nullptr;
    while (tree->left != nullptr)
        tree = tree->left;
    return tree;
}

struct bstree *bstree_max(struct bstree *tree) {
    if (tree == nullptr)
        return nullptr;
    while (tree->right != nullptr)
        tree = tree->right;
    return tree;
}