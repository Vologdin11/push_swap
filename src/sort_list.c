#include "../push_swap.h"

void	pab(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	tmp = *list_a;
	if ((*list_a)->next != NULL)
		*list_a = (*list_a)->next;
	else
		*list_a = NULL;
	tmp->next = NULL;
	ft_list_add_front(list_b, tmp);
}

void	sab(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*list);
	second = (*list)->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*list = second;
}

void	rrab(t_list **list)
{
	t_list	*last;
	t_list	*pre_last;

	pre_last = *list;
	last = pre_last->next;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	ft_list_add_front(list, last);
}

void	rab(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	ft_list_add_back(list, tmp);
}

void	indexing(t_list **stack_a)
{
	int		len_list;
	int		index;
	t_list	*min;
	t_list	*tmp;

	len_list = list_size(*stack_a);
	index = 1;
	while (index <= len_list)
	{
		min = *stack_a;
		while (min->index != 0)
			min = min->next;
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (min->content > tmp->content && tmp->index == 0)
				min = tmp;
			tmp = tmp->next;
		}
		min->index = index;
		index++;
	}
}
