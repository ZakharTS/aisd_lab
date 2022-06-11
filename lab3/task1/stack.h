#ifndef TASK1_STACK_H
#define TASK1_STACK_H

#include <string>

struct stacknode {
    std::string value;
    struct stacknode *next;
};

struct stack {
    struct stacknode *top;
    int size;
};

struct stack *stack_init();

void stack_push(struct stack *s, std::string value);

bool stack_is_empty(struct stack *s);

std::string stack_top(struct stack *s);

void stack_pop(struct stack *s);

#endif //TASK1_STACK_H
