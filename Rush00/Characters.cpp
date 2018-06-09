/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:56:54 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/09 13:15:07 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Characters.hpp"

Characters::Characters(void)  : _alive(1), _positionY(0), _positionX(0) 
{
	return;
}

Characters::Characters(Characters const & src) 
{
	*this = src;
	return;
}

Characters::Characters(int positionY, int positionX)  : _alive(1) 
{
	this->_positionY = positionY;
	this->_positionX = positionX;
	return;
}

/*
void	Charactes::moveCharacter()
{
	destroy_win(my_win);
    my_win = create_newwin(height, width, centerY, --centerX)
}
*/

void	Characters::setAliveStatus(bool alive)
{
	Characters::_alive = alive;
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

Characters	& Characters::operator=( Characters const & rhs )
{
	this->_alive = rhs.getAliveStatus();
	this->_positionY = rhs.getPositionY();
	this->_positionX = rhs.getPositionX();
	return *this;	
}

Characters::~Characters(void)
{	
	return;
}
