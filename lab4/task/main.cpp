#include <bits/stdc++.h>
#include <stdlib.h>
#include "bstree.h"
#include "hashtab.h"

using namespace std;

int main() {
    ifstream fin("file.txt");
    vector<string> words;
    for (int i = 0; i < 200000; i++) {
        string tmp;
        fin >> tmp;
        words.push_back(tmp);
    }
    cout << "Average case." << endl;
    struct bstree *tree = bstree_create(words[0], 0);
    struct listnode *hashtab[10000];
    hashtab_init(hashtab);
    for (int i = 0; i < 200000; i++) {
        if ((i + 1) % 10000 == 0) {
            cout << (i + 1) / 10000 << ") " << endl;
            clock_t time = clock();
            bstree_add(tree, words[i], i);
            cout << "bstree_add " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            bstree_lookup(tree, words[rand() % (i + 1)]);
            cout << "bstree_lookup " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            bstree_min(tree);
            cout << "bstree_min " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            bstree_max(tree);
            cout << "bstree_max " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;

            time = clock();
            hashtab_add(hashtab, words[i], i);
            cout << "hashtab_add " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            hashtab_lookup(hashtab, words[rand() % (i + 1)]);
            cout << "hashtab_lookup " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
        } else {
            hashtab_add(hashtab, words[i], i);
            bstree_add(tree, words[i], i);
        }
    }
    cout << endl;

    sort(words.begin(), words.end());
    tree = bstree_create(words[0], 0);
    hashtab_init(hashtab);
    cout << "Worst case." << endl;
    for (int i = 0; i < 200000; i++) {
        if ((i + 1) % 10000 == 0) {
            cout << (i + 1) / 10000 << ") " << endl;
            clock_t time = clock();
            bstree_add(tree, words[i], i);
            cout << "bstree_add " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            bstree_lookup(tree, words[i]);
            cout << "bstree_lookup " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            bstree_max(tree);
            cout << "bstree_max " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;

            time = clock();
            hashtab_add(hashtab, words[i], i);
            cout << "hashtab_add " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
            time = clock();
            hashtab_lookup(hashtab, words[i]);
            cout << "hashtab_lookup " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
        } else {
            hashtab_add(hashtab, words[i], i);
            bstree_add(tree, words[i], i);
        }
    }

    tree = bstree_create(words[0], 0);
    for (int i = 0; i < 200000; i++) {
        bstree_add(tree, words[200000 - 1 - i], i);
        if ((i + 1) % 10000 == 0) {
            cout << (i + 1) / 10000 << ") " << endl;
            clock_t time = clock();
            bstree_min(tree);
            cout << "bstree_min " << (float) (clock() - time) / CLOCKS_PER_SEC << endl;
        }
    }
    return 0;
}