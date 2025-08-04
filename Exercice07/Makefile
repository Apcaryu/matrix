CXX = g++

CFLAGS = -std=c++20

ARCHIVE = ar rcs

LIB = ../matrix_lib/libmatrix.a

TEST_FILE = test.cpp
OBJS_TEST = $(TEST_FILE:.cpp=.o)
TEST = exercice07.out

all : compile_lib $(TEST)

compile_lib:
	make -C ../matrix_lib/

$(TEST): $(OBJS_TEST)
	$(CXX) -o $(TEST) $(OBJS_TEST) $(LIB)

$(OBJS_TEST): $(TEST_FILE)
	$(CXX) $(CFLAGS) -c $(TEST_FILE) -o $(OBJS_TEST)

PHONY: clean
clean:
	-rm $(OBJS_TEST)

PHONY: fclean
fclean: clean
	-rm $(TEST)

re: fclean all
