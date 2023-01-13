#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void push(struct Stack *s, int element) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
    } else {
        s->data[++s->top] = element;
        printf("Pushed %d to stack\n", element);
    }
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    } else {
        int popped = s->data[s->top--];
        printf("Popped %d from stack\n", popped);
        return popped;
    }
}

int peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    s.top = -1;

    int choice, element;
    while (1) {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&s, element);
                display(&s);
                break;
            case 2:
                pop(&s);
                display(&s);
                break;
            case 3:
                printf("Top element: %d\n", peek(&s));
                display(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
