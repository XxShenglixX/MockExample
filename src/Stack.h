#ifndef Stack_H
#define Stack_H

typedef struct 
{
	char *buffer;
	int size;
	int length;
}Stack;

Stack *stackNew(int length);
void stackDel(Stack *stack);

int stackPop(Stack *stackPtr);
void stackPush(Stack *stackPtr,int data);

int stackIsEmpty(Stack *stackptr); // 1 = empty
int stackIsFull(Stack *stackptr); // 1 = empty

#endif // Stack_H
