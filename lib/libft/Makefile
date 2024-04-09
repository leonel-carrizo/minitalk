# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 03:19:48 by lcarrizo          #+#    #+#              #
#    Updated: 2024/04/08 15:07:08 by lcarrizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME		= libft.a
HEADER		= -I../include
SRC_DIR		= ./
OBJ_DIR		= obj/
SRC		= $(wildcard $(SRC_DIR)*c) $(wildcard $(SRC_DIR)ft_printf/*c) \
		  $(wildcard $(SRC_DIR)get_next_line/*c)
OBJ		= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

#############################      COMMANDS    #################################

CC		= cc
RM 		= rm -fr
OPT		= -c
CFLAGS		= -Wall -Werror -Wextra $(HEADER)
AR		= ar rcs

#############################       RULES      ##################################

.SILENT:	$(OBJ) $(NAME) clean fclean

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		@echo "\n$(notdir $@) created\n"

$(OBJ_DIR):	
		@mkdir -p $(OBJ_DIR)
		@echo "\nCompailing libft...\n"	

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(OPT) $< -o $@

$(OBJ_DIR)%.o:	$(SRC_DIR)ft_printf/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(OPT) $< -o $@

$(OBJ_DIR)%.o:	$(SRC_DIR)get_next_line/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(OPT) $< -o $@

clean:		
		$(RM) $(OBJ_DIR) 
		@echo "\n* LIBFT  Object files deleted! *\n"

fclean:		clean
		$(RM) $(NAME)
		@echo "\n** LIBFT FULL CLEAN done! **\n"

re:		fclean all

.PHONY: all clean fclean re
