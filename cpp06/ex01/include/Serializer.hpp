#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "colors.hpp"
# include <iostream>
# include <string>
# include "data.hpp"
# include <stdint.h>


// uintptr_t: unsigned integer type capable of holding a pointer to void

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
