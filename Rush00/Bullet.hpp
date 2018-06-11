/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 07:56:54 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/10 14:21:32 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
	#define BULLET_HPP

#include "ft_retro.hpp"

class Bullet : public Characters
{

	private:
		bool		_alive;
		int 		_positionY;
		int 		_positionX;
		int			_maxY;
		int			_maxX;
		char		_shape;

	public : 
		Bullet(void);
		Bullet(int posY, int posX, int maxX, int maxY, char shape);
		Bullet(Bullet const & src);	
		~Bullet(void);

        void moveBullet(char direction);
        void clearBullet(void) const;

		Bullet	& operator=(Bullet const & rhs);
};

#endif