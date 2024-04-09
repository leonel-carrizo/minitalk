# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 13:05:39 by lcarrizo          #+#    #+#              #
#    Updated: 2024/04/09 15:20:34 by lcarrizo         ###    ###london.com     #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME			=
NAME_SERVER		= server
NAME_CLIENT		= client
LIBFT			= lib/libft/libft.a
LIBFT_DIR		= lib/libft/
INCLUDE			= include/
UTILS_SRC		= utils/
SRC_DIR			= src/
OBJ_DIR			= .obj/

# for server #
SRCS_SERVER		= $(wildcard $(SRC_DIR)server_src/*.c)
OBJ_SERVER		= $(addprefix $(OBJ_DIR)server/, $(notdir $(SRCS_SERVER:.c=.o)))

# for client #
SRCS_CLIENT		= $(wildcard $(SRC_DIR)client_src/*.c)
OBJ_CLIENT		= $(addprefix $(OBJ_DIR)client/, $(notdir $(SRCS_CLIENT:.c=.o)))

#############################    COMMANDS   ##################################

CC			= cc
RM 			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)

################################    RULES    ###################################

.SILENT:
# .SILENT:		$(NAME) $(OBJ_SERVER) $(OBJ_CLIENT) clean fclean

all:			$(LIBFT) $(NAME_SERVER) $(NAME_CLIENT) 

$(LIBFT):	
			@make -C $(LIBFT_DIR)

$(NAME):		$(NAME)

$(NAME_SERVER):		$(OBJ_SERVER)
			$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER) $(LIBFT) -g
			@echo "Server executable created!"

$(NAME_CLIENT):		$(OBJ_CLIENT)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFT) -g
			@echo "Client executable created!"

$(OBJ_DIR)server/%.o:	$(SRC_DIR)server_src/%.c
			@mkdir -p $(OBJ_DIR)/server
			@echo "Object Server Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)client/%.o:	$(SRC_DIR)client_src/%.c
			@mkdir -p $(OBJ_DIR)/client
			@echo "Object Client Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

# create a program which can be debugged with gdb.
debug:			$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS_SERVER) $(wildcard $(UTILS_SRC)/*.c) $(LIBFT) -o $(NAME_SERVER) -g
			$(CC) $(CFLAGS) $(SRCS_CLIENT) $(wildcard $(UTILS_SRC)/*.c) $(LIBFT) -o $(NAME_CLIENT) -g
			@echo "Debugables Created!"

clean:		
			$(RM) $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "** clean minitalk done!**"
			
fclean:			clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)
			$(RM) ./libft.a
			@make -C $(LIBFT_DIR) fclean
			@echo "** full clean minitalk done!**"

re:			fclean all

.PHONY: all clean fclean re

