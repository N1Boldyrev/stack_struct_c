#include "stack.h"
#define DATA_LEN 100

int main()
{
    stack* new_st = create_stack(DATA_LEN);
    stack_push(new_st,"Hello");
    stack_push(new_st,"world!");
    printf("%s\n",stack_pop(new_st));
    printf("%s\n",stack_top(new_st));
    printf("%s\n",stack_pop(new_st));
    delete_stack(new_st);
    return 0;
}