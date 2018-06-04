# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 15:33:01 by kmuvezwa          #+#    #+#              #
#    Updated: 2018/06/04 15:58:15 by kmuvezwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

COMPILE = g++ 

FLAGS = -Wall -Wextra -Werror

FILES = megaphone.cpp

all : $(NAME)

$(NAME) :
		$(COMPILE) $(FILES) $(FLAGS) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all
