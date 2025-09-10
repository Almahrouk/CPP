CPP = c++
WFLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = PhoneBook
SRCS = main.cpp PhoneBook.cpp PhoneBookUtils.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(WFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(WFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re