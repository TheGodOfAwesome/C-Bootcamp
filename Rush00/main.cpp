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

	box(local_win, 0, 0);

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
	curs_set(FALSE);
	nodelay(stdscr, TRUE);

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
	
	Characters enemy(0, centerX);
	Characters player(0, centerX);
	
	refresh();
	my_win = create_newwin(maxY, maxX, 0, 0);
	int timer = 0;
	while(1)
	{
		if (timer == 60000)
		{
			int a = enemy.getPositionY();
			int b = enemy.getPositionX();
			mvaddch(a, b, ' ');
			enemy.setPosition(++a, b);
			mvaddch(a, b, 'x');
			timer = 0;
		}
		timer++;
		ch = getch();
		switch(ch)
		{
			case KEY_LEFT:
					mvaddch(centerY, centerX, ' ');
					mvaddch(centerY, --centerX, 'o');
					break;
			case KEY_RIGHT:	
					mvaddch(centerY, centerX, ' ');
					mvaddch(centerY, ++centerX, 'o');
					break;
			case KEY_UP:	
					mvaddch(centerY, centerX, ' ');
					mvaddch(--centerY, centerX, 'o');
					break;
			case KEY_DOWN:
					mvaddch(centerY, centerX, ' ');
					mvaddch(++centerY, centerX, 'o');
					break;
			//Space Bar
			case 32:
					destroy_win(my_win);
					my_win = create_newwin(height, width, ++centerY, centerX);
					break;
			case 27:
					endwin();
					return 0;
					break;
		}
	}
	endwin();

	return(0);
}
