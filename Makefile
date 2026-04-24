NAME			:= so_long
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

CLR_RMV			:= \033[0m
RED				:= \033[1;31m
GREEN			:= \033[1;32m
YELLOW			:= \033[1;33m
BLUE			:= \033[1;34m
CYAN 			:= \033[1;36m

SRCS			:=	srcs/closed_rectangle.c \
					srcs/count_obj.c \
					srcs/create_map.c \
					srcs/display_movements.c \
					srcs/freeall.c \
					srcs/freemap.c \
					srcs/ft_calloc.c \
					srcs/ft_itoa.c \
					srcs/ft_putnbr.c \
					srcs/ft_putstr.c \
					srcs/ft_split.c \
					srcs/ft_strdup_no_nl.c \
					srcs/ft_strjoin.c \
					srcs/ft_strlen.c \
					srcs/map_init.c \
					srcs/movements.c \
					srcs/parser.c \
					srcs/portal_animation.c \
					srcs/render_and_input.c \
					srcs/render_map.c \
					srcs/so_long.c \
					srcs/valid_file.c \
					srcs/valid_way.c \
					srcs/get_next_line/get_next_line.c \
					srcs/get_next_line/get_next_line_utils.c

MLX_DIR			:= MLX42
MLX_BUILD_DIR	:= $(MLX_DIR)/build
MLX_LIB			:= $(MLX_BUILD_DIR)/libmlx42.a
MLX_REPO		:= https://github.com/codam-coding-college/MLX42.git

UNAME_S			:= $(shell uname -s)
GLFW_PREFIX		:= $(shell brew --prefix glfw 2>/dev/null)

ifeq ($(UNAME_S),Darwin)
ifneq ($(GLFW_PREFIX),)
GLFW_LIB_PATH	:= -L"$(GLFW_PREFIX)/lib"
endif
LDLIBS			:= $(GLFW_LIB_PATH) -lglfw -framework Cocoa -framework OpenGL -framework IOKit -lm
else
LDLIBS			:= -ldl -lglfw -pthread -lm
endif

all: $(NAME)

$(NAME): $(MLX_LIB)
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@$(CC) $(CFLAGS) $(SRCS) $(MLX_LIB) $(LDLIBS) -o $(NAME)
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

$(MLX_DIR):
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)MLX42 $(CLR_RMV)..."
	@ echo "$(YELLOW)MLX42 not found$(CLR_RMV), cloning repository ..."
	@git clone --depth 1 $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	@ echo "$(CYAN)Building MLX42$(CLR_RMV) ..."
	@cmake -S $(MLX_DIR) -B $(MLX_BUILD_DIR)
	@cmake --build $(MLX_BUILD_DIR) -j4

clean:
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@$(RM) $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

mlxclean:
	@rm -rf $(MLX_DIR)
	@ echo "$(RED)Deleting $(CYAN)MLX42 $(CLR_RMV)folder ✔️"

re: fclean all

.PHONY: all clean fclean re mlxclean
