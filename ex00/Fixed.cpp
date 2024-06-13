#include "Fixed.hpp"

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
//A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

// A member function void setRawBits( int const raw ) that sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw ) {
	this->_rawValue = raw;
}