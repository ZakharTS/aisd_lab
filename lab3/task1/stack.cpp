#include "stack.h"

struct stack *stack_init() {
    struct stack *temp = new struct stack;
    temp->size = 0;
    temp->top = nullptr;
    return temp;
}

void stack_push(struct stack *s, std::string value) {
    struct stacknode *node = new struct stacknode;
    node->next = s->top;
    node->value = value;
    s->top = node;
    s->size++;
}
bool stack_is_empty(struct stack *s) {
    if (s->size == 0) return 1;
    return 0;
}

std::string stack_top(struct stack *s) {
    return s->top->value;
}

void stack_pop(struct stack *s) {
    if (stack_is_empty(s)) return;
    struct stacknode *temp;
    temp = s->top;
    s->size--;
    s->top = temp->next;
    delete temp;
}