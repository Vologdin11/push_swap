#include "push_swap.h"

static void	check_dup(t_list *stack_a)
{
	t_list	*i;

	if (list_size(stack_a) < 2)
		return ;
	while (stack_a->next != NULL)
	{
		i = stack_a->next;
		while (i != NULL)
		{
			if (stack_a->content == i->content)
				error();
			i = i->next;
		}
		stack_a = stack_a->next;
	}
}

static void	check_arg(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		ft_isdigit(args[i]);
		i++;
	}
}

static void	validator_dop_two(char **argv, t_list **t, t_list **stack_a)
{
	char	**args;
	char	**i;

	args = ft_split(argv[1], ' ');
	if (args == NULL)
		error();
	check_arg(args);
	i = args;
	while (*i != NULL)
	{
		*t = ft_list_new(ft_atoi(*i));
		if (stack_a == NULL)
			stack_a = t;
		else
			ft_list_add_back(stack_a, *t);
		i++;
	}
	ft_malloc_free(args);
}

static void	validator_dop(int argc, char **argv, t_list **t, t_list **stack_a)
{
	while (argc-- > 1)
	{
		ft_isdigit(argv[argc]);
		*t = ft_list_new(ft_atoi(argv[argc]));
		if (stack_a == NULL)
			stack_a = t;
		else
			ft_list_add_front(stack_a, *t);
	}
}

t_list	*validator(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tmp;

	stack_a = NULL;
	if (argc == 2)
		validator_dop_two(argv, &tmp, &stack_a);
	else
		validator_dop(argc, argv, &tmp, &stack_a);
	check_dup(stack_a);
	indexing(&stack_a);
	return (stack_a);
}
