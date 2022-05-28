#include <iostream>
#include <fstream>
#include "bstree.h"

using namespace std;

int main() {
    ifstream fin("file.txt");
    for (int i = 1; i <= 20; i++) {
        cout << i << ")" << endl;
        for (int j = 0; j < 10000; j++) {
            char * temp;
            fin >> temp;
            
        }
    }
    return 0;
}
