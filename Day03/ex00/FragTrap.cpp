/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:48:25 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:02:28 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _Hp(100), _Energy(100), _Level(1){
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap constructor with string name argument called" << std::endl;
	this->_Name = name;
	this->_Hp = 100;
	this->_Energy = 100;
	this->_Level = 1;
	return;
}

std::string	 FragTrap::getName( void ) const {
	return this->_Name;
}

int	FragTrap::getHp( void ) const {
	return this->_Hp;
}

int	FragTrap::getEnergy( void ) const {
	return this->_Energy;
}

int	FragTrap::getLevel( void ) const {
	return this->_Level;
}

void    FragTrap::setName(std::string const name) {
	this->_Name = name;
	return;
}

void    FragTrap::setHp(int const hp) {
	this->_Hp = hp;
	return;
}

void    FragTrap::setEnergy(int const energy) {
	this->_Energy = energy;
	return;
}

void    FragTrap::setLevel(int const level) {
	this->_Level = level;
	return;
}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
	return;
}

void FragTrap::rangedAttack(std::string const & target) {
	if (
			((this->_Hp - 
			  (FragTrap::_RangedAttackDamage - FragTrap::_ArmourDamageReduction)) > 0)
			&&
			(this->_Energy > 0)
	   )
	{ 
		FragTrap::takeDamage(FragTrap::_RangedAttackDamage - FragTrap::_ArmourDamageReduction);
		std::cout << "Ranged attack fired!" << std::endl;
		std::cout << this->_RangedAttackDamage - this->_ArmourDamageReduction;
		std::cout << " damage taken from ";
		std::cout << target + " has ";
		std::cout << this->_Hp;  
		std::cout << " hp!" << std::endl;  
	}
	else { 
		if(
				(this->_Hp - 
				 (FragTrap::_RangedAttackDamage - FragTrap::_ArmourDamageReduction)) < 0)
		{
			std::cout << "Target destroyed!" << std::endl;  
		}
		if (this->_Energy <= 0)
			std::cout << "No Energy!" << std::endl; 
	}	
	return;
}

void FragTrap::meleeAttack(std::string const & target) {
	if (
			((this->_Hp - 
			  (FragTrap::_MeleeAttackDamage - FragTrap::_ArmourDamageReduction)) > 0)
			&&
			(this->_Energy > 0)
	   )
	{
		FragTrap::takeDamage(FragTrap::_MeleeAttackDamage - FragTrap::_ArmourDamageReduction);	
		std::cout << "Melee attack launched!" << std::endl;
		std::cout << this->_MeleeAttackDamage - this->_ArmourDamageReduction;
		std::cout << " damage taken from ";
		std::cout << target + " has "; 
		std::cout << this->_Hp;  
		std::cout << " hp!" << std::endl;  
	}
	else {
		if(
				(this->_Hp - 
				 (FragTrap::_MeleeAttackDamage - FragTrap::_ArmourDamageReduction)) < 0)
		{
			std::cout << "Target destroyed!" << std::endl;  
		}
		if (this->_Energy <= 0)
			std::cout << "No Energy!" << std::endl; 
	}
	return;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string attack = "";
	int attackDamage = 0;
	int randomNumber = rand() % 5;
	if (randomNumber == 0) {
		attackDamage = this->_FartGunDamage;
		attack = "Fart Gun";
	}else if (randomNumber == 1) {
		attackDamage = this->_NutPunchDamage;
		attack = "Nut Punch";
	}else if (randomNumber == 2) {
		attackDamage = this->_KissOfDeathDamage;
		attack = "Kiss Of Death Damage";
	}else if (randomNumber == 3) {
		attackDamage = this->_BaterangDamage;
		attack = "Baterang";
	} else if (randomNumber == 4) {
		attackDamage = this->_OodamaRasenganDamage;
		attack = "Oodama Rasenga";
	}

	if (
			((this->_Hp - 
			  (attackDamage - FragTrap::_ArmourDamageReduction)) > 0)
			&&
			(this->_Energy >= 25)
	   )
	{
		FragTrap::setEnergy(this->_Energy - 25);
		FragTrap::takeDamage(attackDamage - FragTrap::_ArmourDamageReduction);	
		std::cout << attack +  " attack launched!" << std::endl;
		std::cout << attackDamage - this->_ArmourDamageReduction;
		std::cout << " damage taken from ";
		std::cout << target + " has "; 
		std::cout << this->_Hp;  
		std::cout << " hp!" << std::endl;  
	}
	else {
		if(
				(this->_Hp - 
				 (attackDamage - FragTrap::_ArmourDamageReduction)) < 0)
		{
			std::cout << "Target destroyed!" << std::endl;  
		}
		if (this->_Energy <= 0)
			std::cout << "No Energy!" << std::endl; 
	}
	return;
}

void	FragTrap::takeDamage(unsigned int amount){
	this->_Hp = this->_Hp - amount;
}

void	FragTrap::beRepaired(unsigned int amount){
	this->_Hp = this->_Hp + amount;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Default Destructor called" << std::endl;
	return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	this->_Hp = rhs.getHp();
	this->_Energy = rhs.getEnergy();
	this->_Level = rhs.getLevel();
	return *this;	
}
