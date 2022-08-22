#include <stdio.h>
#include "./stack.h"

#define MAX 100

int ai = 0; // actual index
double stack[MAX];

/* pop double from stack if there is element from stack */
double pop() {
    if (ai != 0) {
        return stack[--ai];
    }
    printf("There is no more elements in stack");
    return 0.0;
}

/* push double to stack if stack not full */
void push(double c) {
    if (ai < MAX) {
        stack[ai++] = c;
    }
    else {
        printf("%f cant be push, reached stack maximum capacity", c);
    }
}
