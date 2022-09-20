#include "bstree.h"

struct bstree *bstree_create(std::string key, int value) {
    struct bstree *node = new struct bstree;
    node->key = key;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void bstree_add(struct bstree *tree, std::string key, int value) {
    struct bstree *parent = tree, *node;
    if (tree == nullptr) return;
    while (tree != nullptr) {
        parent = tree;
        if (key < tree->key)
            tree = tree->left;
        else if (key > tree->key)
            tree = tree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (key < parent->key)
        parent->left = node;
    else if (key > parent->key)
        parent->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, std::string key) {
    while (tree != nullptr) {
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