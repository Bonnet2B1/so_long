# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 09:22:16 by marvin            #+#    #+#              #
#    Updated: 2022/11/23 18:39:49 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
## First part
#

SRCS			+=	ft_isalpha.c
SRCS			+=	ft_isdigit.c
SRCS			+=	ft_isalnum.c
SRCS			+=	ft_isascii.c
SRCS			+=	ft_isprint.c
SRCS			+=	ft_strlen.c
SRCS			+=	ft_memset.c
SRCS			+=	ft_bzero.c
SRCS			+=	ft_memcpy.c
SRCS			+=	ft_memmove.c
SRCS			+=	ft_strlcpy.c
SRCS			+=	ft_strlcat.c
SRCS			+=	ft_toupper.c
SRCS			+=	ft_tolower.c
SRCS			+=	ft_strchr.c
SRCS			+=	ft_strrchr.c
SRCS			+=	ft_strncmp.c
SRCS			+=	ft_memchr.c
SRCS			+=	ft_memcmp.c
SRCS			+=	ft_strnstr.c
SRCS			+=	ft_atoi.c
SRCS			+=	ft_calloc.c
SRCS			+=	ft_strdup.c

#
## Second part
#

SRCS			+=	ft_substr.c
SRCS			+=	ft_strjoin.c
SRCS			+=	ft_strtrim.c
SRCS			+=	ft_split.c
SRCS			+=	ft_itoa.c
SRCS			+=	ft_strmapi.c
SRCS			+=	ft_striteri.c
SRCS			+=	ft_putchar_fd.c
SRCS			+=	ft_putstr_fd.c
SRCS			+=	ft_putendl_fd.c
SRCS			+=	ft_putnbr_fd.c

#
## Part bonus
#

SRCS_BONUS		+=	ft_lstnew_bonus.c
SRCS_BONUS		+=	ft_lstadd_front_bonus.c
SRCS_BONUS		+=	ft_lstsize_bonus.c
SRCS_BONUS		+=	ft_lstlast_bonus.c
SRCS_BONUS		+=	ft_lstadd_back_bonus.c
SRCS_BONUS		+=	ft_lstdelone_bonus.c
SRCS_BONUS		+=	ft_lstclear_bonus.c
SRCS_BONUS		+=	ft_lstiter_bonus.c
SRCS_BONUS		+=	ft_lstmap_bonus.c

#	=== FLAGS ===

CFLAGS			+=	 -Wall
CFLAGS			+=	 -Wextra
CFLAGS			+=	 -Werror

#	=== KEYS WORDS ===

NAME		= libft.a

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

#	=== COMMANDES ===

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $@ $^

bonus:			$(OBJS) $(OBJS_BONUS)
				@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
				@rm -f $(OBJS) $(OBJS_BONUS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all
