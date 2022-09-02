#include "push_swap.h"

void	sb(t_stack *lst)
{
	int	temp;

	write(1, "sb\n", 3);
	temp = (lst)->next->content;
	(lst)->next->content = (lst)->content;
	(lst)->content = temp;
}

void	pb(t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;

	write(1, "pb\n", 3);
	temp = (*lsta)->next;
	ft_lstadd_front(lstb, *lsta);
	(*lsta) = temp;
}

void	rb(t_stack **lstb)
{
	t_stack	*listenin_sonu;
	t_stack	*listenin_yeni_basi;

	listenin_yeni_basi = (*lstb)->next;
	write(1, "rb\n", 3);
	listenin_sonu = ft_lstlast(*lstb);
	listenin_sonu->next = *lstb;
	listenin_sonu->next->next = NULL;
	*lstb = listenin_yeni_basi;
}

void	rrb(t_stack **lstb)
{
	t_stack	*end_lst;
	t_stack	*temp;
	int		i;

	temp = *lstb;
	write(1, "rrb\n", 4);
	i = ft_lstlast(*lstb)->content;
	while (temp->next->next)
		temp = temp->next;
	free(ft_lstlast(*lstb));
	temp->next = NULL;
	end_lst = malloc(sizeof(t_stack));
	end_lst->content = i;
	end_lst->next = *lstb;
	*lstb = end_lst;
}
