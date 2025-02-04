CXX = g++

CFLAGS = -std=c++20

ARCHIVE = ar rcs

HEADER_PATH = headers/
HEADER_FILES = Matrix.hpp
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

OBJS = $(HEADERS:.hpp=.o)

NAME = libmatrix.a

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $^

%.o: %.hpp
	$(CXX) $(CFLAGS) -x c++ -o $@ -c $<

.PHONY: clean
clean:
	-rm $(OBJS)

.PHONY: fclean
fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: test
test: $(NAME)
	$(CXX) -o test.out test.cpp libmatrix.a

test_clean:
	-rm test.out
