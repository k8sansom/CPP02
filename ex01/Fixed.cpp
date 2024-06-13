/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:37:42 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/07 13:31:00 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//OLD////////////////////////////////////////////////////////////////////////////////////////////
Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &func2) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &func2) {
		this->setRawBits(func2.getRawBits());
	}
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_rawValue);
}

void Fixed::setRawBits( int const raw ) {
	this->_rawValue = raw;
}

//NEW///////////////////////////////////////////////////////////////////////////////////////////
// A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value.
Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = integer << this->_bits;
}

//A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value.
Fixed::Fixed(const float floating) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawValue = roundf(floating * (1 << this->_bits));
}

// A member function float toFloat( void ) const that converts the fixed-point value to a floating-point value
float	Fixed::toFloat( void ) const {
	return ((float)this->_rawValue / (float)(1 << this->_bits));
}

//  A member function int toInt( void ) const that converts the fixed-point value to an integer value.
int	Fixed::toInt( void ) const {
	return (this->_rawValue >> this->_bits);
}

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream	&operator<<(std::ostream &str, Fixed const &func) {
	str << func.toFloat();
	return (str);
}