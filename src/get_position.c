#include "../push_swap.h"

int	get_position_elem(int index, t_list *list)
{
	int	pos;

	pos = 1;
	while (list->index != index)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}

static int	get_min_index(t_list *list)
{
	int	index;

	index = 0;
	while (list != NULL)
	{
		if (index == 0)
			index = list->index;
		if (list->index < index)
			index = list->index;
		list = list->next;
	}
	return (index);
}

int	get_position_insert(int index, t_list *list)
{
	int		pos;
	int		pre;
	int		next;
	int		min_index;
	t_list	*tmp;

	pos = 1;
	pre = list->index;
	tmp = list->next;
	next = tmp->index;
	min_index = get_min_index(list);
	if (index < min_index)
		return (get_position_elem(min_index, list));
	while (1)
	{
		pos++;
		if (pre < index && next > index)
			return (pos);
		pre = tmp->index;
		if (tmp->next == NULL)
			tmp = list;
		else
			tmp = tmp->next;
		next = tmp->index;
	}
}
