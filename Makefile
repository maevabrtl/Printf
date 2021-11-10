.PHONY: all clean fclean re libft

NAME = libftprintf.a 
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
TEST_FLAGS = -Wno-format
PATH_OBJ = ./objs
PATH_SRC = ./srcs
PATH_INC = ./includes
INCS = $(addprefix $(PATH_INC)/, libftprintf.h)

#*****************************************************************************#
#                                  PRINTF                                     #
#*****************************************************************************#

PATH_PRINTF = $(PATH_SRC)/printf
PATH_OBJ_PRINTF = $(PATH_OBJ)/printf
FILES_PRINTF = error ft_printf tools
SRCS_PRINTF = $(addprefix $(PATH_PRINTF)/, $(addsuffix .c, $(FILES_PRINTF)))
OBJS_PRINTF = $(addprefix $(PATH_OBJ_PRINTF)/, $(addsuffix .o, $(FILES_PRINTF)))

#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#

PATH_LIBFT = ./libs/Libft
NAME_LIBFT = ft
LIBFT = $(PATH_LIBFT)/lib$(NAME_LIBFT).a
ILIBFT = -L $(PATH_LIBFT) -l $(NAME_LIBFT)
PATH_INC_LIBFT = $(PATH_LIBFT)/includes

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
	make -C ./libs/Libft fclean

re: fclean all

libft:
	make -C ./libs/Libft
	cp $(LIBFT) $(NAME)

tests: all
	$(CC) $(TEST_FLAGS) tests/main.c -L ./ -l ftprintf -I $(PATH_INC) -I $(PATH_INC_LIBFT)
	./a.out
	rm ./a.out

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#


$(NAME): libft $(PATHS_OBJ) $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS)

$(PATHS_OBJ):
	mkdir $@

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	$(CC) $(CC_FLAGS) -I $(PATH_INC) -I $(PATH_INC_LIBFT) -o $@ -c $<