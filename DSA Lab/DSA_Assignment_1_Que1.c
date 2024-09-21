#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 500

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}


bool isEmpty(Stack *s)
{
    return s->top == -1;
}


bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}


void push(Stack *s, double value)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %lf onto the stack.\n", value);
        return;
    }
    s->data[++s->top] = value;
}


double pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1; 
    }
    return s->data[s->top--];
}


double peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty! No elements to peek.\n");
        return -1; 
    }
    return s->data[s->top];
}

double evaluatePostfix(char *expression) {
    Stack s;
    initStack(&s);
    char *token = strtok(expression, ", ");
    
    while (token != NULL) {
        // If the token is the ending character '#', break out of the loop
        if (token[0] == '#') {
            break;
        }

        // If the token is an operator, pop two operands from the stack, apply the operator
        if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            double operand2 = pop(&s); // Right operand
            double operand1 = pop(&s); // Left operand
            double result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator encountered: %s\n", token);
                    exit(EXIT_FAILURE);
            }
            push(&s, result);
        } else { 
            // Otherwise, the token is an operand (number), so we push it onto the stack
            double value = atof(token);  // Convert the token to a double
            push(&s, value);
        }

        // Get the next token
        token = strtok(NULL, ", ");
    }

    // The final result will be the only element left in the stack
    return pop(&s);
}

int main() {
    char expression[100];

    // Example postfix expression input: 5, 3, 4, -, -2, *, /, #
    printf("Enter the postfix expression (e.g. 5, 3, 4, -, -2, *, /, #):\n");
    fgets(expression, sizeof(expression), stdin);

    // Evaluate the postfix expression
    double result = evaluatePostfix(expression);

    // Print the result
    printf("Result: %lf\n", result);

    return 0;
}