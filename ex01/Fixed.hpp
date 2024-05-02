#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_fixedPoint;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &func);
		~Fixed();
		Fixed &operator=(const Fixed &func2);
		
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};
#endif