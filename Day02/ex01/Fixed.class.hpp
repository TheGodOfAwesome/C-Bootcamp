/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuvezwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:12:07 by kmuvezwa          #+#    #+#             */
/*   Updated: 2018/06/07 11:00:40 by kmuvezwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <string>

class Fixed{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		
		Fixed(void);
		Fixed(int const intToConvert);
		Fixed(float const floatToConvert);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		int getValue(void) const; 
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt (void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
