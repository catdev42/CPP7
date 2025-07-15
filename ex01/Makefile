#***************#
#* INGREDIENTS *#
#***************#

SRC = main.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic -g

NAME = iter

#****************#
#*    RECIPE    *#
#****************#

all: $(NAME)

obj/%.o: %.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

check: $(OBJ)
	$(CC) $(CPPFLAGS) -g $(OBJ) -o $(NAME)
	valgrind ./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf obj
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all check clean fclean re

#**********#
#* Colors *#
#**********#

GREEN := \033[32m
RED := \033[31m
YELLOW := \033[33m
BLUE := \033[34m
MAGENTA := \033[35m
CYAN := \033[36m
WHITE := \033[37m
RESET := \033[0m

# Text formatting
BOLD := \033[1m
DIM := \033[2m
ITALIC := \033[3m
UNDERLINE := \033[4m
