/*
 *  Author:   Linus Lagerhjelm
 *  File:     stack.h
 *  Date:     2016-01-05
 *  Purpose:  Creates a headerfile for a stack implementation
 * 
 */

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef __STACK_H

typedef struct element {
  void *data;
  struct element *next;
} element;

typedef struct stack {
  unsigned int size;
  element *head;
} stack;


/*
 *  Function: new_stack()
 *  Purpose:  Creates a new stack
 *  Input:    (void)
 *  Output:   (stack *) pointer to the new stack 
 */
stack *new_stack();

/*
 *  Function: isEmpty() 
 *  Purpose:  Checks if the stack is empty 
 *  Input:    (stack *) pointer to the stack
 *  Output:   (int) 1/0 representing true or false 
 */
int isEmpty(stack *stack);

/*
 *  Function: stack_push() 
 *  Purpose:  Adds an element to the stack 
 *  Input:    (stack *) stack to add to
 *            (void *)  pointer to the data to add
 *  Output:   (void)  
 */
void  stack_push(stack *stack, void *data);

/*
 *  Function: stack_peek()
 *  Purpose:  Gets the first element in the stack without poping
 *  Input:    (stack *) stack to peek
 *  Output:   (void *) the data in the stack  
 */
void *stack_peek(stack *stack);

/*
 *  Function: stack_pop() 
 *  Purpose:  Retrieves the first element from the stack and removes it
 *  Input:    (stack *) stack to pop from
 *  Output:   (void *) the data in the stack  
 */
void *stack_pop(stack *stack);

/*
 *  Function: stack_delete()
 *  Purpose:  Removes the stack and all of its content
 *  Input:    (stack *) stack to remove
 *  Output:   (void) 
 */
void stack_delete(stack *stack);

element *new_element(void *val);
#endif
