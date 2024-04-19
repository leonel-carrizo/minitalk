# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 13:05:39 by lcarrizo          #+#    #+#              #
#    Updated: 2024/04/19 18:34:11 by lcarrizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME			=
NAME_SERVER		= server
NAME_CLIENT		= client
LIBFT			= lib/libft/libft.a
LIBFT_DIR		= lib/libft/
INCLUDE			= include/
UTILS_DIR		= utils/
SRC_DIR			= src/
OBJ_DIR			= .obj/

SRCS_UTILS		= $(wildcard $(UTILS_DIR)*.c)
OBJ_UTILS		= $(addprefix $(OBJ_DIR)utils/, $(notdir $(SRCS_UTILS:.c=.o)))

# for server #
SRCS_SERVER		= $(wildcard $(SRC_DIR)server_src/*.c)
OBJ_SERVER		= $(addprefix $(OBJ_DIR)server/, $(notdir $(SRCS_SERVER:.c=.o)))

# for client #
SRCS_CLIENT		= $(wildcard $(SRC_DIR)client_src/*.c)
OBJ_CLIENT		= $(addprefix $(OBJ_DIR)client/, $(notdir $(SRCS_CLIENT:.c=.o)))

# for bonus
SRCS_SERVERB		= $(SRC_DIR)bonus/server_bonus.c
OBJ_SERVERB		= $(OBJ_DIR)bonus/server_bonus.o
SRCS_CLIENTB		= $(SRC_DIR)bonus/client_bonus.c
OBJ_CLIENTB		= $(OBJ_DIR)bonus/client_bonus.o

#############################    COMMANDS   ##################################

CC			= cc
RM 			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)

################################    RULES    ###################################

.SILENT:

all:			$(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
			@make -s -C $(LIBFT_DIR)

$(NAME):		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_SERVER) $(OBJ_UTILS)
			$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) $(LIBFT) -o server  -g
			@echo "Server executable created!"

$(NAME_CLIENT):		$(OBJ_CLIENT) $(OBJ_UTILS)
			$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) $(LIBFT) -o client -g
			@echo "Client executable created!"

$(OBJ_DIR)server/%.o:	$(SRC_DIR)server_src/%.c
			@mkdir -p $(OBJ_DIR)/server
			@echo "Object Server Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)client/%.o:	$(SRC_DIR)client_src/%.c
			@mkdir -p $(OBJ_DIR)/client
			@echo "Object Client Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o:	$(UTILS_DIR)%.c
			@mkdir -p $(OBJ_DIR)/utils
			@echo "Object Utils Directory Created"
			$(CC) $(CFLAGS) -c $< -o $@

bonus:			$(LIBFT) $(OBJ_SERVERB) $(OBJ_CLIENTB) $(OBJ_UTILS)
			$(CC) $(CFLAGS) $(OBJ_SERVERB) $(OBJ_UTILS) $(LIBFT) -o $(NAME_SERVER)
			@echo "Server BONUS executable created!"
			$(CC) $(CFLAGS) $(OBJ_CLIENTB) $(OBJ_UTILS) $(LIBFT) -o $(NAME_CLIENT)
			@echo "Client BONUS executable created!"

$(OBJ_DIR)bonus/%.o:	$(SRC_DIR)bonus/%.c
			@mkdir -p $(OBJ_DIR)/bonus
			@echo "Object BONUS Created!"
			$(CC) $(CFLAGS) -c $< -o $@

# create executables which can be debugged with gdb.
debug:			$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS_SERVER) $(wildcard $(UTILS_DIR)/*.c) $(LIBFT) -o $(NAME_SERVER) -g
			$(CC) $(CFLAGS) $(SRCS_CLIENT) $(wildcard $(UTILS_DIR)/*.c) $(LIBFT) -o $(NAME_CLIENT) -g
			@echo "Debugables Created!"

clean:		
			$(RM) $(OBJ_DIR)
			@make -s -C $(LIBFT_DIR) clean
			@echo "** clean minitalk done!**"
			
fclean:			clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)
			$(RM) ./libft.a
			@make -s -C $(LIBFT_DIR) fclean
			@echo "** full clean minitalk done!**"

re:			fclean all

.PHONY: all clean fclean re bonus
