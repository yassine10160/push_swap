NAME=push_swap
CC=cc
FLAGS=-Wall -Wextra -Werror -g
OBJDIR = .obj
SRCS=utils.c utils2.c push_swap.c utils3.c utils4.c utils5.c ft_split.c check_input.c check_input2.c \
	ft_strncmp.c
HEADERS=push_swap.h
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
$(OBJDIR)/%.o: %.c $(HEADERS) Makefile
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(OPTS) -c $< -o $@
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re