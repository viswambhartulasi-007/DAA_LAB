#include <stdio.h>
#define MAX 100

struct stack {
    int a[MAX];
    int top;
};

void init(struct stack *s) {
    s->top = -1;
}

void push(struct stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack is Full\n");
    } else { 
        (s->top)++;
        s->a[s->top] = value;
        printf("Value %d is pushed into the stack.\n", value);
    }
}

int pop(struct stack *s) {
    int popped_val;
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        popped_val = s->a[s->top];
        (s->top)--;
        return popped_val;
    }
}

void peek(struct stack *s) {
    if (s->top == -1) {
        printf("Empty Stack.\n");
    } else {
        printf("Peek Value: %d\n", s->a[s->top]);
    }
}

void display(struct stack *s) {
    if (s->top == -1) {
        printf("Empty Stack.\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->a[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack s;
    init(&s);

    push(&s, 12);
    push(&s, 11);
    push(&s, 13);
    push(&s, 1);
    push(&s, 5);
    push(&s, 20);

    display(&s);

    int n = pop(&s);
    if (n != -1) {
        printf("Value popped: %d\n", n);
    }

    display(&s);

    peek(&s);

    return 0;
}
