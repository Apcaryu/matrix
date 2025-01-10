CXX = g++

ARCHIVE = ar rcs

SRCS_PATH = src/

SRCS_FILES = 	Matrix.cpp\
				Vector.cpp

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

NAME = libmatrix.a

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $^

%.o: %.cpp
	$(CXX) -o $@ -c $<

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

test: $(NAME)
	$(CXX) -o test.out test.cpp libmatrix.a

test_clean:
	rm test.out

.PHONY: all clean fclean re test test_clean