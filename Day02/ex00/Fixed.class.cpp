#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
	
	return;
}

Fixed::Fixed(Fixed const & src) {
        std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed(void) {
        std::cout << "Destructor called" << std::endl;

	return;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

Fixed	& Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();

	return *this;	
}

void    Fixed::setRawBits(int const raw) {
        this->_fixedPointValue = raw;

        return;
}
