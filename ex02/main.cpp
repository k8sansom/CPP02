#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const c( Fixed(8.98f) / Fixed(0));
	Fixed const d( (Fixed(6785)) + Fixed(7896));
	std::cout << "a first: " << a << std::endl;
	std::cout << "a pre-incremented: " << ++a << std::endl;
	std::cout << "a now: " << a << std::endl;
	std::cout << "a post-incremented: " << a++ << std::endl;
	std::cout << "a after post-inc: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	// std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "max a and b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min a and b: " << Fixed::min( a, b ) << std::endl;
	return 0;
}