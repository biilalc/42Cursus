#include "push_swap.h"

void	give_back(t_stack **stack_a, t_stack **stack_b) //b'den a'ya geri yollar (burada amaç b'deki en büyük elemanı en başa alıp a'ya yollamak)
{
	int	size;
	int	index;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_b);
		index = big_index(*stack_b);
		if (index == 1)
			sb(*stack_b);
		else if (index <= size / 2 && index != 0)
			rb(stack_b);
		else if (index >= size / 2 && index != 0)
			rrb(stack_b);
		else
			pa(stack_a, stack_b);
	}
}

void	three_sort(t_stack **stack) //eleman sayısı 3 veya daha az ise burada sıralama yapar
{
	if (big_index(*stack) == 0 && (min_index(*stack) == 2)
		&& ft_lstsize(*stack) != 2)
	{
		sa(*stack);
		rra(stack);
	}
	else if (big_index(*stack) == 0 && ft_lstsize(*stack) == 2)
		sa(*stack);
	else if (big_index(*stack) == 0 && is_sorted((*stack)->next))
		ra(stack);
	else if (big_index(*stack) == 1 && min_index(*stack) == 0)
	{
		rra(stack);
		sa(*stack);
	}
	else if (min_index(*stack) == 2 && big_index(*stack) == 1)
		rra(stack);
	else
		sa(*stack);
}

void	five_sort(t_stack **stack, t_stack **stack_b) //eleman sayısı 5 veya daha az ise burada sıralama yapar
{
	int	size;
	int	index;
	int	i;

	i = 0;
	size = ft_lstsize(*stack);
	while (ft_lstsize(*stack) > 3)
	{
		index = min_index(*stack);
		if (index >= ft_lstsize(*stack) / 2 && index != 0)
			rra(stack);
		else if (index <= ft_lstsize(*stack) / 2 && index != 0)
			ra(stack);
		else
			pb(stack, stack_b);
	}
	if (ft_lstsize(*stack) <= 3 && !is_sorted(*stack))
		three_sort(stack);
	while (i <= (size - ft_lstsize(*stack)))
	{
		pa(stack, stack_b);
		i++;
	}
}
