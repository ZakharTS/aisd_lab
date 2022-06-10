#include <iostream>
#include <fstream>
#include <ctime>
#include "bstree.h"
#include "hashtab.h"

using namespace std;

int main() {
    ifstream fin("file.txt");
    string words[200000];
    for (int i = 0; fin >> words[i]; i++);
    struct listnode *hashtab[HASHTAB_SIZE];
    hashtab_add(hashtab, words[0], 0);
    hashtab_init(hashtab);
    struct bstree *tree = bstree_create(words[0], 0);
    for (int i = 0; i < 20; i++) {
        cout << i + 1 << ")" << endl;
        for (int j = 0; j < 9999; j++) {
            hashtab_add(hashtab, words[j + i * 10000], 0);
            bstree_add(tree, words[j + i * 10000], 0);
        }
        clock_t time = clock();
        hashtab_add(hashtab, words[9999 + i * 10000], 0);
        cout << "hashtab_add " << clock() - time << endl;
        time = clock();
        bstree_add(tree, words[9999 + i * 10000], 0);
        cout << "bstree_add " << clock() - time << endl;
        int random = rand() % ((i + 1) * 10000);
        time = clock();
        hashtab_lookup(hashtab, words[random]);
        cout << "hashtab_lookup " << clock() - time << endl;
        time = clock();
        bstree_lookup(tree, words[random]);
        cout << "bstree_lookup " << clock() - time << endl;
    }
    return 0;
}
