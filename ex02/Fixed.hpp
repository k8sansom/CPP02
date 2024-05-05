#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

		Fixed(const int integer);
		Fixed(const float floating);

		float 	toFloat( void ) const;
		int 	toInt( void ) const;

		bool	operator>(Fixed const &f) const;
		bool	operator<(Fixed const &f) const;
		bool	operator>=(Fixed const &f) const;
		bool	operator<=(Fixed const &f) const;
		bool	operator==(Fixed const &f) const;
		bool	operator!=(Fixed const &f) const;

		Fixed	operator+(Fixed const &f);
		Fixed	operator-(Fixed const &f);
		Fixed	operator*(Fixed const &f);
		Fixed	operator/(Fixed const &f);

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream& str, const Fixed& func3);
#endif