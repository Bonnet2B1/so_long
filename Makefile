# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:31:57 by edelarbr          #+#    #+#              #
#    Updated: 2023/11/15 17:33:17 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources -----------------------------

NAME = so_long

SRCS =	srcs/closed_rectangle.c \
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
		srcs/get_next_line/get_next_line_utils.c \

OBJS :=	$(SRCS:.c=.o)

.c.o:
	@ $(GCC) -c $< -o $(<:.c=.o)

# ------------------------------ Flags -------------------------------

GCC = @gcc -Wall -Werror -Wextra

# ------------------------------ Colors ------------------------------

# Colors

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ so_long --------------------------------

RM			:=	rm -f

all: $(NAME)

$(NAME):
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(GCC) $(SRCS) -o $(NAME) MLX42/build/libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"
#				@ $(GCC) $(SRCS) -o $(NAME) MLX42/build/libmlx42.a -I include -lglfw -L "/Users/edelarbr/.brew/Cellar/glfw/3.3.8/lib/"
				@ echo "$(GREEN)$(NAME) created[0m ✔️"

# --  ---------------------------- Rules -----------------------------------

clean:
				@ $(RM) $(OBJS) $(OBJS_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM) $(NAME_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all fclean re
