/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:56:54 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:21:32 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Characters::Characters(void)  : _alive(1), _positionY(0), _positionX(0), _maxY(0), _maxX(0) 
{
	return;
}

Characters::Characters(Characters const & src) 
{
	*this = src;
	return;
}

Characters::Characters(int positionY, int positionX, int maxY, int maxX, char shape)  : _alive(1) 
{
	this->_positionY = positionY;
	this->_positionX = positionX;
	this->_maxY = maxY;
	this->_maxX = maxX;
	this->_shape = shape;
	return;
}

void	Characters::moveCharacterUp()
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (y > 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(--y, x);
    	mvaddch(y, x, this->getShape());
	}
}

void	Characters::moveCharacterDown()
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (y < this->getMaxY() - 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(++y, x);
    	mvaddch(y, x, this->getShape());
	}
}

void	Characters::moveCharacterLeft()
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (x > 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(y, --x);
    	mvaddch(y, x, this->getShape());
	}
}

void	Characters::moveCharacterRight()
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (x < this->getMaxX() - 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(y, ++x);
    	mvaddch(y, x, this->getShape());
	}
}

void	Characters::setAliveStatus(bool alive)
{
	Characters::_alive = alive;
	return;
}

void	Characters::setShape(char c)
{
	Characters::_shape = c;
	return;
}

void	Characters::setPosition(int positionY, int positionX)
{
	this->_positionY = positionY;
	this->_positionX = positionX;
	return;
}

bool	Characters::getAliveStatus(void) const
{
	return this->_positionY;
}

int		Characters::getPositionY(void) const
{
	return this->_positionY;
}

int		Characters::getPositionX(void) const
{
	return this->_positionX;
}

int		Characters::getMaxY(void) const
{
	return this->_maxY;
}

int		Characters::getMaxX(void) const
{
	return this->_maxX;
}

char	Characters::getShape(void) const
{
	return this->_shape;
}

Characters	& Characters::operator=( Characters const & rhs )
{
	this->_alive = rhs.getAliveStatus();
	this->_positionY = rhs.getPositionY();
	this->_positionX = rhs.getPositionX();
	this->_shape = rhs.getShape();
	return *this;	
}

Characters::~Characters(void)
{	
	return;
}