#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
};
#endif