/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:48:25 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:02:28 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Hp(100), _Energy(50), _Level(1){
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name): _Hp(100), _Energy(50), _Level(1){
	std::cout << "ClapTrap constructor with name argument called" << std::endl;
	this->_Name = name;
	return;
}

std::string	 ClapTrap::getName( void ) const {
	return this->_Name;
}

int	ClapTrap::getHp( void ) const {
	return this->_Hp;
}

int	ClapTrap::getEnergy( void ) const {
	return this->_Energy;
}

int	ClapTrap::getLevel( void ) const {
	return this->_Level;
}

void    ClapTrap::setName(std::string const name) {
	this->_Name = name;
	return;
}

void    ClapTrap::setHp(int const hp) {
	this->_Hp = hp;
	return;
}

void    ClapTrap::setEnergy(int const energy) {
	this->_Energy = energy;
	return;
}

void    ClapTrap::setLevel(int const level) {
	this->_Level = level;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_Hp = this->_Hp - amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	this->_Hp = this->_Hp + amount;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Default Destructor called" << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
	this->_Hp = rhs.getHp();
	this->_Energy = rhs.getEnergy();
	this->_Level = rhs.getLevel();
	return *this;	
}