#include "huffman.h"

void encode(string fileName) {
    map<char, vector<bool>> HuffmanCode;
    vector<bool> empty;
    map<char, int> frequencies;

    fillFrequenciesFromDecodedFile(frequencies, fileName);
    node *root = buildHuffmanTree(frequencies);
    getHuffmanCodes(root, HuffmanCode, empty);

    ifstream fin(fileName, ios::out | ios::binary);
    ofstream fout("encoded-" + fileName, ios::out | ios::binary);

    fout << frequencies.size() << " ";
    for (auto i: frequencies) {
        fout << (int) i.first << " " << i.second << " ";
    }
    fout << '\0';

    int count = 0;
    char buf = 0;
    while (!fin.eof()) {
        char c = fin.get();
        vector<bool> tmp = HuffmanCode[c];
        for (int n = 0; n < tmp.size(); n++) {
            buf = buf | tmp[n] << (7 - count);
            count++;
            if (count == 8) {
                fout << buf;
                count = 0;
                buf = 0;
            }
        }
    }

}

void getHuffmanCodes(node *root, map<char, vector<bool>> &HuffmanCode, vector<bool> code) {
    if (root->left == nullptr && root->right == nullptr) {
        HuffmanCode[root->ch] = code;
        return;
    }
    if (root->left != nullptr) {
        code.push_back(0);
        getHuffmanCodes(root->left, HuffmanCode, code);
        code.pop_back();
    }
    if (root->right != nullptr) {
        code.push_back(1);
        getHuffmanCodes(root->right, HuffmanCode, code);
        code.pop_back();
    }
}

node *buildHuffmanTree(const map<char, int> &frequencies) {
    priority_queue<node *, vector<node *>, comp> pq;
    for (auto i: frequencies) {
        pq.push(createNode(i.first, i.second, nullptr, nullptr));
    }
    while (pq.size() != 1) {
        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();
        int totalFreq = right->freq + left->freq;
        pq.push(createNode('\0', totalFreq, left, right));
    }
    return pq.top();
}

node *createNode(char ch, int freq, node *left, node *right) {
    node *nd = new node;
    nd->ch = ch;
    nd->freq = freq;
    nd->left = left;
    nd->right = right;
    return nd;
}

void fillFrequenciesFromDecodedFile(map<char, int> &frequencies, string fileName) {
    ifstream fin(fileName, ios::out | ios::binary);

    char c = fin.get();
    while (!fin.eof()) {
        frequencies[c]++;
        c = fin.get();
    }

    fin.close();
}

void decode(string fileName) {
    map<char, vector<bool>> HuffmanCode;
    vector<bool> empty;
    map<char, int> frequencies;


    fillFrequenciesFromEncodedFile(frequencies, fileName);
    node *root = buildHuffmanTree(frequencies);
    getHuffmanCodes(root, HuffmanCode, empty);

    ifstream fin(fileName, ios::in | ios::binary);
    ofstream fout("decoded-" + fileName, ios::out | ios::binary);

    while (fin.get() != '\0');

    char byte;
    bool curBit;
    node *ptrNode = root;
    while (!fin.eof()) {
        byte = fin.get();
        for (int i = 0; i < 8; ++i) {
            curBit = byte & (1 << (7 - i));
            if (curBit == 0) ptrNode = ptrNode->left;
            else ptrNode = ptrNode->right;
            if (ptrNode->left == nullptr && ptrNode->right == nullptr) {
                fout << ptrNode->ch;
                ptrNode = root;
            }
        }
    }

    fout.close();
    fin.close();
}

void fillFrequenciesFromEncodedFile(map<char, int> &frequencies, string fileName) {
    ifstream fin(fileName);
    int frequency, ch, count;
    fin >> count;
    for (int i = 0; i < count; ++i) {
        fin >> ch >> frequency;
        frequencies[(char) ch] = frequency;
    }
    fin.close();
}