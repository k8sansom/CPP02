/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:37:42 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/07 11:37:43 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//OLD////////////////////////////////////////////////////////////////////////////////////////////
Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &func) {
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(func.getRawBits());
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &func2) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &func2) {
		this->setRawBits(func2.getRawBits());
	}
	return (*this);
}
//A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

// A member function void setRawBits( int const raw ) that sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw ) {
	this->_rawValue = raw;
}

//NEW///////////////////////////////////////////////////////////////////////////////////////////
// A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value.
Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = (integer << Fixed::_bits);
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