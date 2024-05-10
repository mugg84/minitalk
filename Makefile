# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 09:23:31 by mmughedd          #+#    #+#              #
#    Updated: 2024/05/09 12:00:11 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c

SERVER = server.c

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

PRINTF_PATH = ft_printf/

PRINTF_NAME = libftprintf.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

PRINTF = $(PRINTF_PATH)$(PRINTF_NAME)

INCS = -I minitalk.h

CLIENT_OBJ = $(CLIENT:.c=.o)

SERVER_OBJ = $(SERVER:.c=.o)

NAME = minitalk

NAME_S = server

NAME_C = client

CC = cc

RM = rm -f

FLAGS = -g #-Wextra -Werror -Wall

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makeftprintf:
	make -sC $(PRINTF_PATH)

$(NAME): makeftprintf $(SERVER_OBJ) $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) $(PRINTF) $(INCS) -o $(NAME_S) 
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(PRINTF) $(INCS) -o $(NAME_C)
clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)
	make clean -C $(PRINTF_PATH)

fclean: clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)
	make fclean -C $(PRINTF_PATH)

re: fclean all

.phony: all clean fclean re makelibft