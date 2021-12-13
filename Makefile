# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 10:42:23 by heahn             #+#    #+#              #
#    Updated: 2021/11/04 04:02:27 by heahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = minitalk
SERVER = server
CLIENT = client

HEADER = minitalk.h
SERVER_SRC = server.c
CLIENT_SRC = client.c
SRC = ft_utils.c\

SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
OBJS = $(SRC:.c=.o)

$(NAME): $(SERVER) $(CLIENT)



RM	= rm -rf
LIB = ar rcu
CC = gcc
CFLAGS = -Wall -Wextra -Werror



all	: $(NAME)

$(SERVER): $(SERVER_OBJS) $(OBJS)
	@echo "==COMPILE $(SERVER)=="
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(OBJS)

$(CLIENT): $(CLIENT_OBJS) $(OBJS)
	@echo "==COMPILE $(CLIENT)=="
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(OBJS)

clean : 
	@echo "==REMOVE OBJECT FILE=="
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS)

fclean : clean
	@echo "==REMOVE $(NAME)=="	
	@$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re bonus
