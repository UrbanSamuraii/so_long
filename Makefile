NAME	= so_long

AR		= @ar
ARFLAG	= crs

CC		= @cc
CCFLAG	= -g -Wall -Wextra -Werror

RM		= @rm
RMFLAG	= -rf

SMAKE	= @make --no-print-directory
DIR		= objs

SRC		= so_long.c map_check.c backtracking.c map_update.c utils.c main.c
OBJ		= $(addprefix $(DIR)/,$(SRC:.c=.o))

BSRC	= so_long_bonus.c map_check_bonus.c backtracking_bonus.c map_update_bonus.c utils_bonus.c main_bonus.c backtracking_deep_bonus.c
BOBJ	= $(addprefix $(DIR)/,$(BSRC:.c=.o))

LIB		= libft/libft minilibx/libmlx.a minilibx/libmlx_Linux.a

all			: $(NAME)

$(NAME)		: $(OBJ)
			$(SMAKE) -C libft/
			$(SMAKE) -C minilibx/
			$(AR) $(ARFLAG) $(NAME) $(OBJ)
			$(CC) -o $(NAME) libft/objs/*.o $(OBJ) $(LIB) -lX11 -lXext
			@echo "\033[1;35m======= game has been created =======\033[0m"

$(DIR)/%.o	: %.c
		@mkdir -p objs
		$(CC) $(CCFLAG) -c $< -o $(DIR)/$(<:.c=.o)

bso_long	: $(BOBJ)
			$(SMAKE) -C libft/
			$(SMAKE) -C minilibx/
			$(AR) $(ARFLAG) $(NAME) $(BOBJ)
			$(CC) -o $(NAME) libft/objs/*.o $(BOBJ) $(LIB) -lX11 -lXext
			@echo "\033[1;35m======= bonus game has been created =======\033[0m"

clean		:
			$(SMAKE) -C libft/ clean
			$(SMAKE) -C minilibx/ clean
			$(RM) $(RMFLAG) $(OBJ) $(BOBJ) objs/
			@echo "\033[1;36m======= so_long object files have been removed =======\033[0m"

fclean		: clean
			$(SMAKE) -C libft/ fclean
			$(RM) $(RMFLAG) $(NAME)
			@echo "\033[1;36m======= game has been removed =======\033[0m"

re			: fclean all

bonus		: fclean bso_long

.PHONY		: all bso_long clean fclean re bonus norm
