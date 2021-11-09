.PHONY: all clean fclean re

NAME = libftprintf.a 
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
TEST_FLAGS = -Wno-format
PATH_OBJ = ./objs
PATH_SRC = ./srcs
PATH_INC = ./includes
INCS = $(addprefix $(PATH_INC)/, libftprintf.h)

#*****************************************************************************#
#                                  LIBFT                                      #
#*****************************************************************************#
PATH_LIBFT = $(PATH_SRC)/libft
PATH_OBJ_LIBFT = $(PATH_OBJ)/libft
FILES_LIBFT = ft_calloc ft_lstnew ft_strchr ft_utoa ft_bzero ft_strlen\
			  ft_lstfree ft_putchar ft_strncpy ft_itoabase ft_putstr
SRCS_LIBFT = $(addprefix $(PATH_LIBFT)/, $(addsuffix .c, $(FILES_LIBFT)))
OBJS_LIBFT = $(addprefix $(PATH_OBJ_LIBFT)/, $(addsuffix .o, $(FILES_LIBFT)))

#*****************************************************************************#
#                                  PRINTF                                     #
#*****************************************************************************#
PATH_PRINTF = $(PATH_SRC)/printf
PATH_OBJ_PRINTF = $(PATH_OBJ)/printf
FILES_PRINTF = error ft_printf tools
SRCS_PRINTF = $(addprefix $(PATH_PRINTF)/, $(addsuffix .c, $(FILES_PRINTF)))
OBJS_PRINTF = $(addprefix $(PATH_OBJ_PRINTF)/, $(addsuffix .o, $(FILES_PRINTF)))

#*****************************************************************************#
#                                    ALL                                      #
#*****************************************************************************#

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_LIBFT) $(PATH_OBJ_PRINTF)
FILES = $(FILES_LIBFT) $(FILES_PRINTF)
SRCS = $(SRCS_LIBFT) $(SRCS_PRINTF)
OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF)

#*****************************************************************************#
#                                   RULES                                     #
#*****************************************************************************#

all: $(NAME)

clean:
	rm -rf $(PATH_OBJ)

fclean: clean
	rm -f $(NAME)
	rm ./a.out

re: fclean all

tests: all
	$(CC) $(TEST_FLAGS) tests/main.c -L ./ -lftprintf -I $(PATH_INC)
	./a.out

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#


$(NAME): $(PATHS_OBJ) $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS)

$(PATHS_OBJ):
	mkdir $@

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	$(CC) $(CC_FLAGS) -I $(PATH_INC) -o $@ -c $<