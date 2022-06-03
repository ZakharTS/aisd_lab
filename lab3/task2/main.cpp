#include <iostream>
#include <queue>

using namespace std;

queue<int> to_one_queue(queue<int>, queue<int>);

queue<int> to_one_queue_sorted(queue<int>, queue<int>);

int main() {
    queue<int> A, B;
    cout << "A: ";
    for (int i = 3; i <= 11; i += 2) {
        cout << i << " ";
        A.push(i);
    }
    cout << endl << "B: ";
    for (int i = 1; i <= 13; i += 3) {
        cout << i << " ";
        B.push(i);
    }
    cout << endl;
    queue<int> result;
    result = to_one_queue(A, B);
    cout << "To one queue: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    result = to_one_queue_sorted(A, B);
    cout << endl << "To one queue sorted: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl << endl;
    return 0;
}

queue<int> to_one_queue(queue<int> A, queue<int> B) {
    queue<int> total;
    while (!A.empty() && !B.empty()) {
        total.push(A.front());
        A.pop();
        total.push(B.front());
        B.pop();
    }
    return total;
}

queue<int> to_one_queue_sorted(queue<int> A, queue<int> B) {
    queue<int> total;
    while (!A.empty() || !B.empty()) {
        if (A.empty()) {
            while (!B.empty()) {
                total.push(B.front());
                B.pop();
            }
            break;
        }
        if (B.empty()) {
            while (!A.empty()) {
                total.push(A.front());
                A.pop();
            }
            break;
        }
        if (A.front() < B.front()) {
            total.push(A.front());
            A.pop();
        } else {
            total.push(B.front());
            B.pop();
        }
    }
    return total;
}