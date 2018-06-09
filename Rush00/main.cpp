/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:46:21 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/09 13:16:17 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Characters.hpp"

WINDOW	*create_newwin(int height, int width, int startY, int startX)
{
	WINDOW *local_win;

	local_win = newwin(height, width, startY, startX);
	
	//Draw the spaceship with no spaces
	std::cout << "\e[?25h";
	std::cout << "<^>" << std::endl;

	//Refresh to show that box
	wrefresh(local_win);
	return(local_win);
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	//Refreshes the window to remove win
	wrefresh(local_win);
	//Deletes local_win
	delwin(local_win);
}

int main(void)
{
	WINDOW	*my_win;
	int ch, maxY, maxX;
	
	//initialising screen
	initscr();
	cbreak();

	keypad(stdscr, TRUE);
	
	//Set Window Dimensions
	getmaxyx(stdscr, maxY, maxX);

	//Set Character Box Dimensions;
	int height = 4;
	int width = 4;

	//Set Starting Point
	int startX = 0;
	int startY = 0;
	startX = 5;
	startY = startX;
	startY++;

	//Creating a center point.
	int centerY = (LINES - width) / 2;
	int centerX = (COLS - height) / 2;

	
	Characters player(0, centerX);

	printw("Press ESC to exit...");
	refresh();
	my_win = create_newwin(height, width, centerY, player.getPositionX());
	while((ch = getch()) != 27)
	{
		switch(ch)
		{
			case KEY_LEFT:
					destroy_win(my_win);
					my_win = create_newwin(height, width, centerY, --centerX);
					break;
			case KEY_RIGHT:	
					destroy_win(my_win);
					my_win = create_newwin(height, width, centerY, ++centerX);
					break;
			case KEY_UP:	
					destroy_win(my_win);
					my_win = create_newwin(height, width, --centerY, centerX);
					break;
			case KEY_DOWN:
					destroy_win(my_win);
					my_win = create_newwin(height, width, ++centerY, centerX);
					break;
			//Space Bar
			case 32:
					destroy_win(my_win);
					my_win = create_newwin(height, width, ++centerY, centerX);
					break;
		}
	}
	printw("Exiting...");
	endwin();

	return(0);
}
