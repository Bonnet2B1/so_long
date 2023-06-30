# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:31:57 by edelarbr          #+#    #+#              #
#    Updated: 2023/06/30 17:47:43 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources -----------------------------

NAME = so_long

SRCS =	srcs/*.c \
		srcs/*/*.c \

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
#				@ $(GCC) $(SRCS) -o $(NAME) MLX42/libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"
				@ $(GCC) $(SRCS) -o $(NAME) MLX42/build/libmlx42.a -I include -lglfw -L "/Users/edelarbr/.brew/Cellar/glfw/3.3.8/lib/"
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