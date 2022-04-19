# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:24:10 by mher              #+#    #+#              #
#    Updated: 2022/04/20 03:39:26 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= visualizer

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

FT_DIR		= ./lib/Libft
GNL_DIR		= ./lib/libgnl	
TESTER_DIR	= ./push_swap_tester	
FT	 	= ft
GNL		= gnl


INCLUDE = -I./include

DATA_STRUCT_DIR = ./srcs/data_struct_src
DATA_STRUCT_SRC = \
	$(DATA_STRUCT_DIR)/list_utils.c \

OPERATOR_DIR = ./srcs/operator_src
OPERATOR_SRC = \
	$(OPERATOR_DIR)/operator_s.c \
	$(OPERATOR_DIR)/operator_p.c \
	$(OPERATOR_DIR)/operator_r.c \
	$(OPERATOR_DIR)/operator_rr.c \
	$(OPERATOR_DIR)/pop_push_swap_rotate.c \

INITALIZE_DIR = ./srcs/initalize_src
INITALIZE_SRC = \
	$(INITALIZE_DIR)/init.c \
	$(INITALIZE_DIR)/check.c \
	$(INITALIZE_DIR)/quick_sort.c \
	$(INITALIZE_DIR)/error_exit.c \

VISUALIZER_DIR =  ./srcs/visualizer_src
VISUALIZER_SRC = \
	$(OPERATOR_SRC) \
	$(DATA_STRUCT_SRC) \
	$(INITALIZE_SRC) \
	$(VISUALIZER_DIR)/visualizer.c \


PUSH_SWAP_OBJ	= $(PUSH_SWAP_SRC:.c=.o)
VISUALIZER_OBJ	= $(VISUALIZER_SRC:.c=.o)

all: $(NAME)

$(NAME) : $(VISUALIZER_OBJ)
	$(MAKE) -C $(FT_DIR) 
	$(MAKE) -C $(GNL_DIR) 
	$(MAKE) -C $(TESTER_DIR) 
	@$(CC) $(CFLAGS) -o $@ $^ \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	
clean:
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	@rm -f $(VISUALIZER_OBJ) 
	rm -f push_swap_out

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(TESTER_DIR) 
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
