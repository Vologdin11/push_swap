#include "push_swap.h"

int	check_sort(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp != NULL)
	{
		if (list->content > tmp->content)
			return (0);
		tmp = tmp->next;
		list = list->next;
	}
	return (1);
}

void	ft_list_add_front(t_list **lst, t_list *new)
{
	new->next = lst[0];
	lst[0] = new;
}

int	list_size(t_list *list)
{
	int	size;

	size = 0;
	if (list != NULL)
	{
		size++;
		while (list->next != NULL)
		{
			size++;
			list = list->next;
		}
	}
	return (size);
}

void	ft_list_add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_list_new(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
	new->next = NULL;
	return (new);
}
