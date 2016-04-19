#include <stdio.h>
#include <stdlib.h>
#include "../includes/common.h"
#include "../includes/stack.h"

void test_new_stack() {
  printf("Testing new stack");
  stack *s = new_stack();
  if(!s) {
    error("No stack was created");
  }
  printf(" - check \n");
  stack_delete(s);
}
void test_new_stack_empty() {
  printf("New stack should be empty");
  stack *s = new_stack();
  if(!isEmpty(s)) {
    error("New stack was not empty");
  }
  printf(" - check \n");
  stack_delete(s);
}
void test_stack_push() {
  printf("Trying to push element to stack");
  stack *s = new_stack();
  int *val = malloc(sizeof(int));
  *val = 2;
  stack_push(s, val);
  if(isEmpty(s)) {
    error("Could not push to stack!");
  }
  printf(" - check \n");
  stack_delete(s);
}
void test_front_value() {
  printf("Checking if front value was correct");
  stack *s = new_stack();
  int *val = malloc(sizeof(int));
  *val = 1;
  stack_push(s, val);
  if(*val != *(int *)stack_peek(s)) {
    error("Fron value was not right");
  }
  printf(" - check\n");
  stack_delete(s);
}
void test_pop_should_not_crash() {
  printf("Pop on stack should not crash");
  stack *s = new_stack();
  int *val = malloc(sizeof(int));
  *val = 1;
  stack_push(s, val);
  free(stack_pop(s));
  printf(" - check\n");
  stack_delete(s);
}
void test_pop_should_return_correct() {
  printf("Pop should return correct value");
  stack *s = new_stack();
  int *val = malloc(sizeof(int));
  *val = 1;
  stack_push(s, val);
  if(*val != *(int *)stack_pop(s)) {
    error("Value returned from pop was not correct");
  }
  printf(" - check\n");
  stack_delete(s);
}
void test_pop_on_empty_stack() {
  printf("Pop on empty stack should not crash");
  stack *s = new_stack();
  if(stack_pop(s) != NULL) {
    error("Pop on empty stack shoud be NULL");
  }
  printf(" - check\n");
  stack_delete(s);
}
void test_multiple_pushes_pops() {
  printf("Trying to add and delete multiple elements");
  stack *s = new_stack();
  for(int i = 0; i < 10; ++i) {
    int *val = malloc(sizeof(int));
    *val = i;
    stack_push(s, val);
  }
  for(int i = 9; i >= 0; --i) {
    if(*(int *)stack_pop(s) != i) {
      error("Values did not match");
    }
  }
  printf(" - check\n");
  stack_delete(s);
}
void test_stack_delete() {
  printf("Trying to delete non-empty stack");
  stack *s = new_stack();
  for(int i = 0; i < 10; ++i) {
    int *val = malloc(sizeof(int));
    *val = i;
    stack_push(s, val);
  }
  stack_delete(s);
  printf(" - check\n");

}
void test_delete_empty_stack() {
  printf("Trying to delete empty stack");
  stack *s = new_stack();
  stack_delete(s);
  printf(" - check\n");
}

int main(void) {

  test_new_stack();
  test_new_stack_empty();
  test_stack_push();
  test_front_value();
  test_pop_should_not_crash();
  test_pop_should_return_correct();
  test_pop_on_empty_stack();
  test_multiple_pushes_pops();
  test_stack_delete();
  test_delete_empty_stack();

  return 0;
}
