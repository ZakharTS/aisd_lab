#include "queue.h"

struct queue *queue_init() {
    struct queue *temp = new struct queue;
    temp->size = 0;
    temp->head = nullptr;
    temp->tail = nullptr;
    return temp;
}

void queue_push(struct queue *q, int value) {
    struct queuenode *node = new struct queuenode;
    node->value = value;
    node->next = nullptr;
    if (queue_is_empty(q)) {
        q->head = node;
        q->tail = node;
        q->size++;
        return;
    }
    q->tail->next = node;
    q->tail = node;
    q->size++;
}

bool queue_is_empty(struct queue *q) {
    if (q->size == 0) return 1;
    return 0;
}

int queue_front(struct queue *q) {
    return q->head->value;
}

void queue_pop(struct queue *q) {
    if (queue_is_empty(q)) return;
    struct queuenode *temp = q->head;
    q->head = temp->next;
    q->size--;
    delete temp;
}