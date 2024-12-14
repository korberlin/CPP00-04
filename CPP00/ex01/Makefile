NAME = phonebook

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = PhoneBook.cpp Contacts.cpp Main.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
