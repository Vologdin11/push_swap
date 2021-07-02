NAME = push_swap

SRCS =	src/push_swap.c src/list.c src/sort_list.c src/ft_split.c src/ft_atoi.c \
		src/validator.c src/pre_sort.c src/sort.c src/get_position.c

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