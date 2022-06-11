#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    string input;
    getline(cin, input);
    struct stack *tags = stack_init();
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
                if (stack_is_empty(tags)) {
                    cout << "No pair for <" << temp << ">" << endl;
                    isRight = false;
                    continue;
                }
                if (current == stack_top(tags)) {
                    stack_pop(tags);
                } else {
                    cout << "No pair for <" << temp << "> or wrong tag closing." << endl;
                    isRight = false;
                    continue;
                }
            } else {
                stack_push(tags, current);
            }
        }
    }
    while (!stack_is_empty(tags)) {
        cout << "No pair for <" << stack_top(tags) << ">" << endl;
        isRight = false;
        stack_pop(tags);
    }
    if (isRight) {
        cout << "Everything is right." << endl;
    }
    return 0;
}
