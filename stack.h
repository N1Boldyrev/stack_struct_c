#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{
    size_t stack_size;
    char** data;
    size_t data_len;
    size_t next_elem;
}stack;

stack* create_stack(size_t);
void delete_stack(stack*);
int stack_push(stack*,char*);
int stack_pop(stack*);
int stack_read_elem(stack*,size_t,FILE*);
int stack_read(stack*,FILE*);

stack* create_stack(size_t data_len)
{
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->next_elem = 0;
    new_stack->stack_size = 0;
    new_stack->data_len = data_len;
    return new_stack;
}

void delete_stack(stack* st)
{
    for(size_t i = 0; i < st->stack_size; i++)
        free(st->data[i]);
    free(st->data);
    free(st);
}

int stack_push(stack* st,char* get_data)
{
    st->stack_size++;
    if(st->data == NULL)
    {
     st->data = (char**)malloc(sizeof(char*) * st->stack_size);
     st->data[0] = (char*)malloc(sizeof(char*) * st->data_len);
     for(size_t i = 0; i < st->data_len && i < strlen((const char*)get_data); i++)
        st->data[0][i] = get_data[i];
     return 1;
    }
    else if (st->data != NULL)
    {
        st->next_elem++;
        st->data =(char**)realloc(st->data,sizeof(char*) * st->stack_size);
        for(size_t i = st->next_elem; i < st->stack_size; i++)
            st->data[i] = (char*)malloc(sizeof(char*) * st->data_len);
        for(size_t i = 0; i < st->data_len && i < strlen((const char*)get_data); i++)
            st->data[st->next_elem][i] = get_data[i];
        return 1;
    }
    return 0;
}

int stack_pop(stack* st)
{
    if(st->stack_size > 0)
    {
        free(st->data[st->next_elem]);
        st->next_elem--;
        st->stack_size--;
        st->data =(char**)realloc(st->data,sizeof(char*) * st->stack_size);
        return 1;
    }
    return 0;
}

int stack_read_elem(stack* st, size_t element_num, FILE* fp)
{
    if(st->stack_size > 0)
    {
        fprintf(fp,"[ELEMENT %ld]: %s\n",st->next_elem,st->data[element_num]);
        return 1;
    }
    return 0;
}

int stack_read(stack* st,FILE* fp)
{
    if(st->stack_size > 0)
    {
        for(size_t i = 0; i < st->stack_size; i++)
            fprintf(fp,"[ELEMENT %ld]: %s\n",i,st->data[i]);
        return 1;
    }
    return 0;
}