NAME = libftprintf.a
TEST = printf.exe

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = 

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

T_SRCS = main.c
T_OBJS = $(T_SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(TEST): $(NAME) $(T_OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(T_OBJS) $(NAME)

test: $(TEST)
	exec ./$(TEST) > ans.txt
	$(CC) $(CFLAGS) -D FT_PRINTF -o $(TEST) $(T_OBJS) $(NAME)
	exec ./$(TEST) > solve.txt
	diff -y ans.txt solve.txt

clean:
	rm -f $(OBJS)

testclean: clean
	rm -f $(T_OBJS) $(TEST)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re testclean test
