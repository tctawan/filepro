/* Name: Tawan Chaeyklinthes
 * ID: 5980963
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    
    if(*q == NULL){
        *q = (Queue *)malloc(sizeof(Queue));
        (*q)->head = NULL;
        (*q)->tail = NULL;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = (char *)malloc(sizeof(word));
    strcpy(n->data, word);
    n->next = NULL;


    if(isEmpty(*q)){
        (*q)->head = n;
        (*q)->tail = n;
    }else{
        Node *prev = (*q)->tail;
        prev->next  = n;
        (*q)->tail = n;
    }

}

char *pop(Queue *q) {
    if(!isEmpty(q)){
        Node *zombie = q->head;
        char *word = zombie->data;
        q->head = zombie->next;
        free(zombie);
        return word;

    }else{
        return NULL;
    }
}

void print(Queue *q) {
    if(isEmpty(q)){
        printf("No items\n");
    }
    else{
        Node *n = (q)->head;
        while(n){
            printf("%s\n",n->data);
            n = n->next;
        }
    }
}

int isEmpty(Queue *q) {
    if(q != NULL && q->head != NULL && q->tail != NULL){
        return 0;
    }
    return 1;
}

void delete(Queue *q) {
    while(!isEmpty(q)){
        char *word= pop(q);
        free(word);
    }
    q->head = NULL;
    q->tail = NULL;
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
   print(q);


    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n",item);
        free(item);
    }
    char *item = pop(q);
    assert(item == NULL);

    // push again
    
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
