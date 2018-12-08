#include <stdio.h>
#include <stdlib.h>

#define ERROR -6666

typedef struct {
    int top;               /* index of the top of the stack */
    unsigned int capacity; /* The maximum number of items in the stack */
    int *data;             /* pointer to the stack data */
} Stack;

/* Creates a new stack with a given capacity */
Stack *create_stack(unsigned int capacity) {
    
    Stack * s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->data = (int *)malloc(sizeof(int)*capacity);
    return s;

}

/* Checks if the stack is full */
int is_full(Stack *stack) {
   
    if(stack->top == stack->capacity-1){
        return 1;
    }
    return 0;
}

/* Checks if the stack is empty */
int is_empty(Stack *stack) {
    
    if(stack->top == -1){
        return 1;
    }
    return 0;


}

/* Double the stack capacity */
void double_capacity(Stack *stack) {
    
    stack->capacity = stack->capacity*2;
    stack->data = (int *)realloc(stack->data,sizeof(int)*stack->capacity);
}

/* Inserts an integer to the top of the stack.
 * If the stack is full, double its capacity
 * and then insert.
 */
void push(Stack *stack, int item) {

    if(is_full(stack)){
        
        double_capacity(stack);
    }

    stack->top += 1;
    int i = stack->top;
    stack->data[i] = item;
}

/* Removes the data at the top of the stack
 * and returns it. If the stack is empty, return ERROR.
 */
int pop(Stack *stack) {

    if(is_empty(stack)){
        return ERROR;
    }

    int num = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top -= 1;
    return num;
}

/* Deallocates all items in the stack, including
 * the stack itself
 */
void free_stack(Stack *stack) {
    
    free(stack->data);
    free(stack);
}

int main() {
    Stack *stack = create_stack(2);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));

    free_stack(stack);
    return 0;
}
