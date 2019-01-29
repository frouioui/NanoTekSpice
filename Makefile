##
## EPITECH PROJECT, 2019
## OOP_NanoTekSpice
## File description:
## Makefile of the whole project
##

BINARY_NAME = nanotekspice

BINARY_UT_NAME = unit_tests

CXX	=	g++ $(HEADER)

PATH_TEST = ./tests

PATH_SRC = ./src

UT_SRC =	$(PATH_TEST)/parser/TestsOpenFile.cpp				\
			$(PATH_TEST)/parser/TestsClearLine.cpp				\
			$(PATH_TEST)/parser/TestsCommentLine.cpp			\
			$(PATH_TEST)/parser/TestsSplitLineInTwo.cpp			\
			$(PATH_TEST)/parser/TestsCreateNewChipsetInfo.cpp	\
			$(PATH_TEST)/parser/TestsGetLinks.cpp				\
			$(PATH_TEST)/parser/TestsParseFile.cpp				\

MAIN = $(PATH_SRC)/Main.cpp

SRC =	$(PATH_SRC)/parser/Parser.cpp			\
		$(PATH_SRC)/parser/ParserError.cpp		\

HEADER	=	-I./include/

CXXFLAGS	=	-W -Wextra -Werror

LDFLAGS = -lcriterion -lgcov --coverage

OBJS	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	$(CXX) -o $(BINARY_NAME) $(HEADER) $(OBJS)

run:
	echo "bite"

debug:
	$(CXX) -o $(BINARY_NAME) $(HEADER) $(SRC) $(MAIN) -g3

tests_run:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1

tests_run_coverage:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1
	echo "\n"
	gcov *.gcno

clean:
	rm -f $(OBJS) *.gc*

fclean: clean
	rm -f $(BINARY_UT_NAME) $(BINARY_NAME)

re: fclean all