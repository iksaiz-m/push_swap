# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 21:24:04 by iksaiz-m          #+#    #+#              #
#    Updated: 2024/11/22 19:23:59 by iksaiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR    = libft/
LIBFT        = $(LIBFT_DIR)libft.a
HEADERS      = -I $(LIBFT_DIR)
CFLAGS       = -Wall -Wextra -Werror -g -O3 -g3

NAME         = push_swap
RM           = rm -rf
SRC = main.c arguments.c utils.c fillstack.c functions.c functions2.c \
	functions3.c functions4.c

OBJS = $(SRC:.c=.o)

all: $(MINILIBX) $(LIBFT) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  -L$(LIBFT_DIR) -lft -lm -lX11 -lXext

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	@make -C libft clean

fclean: clean
	$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
