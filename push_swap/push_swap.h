#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}t_stack;

t_stack	*push_swap(char **str, int len);

void	sa(t_stack *lst);
void	sb(t_stack *lst);
void	ss(t_stack *lsta, t_stack *lstb);
void	pa(t_stack **lsta, t_stack **lstb);
void	pb(t_stack **lsta, t_stack **lstb);
void	ra(t_stack **lsta);
void	rb(t_stack **lstb);
void	rr(t_stack **lsta, t_stack **lstb);
void	rra(t_stack **lsta);
void	rrb(t_stack **lstb);
void	rrr(t_stack **lsta, t_stack **lstb);

void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*to_int(char **str, int len);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_atoi(const char *str);
int		ft_lstsize(t_stack *lst);
int		is_number(char **str, int ac);
int		ft_strlen(char *str);
int		is_uniq(t_stack *stack);

void	push(t_stack **stack, int data);
int		min_index(t_stack *stack);
int		min(t_stack *stack);
int		big_index(t_stack *stack);
int		find_index(t_stack *stack, int data);

int		ctrl_dizi(int *dizi, int min, int boyut);
int		is_sorted(t_stack *stack);
void	push_b(t_stack **stack_a, t_stack **stack_b, int *dizi, int boyut);
void	push_b2(t_stack **stack_a, t_stack **stack_b, int ort);
void	sort(t_stack **stack_a);
void	three_sort(t_stack **stack);
void	five_sort(t_stack **stack_a, t_stack **stack_b);
void	give_back(t_stack **stack_a, t_stack **stack_b);

#endif
