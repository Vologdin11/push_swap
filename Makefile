NAME = push_swap

SRCS = push_swap.c list.c sort_list.c ft_split.c ft_atoi.c validator.c pre_sort.c sort.c get_position.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all