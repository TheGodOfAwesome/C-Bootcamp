/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:56:54 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:21:32 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Bullet::Bullet(void)  : _alive(1), _positionY(0), _positionX(0), _maxY(0), _maxX(0) 
{
	return;
}

Bullet::Bullet(Bullet const & src) 
{
	*this = src;
	return;
}

Bullet::Bullet(int positionY, int positionX, int maxY, int maxX, char shape)  : _alive(1) 
{
	this->_positionY = positionY;
	this->_positionX = positionX;
	this->_maxY = maxY;
	this->_maxX = maxX;
	this->_shape = shape;
	return;
}

void	Bullet::moveBullet(char direction)
{
	int y = this->getPositionY();
    int x = this->getPositionX();
	if (direction == 'u' && y > 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(--y, x);
    	mvaddch(y, x, '*');
        return;
	}
    else if (direction == 'd' && y > this->getMaxY() - 2) 
	{
    	mvaddch(y, x, ' ');
    	this->setPosition(++y, x);
    	mvaddch(y, x, '*');
        return;
	}
    mvaddch(y, x, ' ');
    return;
}

void	Bullet::clearBullet(void) const
{
	int y = this->getPositionY();
	int x = this->getPositionX();
	mvaddch(y, x, ' ');
	return;
}


Bullet	& Bullet::operator=( Bullet const & rhs )
{
	this->_alive = rhs.getAliveStatus();
	this->_positionY = rhs.getPositionY();
	this->_positionX = rhs.getPositionX();
	this->_shape = rhs.getShape();
	return *this;	
}

Bullet::~Bullet(void)
{	
	return;
}