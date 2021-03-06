/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NonPlayerCharacter.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:59:47 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/09 07:59:49 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

NonPlayerCharacter::NonPlayerCharacter(void)  : _alive(1), _positionY(0), _positionX(0), _maxY(0), _maxX(0) 
{
	return;
}

NonPlayerCharacter::NonPlayerCharacter(NonPlayerCharacter const & src) 
{
	*this = src;
	return;
}

NonPlayerCharacter::NonPlayerCharacter(int positionY, int positionX, int maxY, int maxX, char shape)  : _alive(1) 
{
	this->_positionY = positionY;
	this->_positionX = positionX;
	this->_maxY = maxY;
	this->_maxX = maxX;
	this->_shape = shape;
	return;
}

void	NonPlayerCharacter::moveNonPlayerCharacter(void)
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (y < this->getMaxY() - 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(++y, x);
    	mvaddch(y, x, this->getShape());
	}
	else
		mvaddch(y, x, ' ');
}

void	NonPlayerCharacter::clearNonPlayerCharacter(void) const
{
	int y = this->getPositionY();
	int x = this->getPositionX();
	mvaddch(y, x, ' ');
	return;
}


NonPlayerCharacter	& NonPlayerCharacter::operator=( NonPlayerCharacter const & rhs )
{
	this->_alive = rhs.getAliveStatus();
	this->_positionY = rhs.getPositionY();
	this->_positionX = rhs.getPositionX();
	this->_shape = rhs.getShape();
	return *this;	
}

NonPlayerCharacter::~NonPlayerCharacter(void)
{	
	return;
}