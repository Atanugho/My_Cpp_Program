
//a)Using the above functions declare 10 stacks and operate on them.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack {
    int top;
    int item[MAX];
} stk;

void create(stk *ps) {
    (ps)->top = -1;
}

int isempty(stk *ps) {
    if ((ps)->top == -1)
        return (1);
    else
        return (0);
}

int isfull(stk *ps) {
    if ((ps)->top == MAX - 1)
        return (1);
    else
        return (0);
}

int push(stk *ps, int x) {
    if (isfull(ps)) {
        return 0;
    } else {
        (ps)->item[++(ps)->top] = x;
        return 1;
    }
}

int pop(stk *ps, int *flag) {
    if (isempty(ps)) {
        *flag = 0;
    } else {
        *flag = 1;
        return (ps)->item[(ps)->top--];
    }
}

int top(stk *ps, int *flag) {
    if (isempty(ps)) {
        *flag = 0;
    } else {
        *flag = 1;
        return (ps)->item[(ps)->top];
    }
}

void display(stk *ps) {
    int i;
    if (ps->top == -1)
        printf("Stack is empty\n");
    else {
        printf("\nCurrent Stack is:\n");
        for (i = 0; i <= ps->top; i++)
            printf("%d\t", ps->item[i]);
    }
}

int main() {
    int op, x, ch, r;
    stk stacks[10];  // Array of 10 stacks
    for (int i = 0; i < 10; i++) {
        create(&stacks[i]); // Initialize each stack
    }

    while (1) {
        printf("\nMENU\n");
        printf("1: isempty\n2: push\n3: pop\n4: top\n5: display\n6: quit\n");
        printf("Enter your option\n");
        scanf("%d", &op);

        if (op >= 1 && op <= 5) {
            printf("Enter the stack number (0-9): ");
            int stackNumber;
            scanf("%d", &stackNumber);

            if (stackNumber >= 0 && stackNumber < 10) {
                switch (op) {
                    case 1:
                        x = isempty(&stacks[stackNumber]);
                        if (x)
                            printf("Stack %d is empty\n", stackNumber);
                        else
                            printf("Stack %d is not empty\n", stackNumber);
                        break;
                    case 2:
                        printf("Enter value to be pushed\n");
                        scanf(" %d", &ch);
                        r = push(&stacks[stackNumber], ch);
                        if (r)
                            printf("Item %d is pushed into Stack %d\n", ch, stackNumber);
                        else
                            printf("Stack %d is full\n", stackNumber);
                        break;
                    case 3:
                        x = pop(&stacks[stackNumber], &r);
                        if (r)
                            printf("Popped item from Stack %d is %d\n", stackNumber, x);
                        else
                            printf("Stack %d is empty\n", stackNumber);
                        break;
                    case 4:
                        x = top(&stacks[stackNumber], &r);
                        if (r)
                            printf("Top item in Stack %d is %d\n", stackNumber, x);
                        else
                            printf("Stack %d is empty\n", stackNumber);
                        break;
                    case 5:
                        display(&stacks[stackNumber]);
                        break;
                }
            } else {
                printf("Invalid stack number. Please enter a number between 0 and 9.\n");
            }
        } else if (op == 6) {
            exit(0);
        } else {
            printf("Invalid option. Please choose a valid option.\n");
        }
    }
    return 0;
}