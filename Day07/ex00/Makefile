# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 15:33:01 by kmuvezwa          #+#    #+#              #
#    Updated: 2018/06/04 18:00:25 by kmuvezwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

COMPILE = clang++ 

FLAGS = -Wall -Wextra -Werror

EXTRAFLAGS = -lncurses

FILES = Characters.cpp NonPlayerCharacter.cpp Bullet.cpp Arena.cpp main.cpp 

all : $(NAME)

$(NAME) :
		$(COMPILE) $(FLAGS) $(FILES) $(EXTRAFLAGS) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all
