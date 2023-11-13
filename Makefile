# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:51:26 by yubi42            #+#    #+#              #
#    Updated: 2023/11/07 18:06:49 by yubi42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
NAME	= pipex

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= ft_printf.c ft_printf_utils.c ft_printf_err.c ft_printf_utils_err.c\
			ft_memcpy.c ft_split.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_substr.c \
			pipex_err.c pipex_new_branch.c pipex_utils.c pipex_path.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
MAIN	= main.c
MAIN_B = main_bonus.c

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
MAIN_OBJ = $(OBJ_PATH)$(MAIN:.c=.o)
MAIN_B_OBJ = $(OBJ_PATH)$(MAIN_B:.c=.o)

INCS	= -I include

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(MAIN_OBJ): 
	$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_OBJ) $(INCS)
	
$(NAME): $(OBJ_PATH) $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(MAIN_B_OBJ):
	$(CC) $(CFLAGS) -c $(MAIN_B) -o $(MAIN_B_OBJ) $(INCS)

bonus: $(OBJ_PATH) $(OBJS) $(MAIN_B_OBJ)
	$(CC) $(CFLAGS) $(MAIN_B_OBJ) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re bonus