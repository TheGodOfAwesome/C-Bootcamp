/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arena.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:57:19 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:21:54 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Arena::Arena(void)  : _maxY(0), _maxX(0) 
{
	return;
}

Arena::Arena(Arena const & src) 
{
	*this = src;
	return;
}

Arena::Arena(int maxY, int maxX)
{
	this->_maxY = maxY;
	this->_maxX = maxX;
	return;
}

void    Arena::create_arena(void) const
{
	//initialising screen
	initscr();
	cbreak();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	return;
}

WINDOW* Arena::create_newwin(int height, int width, int startY, int startX)
{
	WINDOW *local_win;

	local_win = newwin(height, width, startY, startX);

	box(local_win, 0, 0);

	//Refresh to show that box
	wrefresh(local_win);
	return(local_win);
}

void    Arena::destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	//Refreshes the window to remove win
	wrefresh(local_win);
	//Deletes local_win
	delwin(local_win);
}

int		Arena::getMaxY(void) const
{
	return this->_maxY;
}

int		Arena::getMaxX(void) const
{
	return this->_maxX;
}

Arena	& Arena::operator=( Arena const & rhs )
{
	this->_maxY = rhs.getMaxY();
	this->_maxX = rhs.getMaxX();
	return *this;	
}

Arena::~Arena(void)
{	
	return;
}