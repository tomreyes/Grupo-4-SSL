#include <stdio.h>
#include "./stack.h"
#include "./get_token.h"
#include <math.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = get_token(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break; 
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Cant have zero as divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0) {
                    //push((int) pop() % (int) op2); // int modulus
                    push(fmod(pop(), op2)); // double modulus
                } else
                    printf("Cant have zero as modulus\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Unknown command %s\n", s);
                break;
        }
    }
    return 0;
}