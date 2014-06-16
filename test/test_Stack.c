#include "unity.h"
#include "Stack.h"
#include <malloc.h>
#include <stdio.h>
#include "CException.h"
#include "ErrorCode.h"

void setUp(void)
{
	
}

void tearDown(void)
{
	
}

void test_stackIsEmpty_should_return_1_for_empty_stack()
{
	Stack *stack = stackNew(6);
	
	TEST_ASSERT_EQUAL(1,stackIsEmpty(stack));
	
	stackDel(stack);
}

void test_stackIsEmpty_size_1_should_return_0_for_not_empty_stack()
{
	Stack *stack = stackNew(6);
	stack->size = 1;
	
	TEST_ASSERT_EQUAL(0,stackIsEmpty(stack));
	
	stackDel(stack);
}

void test_stackIsFull_given_size_6_should_return_1_for_full_stack()
{
	Stack *stack = stackNew(6);
	stack->size = 6;
	
	TEST_ASSERT_EQUAL(1,stackIsFull(stack));
	
	stackDel(stack);
}

void test_stackIsFull_given_size_5_should_return_0_as_stack_is_not_full_yet()
{
	Stack *stack = stackNew(6);
	stack->size = 5;
	
	
	TEST_ASSERT_EQUAL(0,stackIsFull(stack));
	
	stackDel(stack);
}

void test_stackNew_given_6_should_allotcate_Stack_obeject_with_a_buffer_of_6()
{
	Stack *stack = stackNew(6);
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NOT_NULL(stack->buffer);
	TEST_ASSERT_EQUAL(6,stack->length);
	TEST_ASSERT_EQUAL(0,stack->size);

	stackDel(stack);
}

void test_stackPush_given_size_6_length_6_should_return_error()
{
	CEXCEPTION_T err;
	
	Stack *stack = stackNew(6);
	stack->size = 6;
	
	Try
	{
		stackPush(stack,'a');
		TEST_FAIL_MESSAGE("Error should generate exception due to full stack");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_STACK_FULL,err);
		printf("Error [%d] : Stack is full",err);
	}
	
	stackDel(stack);
}

void test_stackPush_given_a_should_return_a_for_data_and_size_1()
{
	Stack *stack = stackNew(6);
	
	stackPush(stack,'a');
	
	TEST_ASSERT_EQUAL('a',*(stack->buffer-1));
	TEST_ASSERT_EQUAL(1,stack->size);
	
	stackDel(stack);
}

void test_stackPush_given_a_b_c_should_return_a_b_c_for_data_and_size_3()
{
	Stack *stack = stackNew(6);
	
	stackPush(stack,'a');
	TEST_ASSERT_EQUAL('a',*(stack->buffer-1));
	stackPush(stack,'b');
	TEST_ASSERT_EQUAL('b',*(stack->buffer-1));
	stackPush(stack,'c');
	TEST_ASSERT_EQUAL('c',*(stack->buffer-1));
	
	
	TEST_ASSERT_EQUAL(3,stack->size);
	
	stackDel(stack);
}

void test_stackPush_given_a_b_c_d_e_f_g_should_return_size_6_and_throw_an_error()
{
	Stack *stack = stackNew(6);
	CEXCEPTION_T err;
	Try
	{
		stackPush(stack,'a');
		stackPush(stack,'b');
		stackPush(stack,'c');
		stackPush(stack,'d');
		stackPush(stack,'e');
		stackPush(stack,'f');
		stackPush(stack,'g');
		TEST_FAIL_MESSAGE("Error should generate exception due to full stack");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_STACK_FULL,err);
		printf("Error [%d] : Stack is full",err);
	}
	TEST_ASSERT_EQUAL(6,stack->size);
	stackDel(stack);
}

 void test_stackPop_x1_a_b_c_size_0_should_throw_an_error()
{
	Stack *stack = stackNew(6);
	CEXCEPTION_T err;
	
	Try
	{
		stackPush(stack,'a');
		stackPush(stack,'b');
		stackPush(stack,'c');
	
		stack->size = 0; 
		stackPop(stack);
		TEST_FAIL_MESSAGE("Error should generate an error due to empty stack");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_STACK_EMPTY,err);
		printf("Error [%d] : Stack is empty",err);
	}
	
	stackDel(stack);
} 


void test_stackPop_x1_given_a_b_c_should_return_c_for_data_and_size_2()
{
	Stack *stack = stackNew(6);
	
	stackPush(stack,'a');
	TEST_ASSERT_EQUAL('a',*(stack->buffer-1));
	stackPush(stack,'b');
	TEST_ASSERT_EQUAL('b',*(stack->buffer-1));
	stackPush(stack,'c');
	
	TEST_ASSERT_EQUAL('c',stackPop(stack));
	TEST_ASSERT_EQUAL(2,stack->size);
	
	stackDel(stack);
} 

void test_stackPop_x3_given_a_b_c_should_return_c_b_a_for_data_and_size_0()
{
	Stack *stack = stackNew(6);
	
	stackPush(stack,'a');
	stackPush(stack,'b');
	stackPush(stack,'c');
	
	TEST_ASSERT_EQUAL('c',stackPop(stack));
	TEST_ASSERT_EQUAL('b',stackPop(stack));
	TEST_ASSERT_EQUAL('a',stackPop(stack));

	TEST_ASSERT_EQUAL(0,stack->size);

	stackDel(stack);
} 

void test_stackPop_x4_given_a_b_c_should_return_c_b_a_for_data__size_0_and_throw_an_error()
{
	Stack *stack = stackNew(6);
	CEXCEPTION_T err;
	
	Try
	{
		stackPush(stack,'a');
		stackPush(stack,'b');
		stackPush(stack,'c');
	
		TEST_ASSERT_EQUAL('c',stackPop(stack));
		TEST_ASSERT_EQUAL('b',stackPop(stack));
		TEST_ASSERT_EQUAL('a',stackPop(stack));
		stackPop(stack);
		TEST_FAIL_MESSAGE("Error should generate an error due to empty stack");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_STACK_EMPTY,err);
		printf("Error [%d] : Stack is empty",err);
	}

	TEST_ASSERT_EQUAL(0,stack->size);
	
	stackDel(stack);
}