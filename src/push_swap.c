#include "../push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	move_elem_dop(t_list **stack_a, t_list **stack_b, t_var *var)
{
	if (var->ra > 0)
	{
		rab(stack_a);
		var->ra--;
		write(1, "ra\n", 3);
	}
	else if (var->rb > 0)
	{
		rab(stack_b);
		var->rb--;
		write(1, "rb\n", 3);
	}
	else if (var->rra > 0)
	{
		rrab(stack_a);
		var->rra--;
		write(1, "rra\n", 4);
	}
	else if (var->rrb > 0)
	{
		rrab(stack_b);
		var->rrb--;
		write(1, "rrb\n", 4);
	}
}

static void	move_elem_dop2(t_list **stack_a, t_list **stack_b)
{
	if (stack_b != NULL)
	{
		pab(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

void	move_elem(t_list **stack_a, t_list **stack_b, t_var *var)
{
	while (var->ra > 0 || var->rb > 0 || var->rra > 0 || var->rrb > 0)
	{
		if (var->ra > 0 && var->rb > 0)
		{
			rab(stack_a);
			rab(stack_b);
			var->ra--;
			var->rb--;
			write(1, "rr\n", 3);
		}
		else if (var->rra > 0 && var->rrb > 0)
		{
			rrab(stack_a);
			rrab(stack_b);
			var->rra--;
			var->rrb--;
			write(1, "rrr\n", 4);
		}
		else
			move_elem_dop(stack_a, stack_b, var);
	}
	move_elem_dop2(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_var	var;

	if (argc < 2)
	{
		write(1, "Please enter numbers to sort!\n", 30);
		return (0);
	}
	stack_a = validator(argc, argv);
	if (check_sort(stack_a) == 1)
		return (0);
	pre_sort(&stack_a, &stack_b);
	while (stack_b != NULL)
		sort(&stack_a, &stack_b, &var);
	finish_sort(&stack_a, &var);
}
