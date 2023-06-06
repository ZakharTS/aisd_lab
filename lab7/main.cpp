#include <iostream>
#include "huffman.h"

int main() {
    encode("file.txt");
    decode("encoded-file.txt");
    return 0;
}
