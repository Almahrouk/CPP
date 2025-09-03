CPP = c++
WFLAGS = -Wall -Wextra -Werror -std=c++98 
EXTRA = -Wpedantic -Weffc++ -Wnon-virtual-dtor -Wold-style-cast -Wnull-dereference -Wsign-conversion

NAME = PhoneBook
SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(WFLAGS) $(EXTRA) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(WFLAGS) $(EXTRA) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re