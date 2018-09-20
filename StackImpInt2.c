#include <stdio.h>
#define MAXSTACKLENGTH 6
#define true 1
#define false 0

/* Stack operations where
 * stack pointer is passed to functions
 */
struct stk{
    int content[MAXSTACKLENGTH];
    int top;
};

typedef struct stk stack;

int size(stack *s)
{
    return s->top;
}

int isEmpty(stack *s)
{
    if (size(s) <= -1)
    {
        return true;
    }
    else if (size(s) > -1)
    {
        return false;
    }
}

int isFull(stack *s) {
    if (size(s) == (MAXSTACKLENGTH-1))
    {
        return true;
    }
    else {
        return false;
    }
}

int peek(stack *s)
{
    if (isEmpty(s) == true)
    {
        printf("Can't peek: Stack is empty!\n");
        return '\0';
    }
    else {
        return s->content[s->top];
    }
}

void push(stack *s, int element)
{
    if (isFull(s) == true)
    {
        printf("Cant push: Stack is full!\n");
    }
    else {
        s->top++;
        s->content[s->top] = element;
    }
}

void pop(stack *s)
{
    if (isEmpty(s) == true) {
        printf("Cant pop: Stack is empty!\n");
    }
    else {
    	printf ("popped element is = %d \n", s->content[s->top]);
        s->top--;
    }
}

void input_push(stack *s)
{
    int c;
    printf("Enter an integer> ");
    scanf(" %d", &c);

    push(s, c);
}

void print_stack(stack *s)
{
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    }
    else {
        int i = s->top;

        for (i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->content[i]);
        }

        printf("\n");
    }
}


int main()
{
    printf("SimpleStack! v1\n");

    stack mystack;
    mystack.top = -1; //Empty

    int choice = 0;

    while (1)
    {
        if (isFull(&mystack))
        {
            printf("Warning -> Stack is full\n");
        }
        if (isEmpty(&mystack))
        {
            printf("Warning -> Stack is empty\n");
        }
        printf("1 -> Push\n");
        printf("2 -> Pop\n");
        printf("3 -> Peek\n");
        printf("4 -> Print Stack\n");
        printf("5 -> Exit\n");

        printf("Enter choice> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_push(&mystack);

                break;
            case 2:
                pop(&mystack);

                break;
            case 3:
                printf("%c\n", peek(&mystack));
                break;
            case 4:
                print_stack(&mystack);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");

                break;
        }

        //system("clear");
    }

    return 0;
}
