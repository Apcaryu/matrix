CXX = g++

CFLAGS = -std=c++20

ARCHIVE = ar rcs

LIB = ../matrix_lib/libmatrix.a

SRCS_PATH = srcs/
SRCS_FILES = add.cpp scale.cpp subtract.cpp
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

NAME = addSubScale.a

TEST_FILE = test.cpp
OBJS_TEST = $(TEST_FILE:.cpp=.o)
TEST = exercice00.out

all : compile_lib $(NAME) $(TEST)

compile_lib:
	make -C ../matrix_lib/

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

PHONY: clean
clean:
	-rm $(OBJS)

PHONY: fclean
fclean: clean test_clean
	-rm $(NAME)

$(TEST): $(NAME) $(OBJS_TEST)
	$(CXX) -o $(TEST) $(OBJS_TEST) $(NAME) $(LIB)

$(OBJS_TEST):
	$(CXX) $(CFLAGS) -o $(OBJS_TEST) -c $(TEST_FILE)

PHONY: test_clean
test_clean: 
	-rm $(TEST)