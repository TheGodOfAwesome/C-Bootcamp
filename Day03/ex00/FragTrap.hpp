/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:47:36 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:05:07 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class FragTrap{
	private :
		std::string			_Name;	

		int 				_Hp;
		static const int	_MaxHp = 100;	
		int 				_Energy;
		static const int	_MaxEnergy = 100;
		int 				_Level;
		static const int	_MeleeAttackDamage = 30;
		static const int	_RangedAttackDamage = 20;
		static const int	_FartGunDamage = 5;
		static const int	_NutPunchDamage = 99;
		static const int	_KissOfDeathDamage = 20;
		static const int	_BaterangDamage = 30;
		static const int	_OodamaRasenganDamage = 20;
		static const int	_ArmourDamageReduction = 5;

	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap	& operator=(FragTrap const & rhs);

		std::string getName(void) const;
		int 		getHp(void) const;
		int			getEnergy(void) const;
		int			getLevel(void) const;

		void	setName(std::string const name);
		void	setHp(int const hp);
		void	setEnergy(int const hp);
		void	setLevel(int const hp);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);
		void	fartGun(std::string const & target);
		void	nutPunch(std::string const & target);
		void	kissOfDeath(std::string const & target);
		void	baterangToss(std::string const & target);
		void	oodamaRasengan(std::string const & target);

};
