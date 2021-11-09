.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
FILES = ft_calloc ft_lstnew ft_strchr ft_utoa ft_bzero ft_strlen ft_itoabase ft_putstr
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))
PATH_OBJS = objs
INC = libft.h

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(PATH_OBJS):
	@mkdir $@

$(OBJS): $(SRCS)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(INC)