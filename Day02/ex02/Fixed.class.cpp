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

Fixed::Fixed(int const intToConvert){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intToConvert << Fixed::_fractionalBits;

	return;
}

Fixed::Fixed(float const floatToConvert){
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = floatToConvert * (1 << Fixed::_fractionalBits);

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

int		Fixed::toInt(void) const{
		return (int) this->_fixedPointValue >> this->_fractionalBits;
}

float	Fixed::toFloat(void) const{
		return (float) this->_fixedPointValue  / (1 << this->_fractionalBits);
}

int & min() {
	std::cout<< "testing min" << std::endl;
}

int & max() {
	std::cout<< "testing max" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
