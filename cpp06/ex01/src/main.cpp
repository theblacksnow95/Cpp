#include "Serializer.hpp"

int	main(void)
{
	Data*data = new Data;
	data->value = 0;
	uintptr_t ptr = Serializer::serialize(data);
	Data *other = Serializer::deserialize(ptr);

	std::cout << BLE << "Data serialized: " << &ptr << RST << std::endl;
	std::cout << GRN << "Deserialized data: " << &other << RST << std::endl;
}
