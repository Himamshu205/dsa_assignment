#include <stdio.h>
#include <string.h>

#define MAX 100

/* ---------------- Stack ---------------- */

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char ch) {
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

/* ------------ Parenthesis Check ------------ */

int isBalanced(const char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            push(&s, '(');
        } else if (expr[i] == ')') {
            if (isEmpty(&s)) {
                return 0;
            }
            pop(&s);
        }
    }
    return isEmpty(&s);
}

/* ----------------- Main ----------------- */

int main() {
    const char *expressions[] = {
        "a + (b - c) * (d",
        "m + (a - b * (c + d * (m)))",
        "a + (b - c)"
    };

    int n = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < n; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (isBalanced(expressions[i])) {
            printf("Result: Balanced parentheses\n\n");
        } else {
            printf("Result: Not balanced parentheses\n\n");
        }
    }

    return 0;
}
