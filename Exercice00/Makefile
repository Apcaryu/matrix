CXX = g++

CFLAGS = -std=c++20

ARCHIVE = ar rcs

LIB = ../matrix_lib/libmatrix.a

TEST_FILE = test.cpp
OBJS_TEST = $(TEST_FILE:.cpp=.o)
TEST = exercice00.out

all : compile_lib $(TEST)

compile_lib:
	make -C ../matrix_lib/

.PHONY: clean
clean:
	-rm $(OBJS_TEST)

.PHONY: fclean
fclean: clean
	-rm $(TEST)

re: fclean all

$(TEST): $(OBJS_TEST)
	$(CXX) -o $(TEST) $(OBJS_TEST) $(LIB)

$(OBJS_TEST): $(TEST_FILE)
	$(CXX) $(CFLAGS) -c $(TEST_FILE) -o $(OBJS_TEST)

#$(OBJS_TEST):
#	$(CXX) $(CFLAGS) -o $(OBJS_TEST) -c $(TEST_FILE)
