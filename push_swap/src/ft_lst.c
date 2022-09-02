#include "push_swap.h"

t_stack *ft_lstlast(t_stack *lst) //listenin son elemanını verir
{
    if (!lst)
        return (0);
    while (lst -> next)
        lst = lst -> next;
    return (lst);
}

int ft_lstsize(t_stack *lst) //listenin boyutunu verir
{
    int i;

    i = 0;
    while (lst != NULL)
    {
        lst = lst -> next;
        i++;
    }
    return (i);
}

int ft_atoi(const char *str) //bu bildiğin atoi işte
{
    int             i;
    unsigned long   ret;
    int             isnegative;

    i = 0;
    ret = 0;
    isnegative = 1;
    while (str[i] == '\n' && str[i] == ' ')
        i++;
    if (str[i] == '-')
        isnegative *= -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        ret = (ret * 10) + (str[i] - '0');
        i++;
    }
    if ((ret > 2147483647 && isnegative != -1)
        || (ret > 2147483647 && isnegative == -1))
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    return (ret * isnegative);
}
