/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:48:25 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:02:28 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _Hp(100), _Energy(100), _Level(1){
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap constructor with name argument called" << std::endl;
	this->_Name = name;
	this->_Hp = 100;
	this->_Energy = 100;
	this->_Level = 1;
	return;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::string challenge = "";
	std::string	_Greeting1 = "Prepare to die!";
	std::string	_Greeting2 = "Punk!!!";
	std::string	_Greeting3 = "Bring it on!";
	std::string	_Greeting4 = "Its time to call your mom, like I did last night!";
	std::string	_Greeting5 = "Shini!!!";

	int randomNumber = rand() % 5;
	if (randomNumber == 0) {
		challenge = _Greeting1;
	}else if (randomNumber == 1) {
		challenge = _Greeting2;
	}else if (randomNumber == 2) {
		challenge = _Greeting3;
	}else if (randomNumber == 3) {
		challenge = _Greeting4;
	} else if (randomNumber == 4) {
		challenge = _Greeting5;
	}

	std::cout <<  target + " " + challenge << std::endl;
	return;
}


void ClapTrap::rangedAttack(std::string const & target) {
	if (
			((this->_Hp - 
			  (ClapTrap::_RangedAttackDamage - ClapTrap::_ArmourDamageReduction)) > 0)
			&&
			(this->_Energy > 0)
	   )
	{ 
		ClapTrap::takeDamage(ClapTrap::_RangedAttackDamage - ClapTrap::_ArmourDamageReduction);
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
				 (ClapTrap::_RangedAttackDamage - ClapTrap::_ArmourDamageReduction)) < 0)
		{
			std::cout << "Target destroyed!" << std::endl;  
		}
		if (this->_Energy <= 0)
			std::cout << "No Energy!" << std::endl; 
	}	
	return;
}

void ClapTrap::meleeAttack(std::string const & target) {
	if (
			((this->_Hp - 
			  (ClapTrap::_MeleeAttackDamage - ClapTrap::_ArmourDamageReduction)) > 0)
			&&
			(this->_Energy > 0)
	   )
	{
		ClapTrap::takeDamage(ClapTrap::_MeleeAttackDamage - ClapTrap::_ArmourDamageReduction);	
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
				 (ClapTrap::_MeleeAttackDamage - ClapTrap::_ArmourDamageReduction)) < 0)
		{
			std::cout << "Target destroyed!" << std::endl;  
		}
		if (this->_Energy <= 0)
			std::cout << "No Energy!" << std::endl; 
	}
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Default Destructor called" << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	this->_Hp = rhs.getHp();
	this->_Energy = rhs.getEnergy();
	this->_Level = rhs.getLevel();
	return *this;	
}
