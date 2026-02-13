#################	TARGET & FLAGS	##################################

TARGET = clapTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -g
C98 = -std=c++98

SRCDIR = src
OBJDIR = obj
INCLUDE = include
#################	SOURCES			##################################

SRC = $(SRCDIR)/main.cpp $(SRCDIR)/ClapTrap.cpp

#################	OBJECTS			##################################

OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#################	ANSI COLORS		##################################

GRN = \033[0;32m
YLL = \033[0;33m
RED = \033[0;31m
RST = \033[0m

#################	RULES			##################################

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "$(YLL)Compiling objects... $(RST)"
	@echo "$(YLL)Compiling Target $(GRN) $(TARGET)... $(RST)"
	$(CC) $(CFLAGS) -I$(INCLUDE) $(C98)  $(OBJ) -o $(TARGET)

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(C98) -c $< -o $@

clean:
	@echo "$(YLL)Removing objects...$(RST)"
	rm -rf $(OBJ)

fclean:	clean
	@echo "$(YLL)Removing target $(RED) $(TARGET)... $(RST)"
	rm -rf $(TARGET)

re: clean all

.PHONY: all clean fclean re del

.SILENT:
