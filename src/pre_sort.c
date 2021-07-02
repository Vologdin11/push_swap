#include "../push_swap.h"

int	ft_isdigit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < 47 || *str > 58)
			error();
		str++;
	}
	return (1);
}

static void	three_sort_dop(t_list **list, t_list *f, t_list *s, t_list *t)
{
	if (s->index < t->index && s->index < f->index && f->index > t->index)
	{
		rab(list);
		write(1, "ra\n", 3);
	}
	else if (f->index < t->index && t->index < s->index && s->index > t->index)
	{
		sab(list);
		rab(list);
		write(1, "sa\nra\n", 6);
	}
	else if (t->index < f->index && f->index < s->index && s->index > f->index)
	{
		rrab(list);
		write(1, "rra\n", 4);
	}
}

static void	three_sort(t_list **list)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f = *list;
	s = f->next;
	t = s->next;
	if (s->index < f->index && s->index < t->index && t->index > f->index)
	{
		sab(list);
		write(1, "sa\n", 3);
	}
	else if (t->index < s->index && t->index < f->index && f->index > s->index)
	{
		sab(list);
		rrab(list);
		write(1, "sa\nrra\n", 7);
	}
	else
		three_sort_dop(list, f, s, t);
}

static void	pre_sort_dop(t_list **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sab(stack_a);
		write(1, "sa\n", 3);
	}
}

void	pre_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_list;

	len_list = list_size(*stack_a) - 3;
	if (list_size(*stack_a) < 3)
		return (pre_sort_dop(stack_a));
	while (list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index > len_list)
		{
			rab(stack_a);
			write(1, "ra\n", 3);
		}
		else
		{
			pab(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
	}
	three_sort(stack_a);
}
