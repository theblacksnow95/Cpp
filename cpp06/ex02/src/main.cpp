#include "Serializer.hpp"

int	main(void)
{
	Data data;
	data.value = 42;
	Data*	start = &data;
	uintptr_t ptr = Serializer::serialize(start);
	Data *other = Serializer::deserialize(ptr);

	std::cout << BLE << "Data serialized:\t" << start << RST << std::endl;
	std::cout << GRN << "Deserialized data:\t" << other << RST << std::endl;
	std::cout << YLL << other->value << RST << std::endl;
}
