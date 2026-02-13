#################	Target & Flags	##################################

TARGET = zombieHorde
CC = c++
CFLAGS = -Wall -Wextra -Werror -g
C98 = -std=c++98

#################	Sources			##################################

SRC = main.cpp zombieHorde.cpp  Zombie.cpp

#################	Objects			##################################

OBJ = $(SRC:%.cpp=%.o)

#################	ANSI COLORS		##################################

GRN = \033[0;32m
YLL = \033[0;33m
RED = \033[0;31m
RST = \033[0m

#################	Rules			##################################

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "$(YLL)Compiling objects... $(RST)"
	@echo "$(YLL)Compiling Target $(GRN) $(TARGET)... $(RST)"
	$(CC) $(CFLAGS) $(C98) $(OBJ) -o $(TARGET)

%.o:%.cpp
	$(CC) $(CFLAGS) $(C98) -c $< -o $@

clean:
	@echo "$(YLL)Removing objects...$(RST)"
	rm -rf $(OBJ)

fclean:	clean
	@echo "$(YLL)Removing target $(RED) $(TARGET)... $(RST)"
	rm -rf $(TARGET)

re: clean all

.PHONY: all clean fclean re

.SILENT:
