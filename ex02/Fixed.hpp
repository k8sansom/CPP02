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
		Fixed(const Fixed &func);
		~Fixed();
		Fixed &operator=(const Fixed &func2);
		
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed(const int integer);
		Fixed(const float floating);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

		bool	operator>(Fixed fixed) const;
		bool	operator<(Fixed fixed) const;
		bool	operator>=(Fixed fixed) const;
		bool	operator<=(Fixed fixed) const;
		bool	operator==(Fixed fixed) const;
		bool	operator!=(Fixed fixed) const;

		float	operator+(Fixed fixed);
		float	operator-(Fixed fixed);
		float	operator*(Fixed fixed);
		float	operator/(Fixed fixed);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);	
};

std::ostream& operator<<(std::ostream& str, const Fixed& func3);
#endif