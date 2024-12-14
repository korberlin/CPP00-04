NAME = materia

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) Executable $(NAME) created.$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)Compiling $< ... $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "CLeaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
