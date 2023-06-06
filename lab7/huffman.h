#ifndef MAIN_CPP_HUFFMAN_H
#define MAIN_CPP_HUFFMAN_H

#include <bits/stdc++.h>

using namespace std;

struct node {
    char ch;
    int freq;
    node *left;
    node *right;
};

struct comp {
    bool operator()(node *a, node *b) {
        return a->freq > b->freq;
    }
};

void encode(string fileName);

void decode(string fileName);

void getHuffmanCodes(node *root, map<char, vector<bool>> &HuffmanCode, vector<bool> code);

node *createNode(char ch, int freq, node *left, node *right);

void fillFrequenciesFromDecodedFile(map<char, int> &frequencies, string fileName);

node *buildHuffmanTree(const map<char, int> &frequencies);

void fillFrequenciesFromEncodedFile(map<char, int> &frequencies, string fileName);

#endif