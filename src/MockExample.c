#include "MockExample.h"
#include "Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *reverseString(char *stringToReverse)
{	int i ,j=0;
	char *reversedString;
	Stack *stack = stackNew(512);
	
	printf("stack :%p \n",stack);
	printf("size :%d \n",stack->size);
	printf("length :%d \n",stack->length);
	
	

	
	for (i=0; i < strlen(stringToReverse) ;i ++)
	{
		stackPush(stack,(int)stringToReverse[i]);
		printf("%c",stringToReverse[i]);
	}
	
	printf("\n");
	reversedString = malloc(sizeof(char) * (i+1));
	
	//while (i-- )
	while(!stackIsEmpty(stack))
	{
		reversedString[j++] = stackPop(stack);
		printf("%c",reversedString[j-1]);
	}
	reversedString[j] = '\0';
	
	return reversedString;
}
