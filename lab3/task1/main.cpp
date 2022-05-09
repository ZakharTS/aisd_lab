#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stack<string> tags;
    bool isRight = true;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<') {
            string current;
            i++;
            for (; i < input.length() && input[i] != '>'; i++) {
                if (input[i] == ' ') {
                    while (i < input.length() && input[i] != '>') i++;
                    break;
                }
                current += input[i];
            }
            if (current[0] == '/') {
                string temp = current;
                current.erase(0, 1);
                if (tags.empty()) {
                    cout << "No pair for <" << temp << ">" << endl;
                    isRight = false;
                    continue;
                }
                if (current == tags.top()) {
                    tags.pop();
                } else {
                    cout << "No pair for <" << temp << "> or wrong tag closing." << endl;
                    isRight = false;
                    continue;
                }
            } else {
                tags.push(current);
            }
        }
    }
    while (!tags.empty()) {
        cout << "No pair for <" << tags.top() << ">" << endl;
        isRight = false;
        tags.pop();
    }
    if (isRight) {
        cout << "Everything is right." << endl;
    }
    return 0;
}
