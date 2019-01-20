#include <stdio.h>
#include <stdlib.h>

struct stackType{
    int data;
    struct stackType *next;
};

int isEmpty(struct stackType *tos){
    if (tos){
        return 0;
    }
    return 1;
}

void outputStack(struct stackType *tos){
    struct stackType *stack = tos;
    if(tos->next){
        printf("%i \n", tos->data);
    }
    while(stack->next){
        stack = stack->next;
        printf("%i \n", stack->data);
    }
}

void push(int n, struct stackType **tos){
    struct stackType *temp = *tos;
    *tos = (struct stackType *) malloc(sizeof(struct stackType*));
    (*tos)->next = temp;
    (*tos)->data = n;
}

int pop(struct stackType **tos){
    int temp = (*tos)->data;
    struct stackType *tempFree = *tos;
    *tos = (*tos)->next;
    free(tempFree);
    return temp;
}

int main() {
    struct stackType *tos;
    tos = NULL;
    push(5, &tos);
    push(7, &tos);
    push(6, &tos);
    push(9, &tos);
    outputStack(tos);
    printf("Popped %i \n", pop(&tos));
    outputStack(tos);
}