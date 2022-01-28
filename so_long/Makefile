#Standard

NAME 		= so_long
INCLUDES	= include/
SRC_DIR		= src/
SRC_DIR_BONUS	= src/bonus/
CC 			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -I
#MLX		= -L /usr/x11/lib/ -lmlx -lXext -lX11
MLX		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

#Libft
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#sources

SRC_FILES	=	so_long.c read_map.c errors.c parser_map.c check_map.c game_start.c new_window.c \
				xpm_image.c render_start.c render_utils.c key_hook.c control_player.c check_map_utils.c

SRC_BONUS_FILES	=	check_map_bonus.c \
			check_map_utils_bonus.c \
			control_player_bonus.c \
			errors_bonus.c \
			game_start_bonus.c \
			key_hook_bonus.c \
			new_window_bonus.c \
			parser_map_bonus.c \
			read_map_bonus.c \
			render_start_bonus.c \
			render_utils_bonus.c \
			so_long_bonus.c \
			xpm_image_bonus.c
	
SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_BONUS 	= 	$(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS_FILES))

OBJ 		= 	$(SRC:.c=.o)

OBJ_BONUS 	= 	$(SRC_BONUS:.c=.o)

###
all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(GRAY)     - Making libft... $(DEF_COLOR)"
			@make -C $(LIBFT_DIR)	
			$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(MLX)
			@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"


bonus:		$(OBJ_BONUS)
			@echo "$(GRAY)     - Making libft... $(DEF_COLOR)"
			@make -C $(LIBFT_DIR)	
			$(CC) $(OBJ_BONUS) $(LIBFT) -o $(NAME) $(MLX)
			@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

.c.o :
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
			@$(RM) -rf $(OBJ) $(OBJ_BONUS)
			@make -C $(LIBFT_DIR) clean
			@echo "$(BLUE)So_Long objects files cleaned!$(DEF_COLOR)"

fclean:				clean
				@$(RM) -f $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@echo "$(CYAN)So_Long executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for So_Long!$(DEF_COLOR)"
norm:
			@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
