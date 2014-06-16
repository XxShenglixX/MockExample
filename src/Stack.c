#include "Stack.h"
#include <stdio.h>
#include <malloc.h>
#include "CException.h"
#include "ErrorCode.h"

/**
 * Create a stack of specific buffer length
 *
 * Input:
 *	stack is the Stack object to delete
 *	length is the length of the stack
 */
Stack *stackNew(int length)
{
	Stack *stack;
	char *buffer;
	stack = malloc(sizeof(Stack));
	buffer = malloc(sizeof(char) * length);
	stack->buffer=buffer;
	stack->length = length;
	stack->size = 0;
}

/**
 * Delete the Stack object
 *
 * Input:
 *	stack is the Stack object to delete
 */
void stackDel(Stack *stack)
{
	if (stack != NULL)
	{
		free(stack->buffer);
		free(stack);
	}
}

/**
 * Pop out an integer out from the stack
 *
 * Input:
 *	stackPtr is the stack with integers
 * 
 * Output:
 *	data is the integer pop out from the stack
 *
 * If stack is empty, will throw ERR_STACK_EMPTY
 */
int stackPop(Stack *stackPtr)
{
	int data ;
	if (stackIsEmpty(stackPtr))
		Throw(ERR_STACK_EMPTY);
		
	else 
		stackPtr->buffer--;

	data = *stackPtr->buffer;
	stackPtr->size -- ;
	
	return data;
}

/** Push a integer into the stack
 *
 * Input:
 *	stackPtr is the stack that going to be pushed
 *	data is the integer that wishes to be pushed into the stack
 * 
 * If stack is full, will throw ERR_STACK_FULL
 */
void stackPush(Stack *stackPtr,int data)
{
	if (stackIsFull(stackPtr))
		Throw(ERR_STACK_FULL);
		
	*stackPtr->buffer = data;
	stackPtr->size ++;
	
	stackPtr->buffer ++;
}

/** Check if stack is empty by looking at the size of the stack
 *
 * Input:
 * stackptr is the stack that is going to be checked
 *
 * Output:
 *	1 if stack is empty , 0 if stack is not empty
 */
int stackIsEmpty(Stack *stackptr)
{
	if (stackptr->size == 0 )
		return 1;
		
	else 
		return 0;
}

/** Check if stack is full by looking at the size of the stack
 *
 * Input:
 * stackptr is the stack that is going to be checked
 *
 * Output:
 *	1 if stack is full , 0 if stack is not full
 */
int stackIsFull(Stack *stackptr)
{
	if (stackptr->size == stackptr->length )
		return 1;
		
	else 
		return 0;
}