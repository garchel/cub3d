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
WINDOW_PATH		= window/
RENDER_PATH		= render/
MAP_PATH		= map/

#source codes
SRC_DIR			=	./src/
SRC_LIST		=	$(WINDOW_PATH)window.c	\
					$(WINDOW_PATH)controls.c\
					$(RENDER_PATH)draw.c	\
					$(MAP_PATH)maps.c		\
					$(MAP_PATH)textures.c		\
					$(MAP_PATH)colors.c		\
					$(MAP_PATH)error_msg.c		\
					$(MAP_PATH)create_map.c		\
					$(MAP_PATH)linked_list.c		\
					$(MAP_PATH)run_through_map.c		\
          			$(RENDER_PATH)bresenham.c	\
					init_data.c cub3d.c 
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
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(WINDOW_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(RENDER_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(MAP_PATH))

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