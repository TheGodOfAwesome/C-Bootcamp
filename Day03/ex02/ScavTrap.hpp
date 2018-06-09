/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:47:36 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:05:07 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap  : public ClapTrap{
	private :
		std::string			_Name;	

		int 				_Hp;
		static const int	_MaxHp = 100;	
		int 				_Energy;
		static const int	_MaxEnergy = 50;
		int 				_Level;
		static const int	_MeleeAttackDamage = 20;
		static const int	_RangedAttackDamage = 15;

		static const int	_ArmourDamageReduction = 3;

	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap	& operator=(ScavTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	challengeNewcomer(std::string const & target);

};
