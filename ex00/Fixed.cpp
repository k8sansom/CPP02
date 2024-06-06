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
    return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}