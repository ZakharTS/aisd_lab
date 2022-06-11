#include <iostream>
#include "queue.h"

using namespace std;

void queue_fill(struct queue *A, struct queue *B);

struct queue *to_one_queue(struct queue *A, struct queue *B);

struct queue *to_one_queue_sorted(struct queue *A, struct queue *B);

int main() {
    struct queue *A = queue_init(), *B = queue_init();
    queue_fill(A, B);
    struct queue *result;
    result = to_one_queue(A, B);
    cout << "To one queue: ";
    while (!queue_is_empty(result)) {
        cout << queue_front(result) << " ";
        queue_pop(result);
    }
    cout << endl;
    queue_fill(A, B);
    result = to_one_queue_sorted(A, B);
    cout << "To one queue sorted: ";
    while (!queue_is_empty(result)) {
        cout << queue_front(result) << " ";
        queue_pop(result);
    }
    cout << endl << endl;
    return 0;
}

void queue_fill(struct queue *A, struct queue *B) {
    cout << "A: ";
    for (int i = 3; i <= 11; i += 2) {
        cout << i << " ";
        queue_push(A, i);
    }
    cout << endl << "B: ";
    for (int i = 1; i <= 13; i += 3) {
        cout << i << " ";
        queue_push(B, i);
    }
    cout << endl;
}

struct queue *to_one_queue(struct queue *A, struct queue *B) {
    struct queue *total = queue_init();
    while (!queue_is_empty(A) && !queue_is_empty(B)) {
        queue_push(total, queue_front(A));
        queue_pop(A);
        queue_push(total, queue_front(B));
        queue_pop(B);
    }
    return total;
}

struct queue *to_one_queue_sorted(struct queue *A, struct queue *B) {
    struct queue *total = queue_init();
    while (!queue_is_empty(A) || !queue_is_empty(B)) {
        if (queue_is_empty(A)) {
            while (!queue_is_empty(B)) {
                queue_push(total, queue_front(B));
                queue_pop(B);
            }
            break;
        }
        if (queue_is_empty(B)) {
            while (!queue_is_empty(A)) {
                queue_push(total, queue_front(A));
                queue_pop(A);
            }
            break;
        }
        if (queue_front(A) < queue_front(B)) {
            queue_push(total, queue_front(A));
            queue_pop(A);
        } else {
            queue_push(total, queue_front(B));
            queue_pop(B);
        }
    }
    return total;
}