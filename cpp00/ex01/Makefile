# Target & Flags
TARGET = PhoneBook
CC = c++
CPPFLAGS = -Wall -Wextra -Werror
CPP98 = -std=c++98

# Sources

SRC =  Contact.cpp PhoneBook.cpp main.cpp

# Objects

OBJ = $(SRC:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CPPFLAGS) $(CPP98) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CPP98) -c $< -o $@

clean:
	rm -rf $(OBJ)
	@echo "cleaning objects..."

fclean: clean
	rm -rf $(TARGET)
	@echo "Cleaning binary file..."

re: clean all

.PHONY: all clean fclean re
