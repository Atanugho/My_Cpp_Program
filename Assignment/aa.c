#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
}Node;

 Node* newNode(char data) {
    Node* node = ( Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push( Node** top, char data) {
     Node* node = newNode(data);
     node->next = *top;
     *top = node;
}

char pop( Node** top) {
    if (*top == NULL) {
        return '\0'; 
    }
    Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}


int checkParentheses(char* exp) {
    Node* stack = NULL;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&stack, exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char topChar = pop(&stack);
            if ((exp[i] == ')' && topChar != '(') ||
                (exp[i] == ']' && topChar != '[') ||
                (exp[i] == '}' && topChar != '{')) {
                return 0; 
            }
        }
    }
    return (stack == NULL); // If stack is empty, parentheses are valid
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (checkParentheses(expression)) {
        printf("Valid parentheses\n");
    } else {
        printf("Invalid parentheses\n");
    }
    return 0;
}