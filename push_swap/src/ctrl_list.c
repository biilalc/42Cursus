#include "push_swap.h"

int is_number(char **str, int ac)
{
    int i;
    int j;
    int k;

    i =  1;
    k = 0;
    while (i < ac)
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j - 1] == ' ' || str[i][j -  1] == '\t')
                k = 0;
            while ((str[i][j] == '-' || str[i][j] == '+') && ++j)
                k++;
            if (((str[i][j] != '-') && (str[i][j] < '0' || str[i][j] > '9') 
                && (str[i][j] != 32 && str[i][j] != '\t')) || k > 1)
                return (0);
            j++;
        }
        i++;
        k = 0;
    }
    return (1);
}

int is_sorted(t_stack *stack) //elemanlar küçükten büyüğe sıralıysa return (1), değilse return (0)
{
    while (stack->next != NULL)
    {
        if (stack->content < stack->next->content)
            stack = stack->next;
        else
            return (0);
    }
    return (1);
}

int is_uniq(t_stack *stack) //listede aynı elemandan iki tane varsa return (0), yoksa return (1)
{
    int     data;
    t_stack *temp;

    temp = stack;
    data = temp->content;
    while (stack && temp->next != NULL)
    {
        if (stack->next != NULL && data == stack->next->content)
            return (0);
        else if (stack->next == NULL)
        {
            temp = temp->next;
            data = temp->content;
            stack = temp;
        }
        else
            stack = stack->next;
    }
    return (1);    
}