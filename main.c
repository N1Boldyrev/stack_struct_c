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
    delete_stack(new_stack);
    return 0;
}