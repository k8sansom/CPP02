#include "Fixed.hpp"

//OLD////////////////////////////////////////////////////////////////////////////////////////////
Fixed::Fixed() : _rawValue(0) {
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
	return (_rawValue);
}

void Fixed::setRawBits( int const raw ) {
	this->_rawValue = raw;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = (integer << Fixed::_bits);
}

Fixed::Fixed(const float floating) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawValue = roundf(floating * (1 << this->_bits));
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_rawValue / (float)(1 << this->_bits));
}

int	Fixed::toInt( void ) const {
	return (this->_rawValue >> this->_bits);
}

//NEW///////////////////////////////////////////////////////////////////////////////////////////
bool	Fixed::operator>(Fixed fixed) const {
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const {
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const {
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const {
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const {
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) {
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) {
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) {
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) {
	return (this->toFloat() / fixed.toFloat());
}

Fixed	&operator++();
Fixed	operator++(int);
Fixed	&operator--();
Fixed	operator--(int);


std::ostream	&operator<<(std::ostream &str, Fixed const &func) {
	str << func.toFloat();
	return (str);
}