#include "functions.hpp"

class check
{
	private:
		int	_n;
	public:
		check(void): _n(0) {}
		check(int n): _n(n) {}
		~check() {}

		check & operator= (check & a) { _n = a._n; return *this; }
		bool operator==( check const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( check const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( check const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( check const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( check const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( check const & rhs ) const { return (this->_n <= rhs._n); }

		int getNum() const {return _n;}
};

std::ostream & operator<<(std::ostream & o, const check &a) { o << a.getNum(); return o; }


int main()
{
	std::cout << YLL << "Test from the subject" << RST << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << PRL << "Another test" << RST << std::endl;
	{
		float a, b;
		a = 10.987, b = 539.123;
		std::cout << GRN << "Base values: " << a << " " << b  << RST << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << PRL << "Another test with complex type" << RST << std::endl;
	{
		check a(10), b(18);
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	return (0);
}
