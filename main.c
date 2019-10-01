#include "stack.h"
#define DATA_LEN 100

int main()
{
   stack* new_stack = create_stack(DATA_LEN);
   for(size_t i = 0; i < 10; i++)
        stack_push(new_stack,"TEST");
    stack_read(new_stack,stdout);
    stack_pop(new_stack);
    stack_push(new_stack,"NEW_TEST");
    stack_read_elem(new_stack,9,stdout);
    stack_top(new_stack,stdout);
    delete_stack(new_stack);
    stack* new_stack2 = create_stack(DATA_LEN);
    if(stack_is_empty(new_stack2) == 1)
        printf("isempty\n");
    else
        printf("is_not_empty\n");
    return 0;
}