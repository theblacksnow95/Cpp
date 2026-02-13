TARGET = megaphone
CC = c++
CPP_FLAGS =  -Wall -Wextra -Werror
STD98 = -std=c++98


SRC = megaphone.cpp


OBJ = megaphone.o


all: $(TARGET)

TARGET: $(OBJ)
	$(CC) $(CPP_FLAGS) $(STD98) -o $(TARGET)

clean:
	rm -rf $(OBJ)
	@echo "Cleaning objects"

fclean: clean
	rm -rf $(TARGET)

re: clean all

.PHONY: all clean fclean re

.SILENT:
