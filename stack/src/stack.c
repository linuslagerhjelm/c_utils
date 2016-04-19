/*
 * Author:   Linus Lagerhjelm
 * File:     stack.c
 * Date:     2016-01-05
 * Purpose:  Creates an implementation for a stack 
 *
 */

#include "../includes/stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef __STACK_C
#define __STACK_C
/*
 *  Function: new_stack()
 *  Purpose:  Creates a new stack
 *  Input:    (void)
 *  Output:   (stack *) pointer to the new stack 
 */
stack *new_stack() {
  stack *s = calloc(1, sizeof(stack));
  s->head = calloc(1, sizeof(element *));
  s->size = 0;
  return s;
}

/*
 * Function: isEmpty() 
 * Purpose:  Checks if the stack is empty 
 * Input:    (stack *) pointer to the stack
 * Output:   (int) 1/0 representing true or false 
 */
int isEmpty(stack *stack) {
  return stack->size == 0 ? 1:0;
}

/*
 * Function: stack_push() 
 * Purpose:  Adds an element to the stack 
 * Input:    (stack *) stack to add to
 *           (void *)  pointer to allocated memory of the data to add
 * Output:   (void)   
 */
void stack_push(stack *stack, void *data) {
  element *item = new_element(data);
  item->next = stack->head;
  stack->head = item;
  stack->size += 1;
}

/*
 * Function: stack_peek()
 * Purpose:  Gets the first element in the stack without poping
 * Input:    (stack *) stack to peek
 * Output:   (void *) the data in the stack  
 */
void *stack_peek(stack *stack) {
  return isEmpty(stack) ? NULL : stack->head->data; 
}

/*
 * Function: stack_pop() 
 * Purpose:  Retrieves the first element from the stack and removes it
 * Input:    (stack *) stack to pop from
 * Output:   (void *) the data in the stack  
 */
void *stack_pop(stack *stack) {
  if(isEmpty(stack)) { return NULL; }
  void *front_value = malloc(sizeof(void *));
  memcpy(front_value, stack->head->data, sizeof(void *));
  element *tmp = stack->head->next;
  free(stack->head->data);
  stack->head->data = NULL;
  free(stack->head);
  stack->head = NULL;
  stack->head = tmp;
  stack->size -= 1;
  return front_value;
}

/*
 * Function: stack_delete()
 * Purpose:  Removes the stack and all of its content
 * Input:    (stack *) stack to remove
 * Output:   (void) 
 */
void stack_delete(stack *stack) {
  int size = stack->size;
  for(int i = 0; i <= size; ++i) {
    free(stack_pop(stack));
  }
  free(stack->head);
  free(stack);
}

element* new_element(void *val) {
  element *item = calloc(1, sizeof(element));
  item->data = val;
  return item;
}

#endif

