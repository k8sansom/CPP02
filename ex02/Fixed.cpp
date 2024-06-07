#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &func) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(func.getRawBits());
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
	return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = (integer << Fixed::_bits);
}

Fixed::Fixed(const float floating) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floating * (1 << this->_bits));
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_fixedPoint / (float)(1 << this->_bits));
}

int	Fixed::toInt( void ) const {
	return (this->_fixedPoint >> this->_bits);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &func) {
	str << func.toFloat();
	return str;
}