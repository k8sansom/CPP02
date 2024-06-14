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
	if (this != &func2)
		this->setRawBits(func2.getRawBits());
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
	this->_rawValue = (integer << this->_bits);
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

float	Fixed::operator+(Fixed fixed) const {
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++() {
	this->_rawValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	++this->_rawValue;
	return (tmp);
}
Fixed	Fixed::operator--() {
	this->_rawValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	--this->_rawValue;
	return (tmp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed &Fixed::min(Fixed const &first, Fixed const &second) {
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
const Fixed &Fixed::max(Fixed const &first, Fixed const &second) {
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);	
}

std::ostream	&operator<<(std::ostream &str, Fixed const &func) {
	str << func.toFloat();
	return (str);
}