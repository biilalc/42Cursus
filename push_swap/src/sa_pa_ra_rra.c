#include "push_swap.h"

void sa(t_stack *lst)
{
    int temp;

    write(1, "sa\n", 3);
    temp = (lst)->next->content;
    (lst)->next->content = (lst)->content;
    (lst)->content = temp;
}

void	pa(t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;

	write(1, "pa\n", 3);
	temp = (*lstb)->next;
	ft_lstadd_front(lsta, *lstb);
	(*lstb) = temp;
}

void	ra(t_stack **lsta)
{
	t_stack	*listenin_sonu;
	t_stack	*listenin_yeni_basi;

	listenin_yeni_basi = (*lsta)->next;
	write(1, "ra\n", 3);
	listenin_sonu = ft_lstlast(*lsta);
	listenin_sonu->next = *lsta;
	listenin_sonu->next->next = NULL;
	*lsta = listenin_yeni_basi;
}

void	rra(t_stack **lsta)
{
	t_stack	*end_lst;
	t_stack	*temp;
	int		i;

	temp = *lsta;
	write(1, "rra\n", 4);
	i = ft_lstlast(*lsta)->content;
	while (temp->next->next)
		temp = temp->next;
	free(ft_lstlast(*lsta));
	temp->next = NULL;
	end_lst = malloc(sizeof(t_stack));
	end_lst->content = i;
	end_lst->next = *lsta;
	*lsta = end_lst;
}
