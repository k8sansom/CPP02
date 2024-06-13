#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawValue;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed &operator=(const Fixed &func2);
		
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed(const int integer);
		Fixed(const float floating);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};

std::ostream& operator<<(std::ostream& str, const Fixed& func3);
#endif