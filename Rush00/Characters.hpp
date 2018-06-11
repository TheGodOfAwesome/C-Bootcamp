/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Characters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:57:19 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:21:54 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERS_HPP
	#define CHARACTERS_HPP

#include "ft_retro.hpp"

class Characters{

	private:

	protected:
		bool		_alive;
		int 		_positionY;
		int 		_positionX;
		int			_maxY;
		int			_maxX;
		char		_shape;

	public : 
		Characters(void);
		Characters(int posY, int posX, int maxX, int maxY, char shape);
		Characters(Characters const & src);	
		~Characters(void);

		virtual void	moveCharacterUp();
		virtual void	moveCharacterDown();
		virtual void	moveCharacterLeft();
		virtual void	moveCharacterRight();

		virtual void	setAliveStatus(bool alive);
		virtual void	setPosition(int positionY, int positionX);
		virtual void	setShape(char c);
		
		virtual bool	getAliveStatus(void) const;
		virtual	int		getPositionY(void) const;
		virtual	int		getPositionX(void) const;
		virtual int		getMaxY(void) const;
		virtual int		getMaxX(void) const;
		virtual char	getShape(void) const;

		Characters	& operator=(Characters const & rhs);
};

#endif