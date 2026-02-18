#ifndef FIXED_HPP
#define FIXED_HPP


# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
private:
	int					_fpValue;
	static const int	_frBits;
public:
	Fixed();
	Fixed(int const value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed& operator= (const Fixed& other);
	~Fixed();

	// comparison operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// arithmetic operators
	float	operator+(const Fixed& other) const;
	float	operator-(const Fixed& other) const;
	float	operator*(const Fixed& other) const;
	float	operator/(const Fixed& other) const;

	// increment/decrement operators
	Fixed	operator++( void );
	Fixed	operator--( void );
	Fixed	operator++(int);
	Fixed	operator--(int);

	// min max memeber functions
	static Fixed&	min(Fixed& n1, Fixed& n2);
	static const Fixed&	min(const Fixed& n1,const Fixed& n2);
	static Fixed&	max(Fixed& n1, Fixed& n2);
	static const Fixed&	max(const Fixed &n1,const Fixed& n2);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& obj);

#endif
