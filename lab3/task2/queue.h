#ifndef TASK2_QUEUE_H
#define TASK2_QUEUE_H

struct queuenode {
    int value;
    struct queuenode *next;
};

struct queue {
    struct queuenode *head;
    struct queuenode *tail;
    int size;
};

struct queue *queue_init();

void queue_push(struct queue *q, int value);

bool queue_is_empty(struct queue *q);

int queue_front(struct queue *q);

void queue_pop(struct queue *q);

#endif //TASK2_QUEUE_H
