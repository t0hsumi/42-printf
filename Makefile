NAME = libftprintf.a
TEST = printf.exe

CC = gcc
CFLAGS = # -Wall -Wextra -Werror
DEBUG = #-g

SRCS = ft_printf.c ft_output.c ft_utils.c
OBJS = $(SRCS:.c=.o)

T_SRCS = main.c

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

solve: $(NAME)
	@$(CC) $(CFLAGS) -D FT_PRINTF -o $(TEST) $(T_SRCS) $(NAME)
	./$(TEST)

ans: $(NAME)
	@$(CC) $(CFLAGS) -o $(TEST) $(T_SRCS) $(NAME)
	./$(TEST)

test: $(NAME)
	@$(CC) $(CFLAGS) -o $(TEST) $(T_SRCS) $(NAME)
	@exec ./$(TEST) > ans.txt
	@$(CC) $(CFLAGS) -D FT_PRINTF -o $(TEST) $(T_SRCS) $(NAME)
	@exec ./$(TEST) > solve.txt
	@diff -y ans.txt solve.txt

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
