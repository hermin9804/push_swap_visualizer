# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_visualizer.bash                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 00:29:53 by mher              #+#    #+#              #
#    Updated: 2022/04/20 03:35:58 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#==============================================================================
# Directroy

#	|- [ push_swap ] (Your push_swap dir)
#	|		|- Makefile
#	|- [ push_swap_visuzlizer ]
#			|- run_visualizer.bash
#			|- push_swap_tester (push_swap_tester by minckim)
#			|- Makefile

#==============================================================================
# path

PUSH_SWAP_DIR=../push_swap

TESTER_DIR=./push_swap_tester

#==============================================================================
# remove previous push_swap_out file

if [ -e push_swap_out ]
then
	rm push_swap_out
fi

#==============================================================================
# set ARG

if [ $1 ]
then
	export ARG=$($TESTER_DIR/random_numbers $1 1)
else
	export ARG=$($TESTER_DIR/random_numbers 10 1)
fi

#==============================================================================
# run

$PUSH_SWAP_DIR/push_swap $ARG >> push_swap_out

./visualizer $ARG
