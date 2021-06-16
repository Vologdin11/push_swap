#include "push_swap.h"

static void	init_var(t_var *var)
{
	var->stack_size = 0;
	var->pos = 0;
	var->ra = 0;
	var->rb = 0;
	var->rra = 0;
	var->rrb = 0;
}

static int	count_action(t_list *stack_a, t_list *stack_b, \
t_var *var, int index)
{
	init_var(var);
	var->stack_size = list_size(stack_b);
	var->pos = get_position_elem(index, stack_b);
	if ((var->stack_size / 2) >= var->pos)
		var->rb = var->pos - 1;
	else if (var->stack_size > 1)
		var->rrb = var->stack_size - var->pos + 1;
	var->stack_size = list_size(stack_a);
	var->pos = get_position_insert(index, stack_a);
	if ((var->stack_size / 2) >= var->pos)
		var->ra = var->pos - 1;
	else
		var->rra = var->stack_size - var->pos + 1;
	return (var->ra + var->rra + var->rb + var->rrb);
}

void	finish_sort(t_list **stack_a, t_var *var)
{
	init_var(var);
	var->stack_size = list_size(*stack_a);
	var->pos = get_position_elem(1, *stack_a);
	if ((var->stack_size / 2) >= var->pos)
		var->ra = var->pos - 1;
	else if (var->stack_size > 1)
		var->rra = var->stack_size - var->pos + 1;
	move_elem(stack_a, NULL, var);
}

void	sort(t_list **stack_a, t_list **stack_b, t_var *var)
{
	int		min_action;
	int		action;
	t_list	*tmp;
	t_list	*min_elem;

	min_action = -1;
	tmp = *stack_b;
	while (tmp != NULL)
	{
		action = count_action(*stack_a, *stack_b, var, tmp->index);
		if (min_action == -1)
		{
			min_action = action;
			min_elem = tmp;
		}
		else if (action < min_action)
		{
			min_action = action;
			min_elem = tmp;
		}
		tmp = tmp->next;
	}
	min_action = count_action(*stack_a, *stack_b, var, min_elem->index);
	move_elem(stack_a, stack_b, var);
}
