NAME			= cub3d

CFLAGS			= -g3 -g -Wall -Werror -Wextra
LFLAGS			= -lft -lmlx -lX11 -lXext -lm -MMD -MP
INCLUDES		= -I./includes -I$(LIBFT_INC) -I$(MLX_PATH)
LIBS			= -L./libs/libft -L./libs/minilibx

#libft
LIBFT_PATH		= ./libs/libft
LIBFT_INC		= $(LIBFT_PATH)/includes
LIBFT			= $(LIBFT_PATH)/libft.a

#minilibx
MLX_PATH		= ./libs/minilibx
MLX_LINUX		= $(MLX_PATH)/libmlx_Linux.a
MLX				= $(MLX_PATH)/libmlx.a

#list path
3D_PROJECTION	= 3d_projection/
CHECKERS		= checkers/
KEYS 			= keys/
MLX_UTILS		= mlx_utils/
MOVE_PLAYER		= move_player/
RAYS 			= rays/
SETUP 			= setup/

#source codes
SRC_DIR			=	./src/
SRC_LIST		=	$(SETUP)actions.c\
					$(MLX_UTILS)draw_utils.c\
					$(MLX_UTILS)utils_mlx.c\
					$(RAYS)rays_utils.c\
					$(RAYS)rays.c\
					$(RAYS)rays_facing.c\
					$(3D_PROJECTION)projection3D.c	\
					$(3D_PROJECTION)render_game.c\
					$(3D_PROJECTION)draw_background.c\
					$(KEYS)keys.c\
					$(RAYS)utils_map.c\
					$(SETUP)utils_start.c\
					error.c	\
					cub3d.c\
					free.c\
					$(SETUP)init_game.c\
					$(RAYS)cast_rays.c\
					$(CHECKERS)temp_map.c		\
					$(CHECKERS)get_files.c\
					$(CHECKERS)create_map.c\
					$(CHECKERS)check_walls.c\
					$(CHECKERS)linked_list.c\
					$(CHECKERS)search_directions.c\
					$(MOVE_PLAYER)move_player.c

SRCS			= $(addprefix $(SRC_DIR),$(SRC_LIST))

#objects
OBJS_DIR		= ./objects/
OBJS			= $(addprefix $(OBJS_DIR),$(SRC_LIST:%.c=%.o))

#colors
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET			= \033[0m

#dependencies
DEP = $(OBJ:.o=.d)
-include $(DEP)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	@printf "\n"
	@cc $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME)
	@echo " $(CYAN)$(NAME): $(GREEN)Done!"
	@echo -n "$(RESET)"

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(3D_PROJECTION))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(CHECKERS))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(KEYS))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(MLX_UTILS))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(MOVE_PLAYER))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(RAYS))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(SETUP))

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(YELLOW)Generating $(CYAN)$(NAME) $(YELLOW)objects... %-33.33s\r" $@

clean:
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(MLX_PATH) clean
	@rm -rf $(OBJS_DIR)	

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

coffee:
	@make -sC $(LIBFT_PATH) coffee

.PHONY: all clean fclean re coffee val