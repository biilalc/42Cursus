#include "push_swap.h"

t_stack *to_int(char **str, int ac) //atoi yardımıyla argümanları int'e çeviriyor
{
    t_stack *ret;
    int     size;

    ret = NULL;
    while (--ac >= 1)
    {
        size = ft_strlen(str[ac]);
        while (str[ac][--size] && size >= 0)
        {
            while ((str[ac][size] >= '0' && str[ac][size] <= '9') 
                || str[ac][size] == '-')
                size--;
            push(&ret, ft_atoi(&str[ac][size + 1]));
            while (str[ac][size] == ' ')
                size--;
            if(size == 0)
                push(&ret, ft_atoi(&str[ac][size]));
        }
    }
    return (ret);
}

void    push(t_stack **stack, int data)
{
    t_stack *temp;

    temp = (t_stack *)malloc(sizeof(t_stack));
    if (!temp)
        return ;
    temp->content = data;
    temp->next = NULL;
    if (!stack)
    {
        (*stack) = temp;
        return ;
    }
    temp->next = (*stack);
    (*stack) = temp;
}

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
    new -> next = *lst;
    *lst = new;
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
