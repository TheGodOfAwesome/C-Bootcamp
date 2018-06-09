/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:47:36 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/08 17:05:07 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ClapTrap{
	private :
		std::string			_Name;	

		int 				_Hp;
		static const int	_MaxHp = 100;	
		int 				_Energy;
		static const int	_MaxEnergy = 100;
		int 				_Level;

	public :
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap	& operator=(ClapTrap const & rhs);

		std::string getName(void) const;
		int 		getHp(void) const;
		int			getEnergy(void) const;
		int			getLevel(void) const;

		void	setName(std::string const name);
		void	setHp(int const hp);
		void	setEnergy(int const hp);
		void	setLevel(int const hp);

		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};