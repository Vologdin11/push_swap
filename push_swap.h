#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct s_var
{
	int		stack_size;
	int		pos;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
}				t_var;

void	ft_list_add_back(t_list **lst, t_list *new);
t_list	*ft_list_new(int content);
void	sab(t_list **list);
void	ft_list_add_front(t_list **lst, t_list *new);
void	pab(t_list **list_a, t_list **list_b);
void	rrab(t_list **list);
char	**ft_split(char const *s, char c);
void	error(void);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		list_size(t_list *list);
void	rab(t_list **list);
t_list	*validator(int argc, char **argv);
void	pre_sort(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b, t_var *var);
void	finish_sort(t_list **stack_a, t_var *var);
int		get_position_elem(int index, t_list *list);
int		get_position_insert(int index, t_list *list);
void	move_elem(t_list **stack_a, t_list **stack_b, t_var *var);
int		check_sort(t_list *list);
int		ft_isdigit(char *str);
char	**ft_malloc_free(char **tab);
void	indexing(t_list **stack_a);

#endif
