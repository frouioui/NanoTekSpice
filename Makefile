##
## EPITECH PROJECT, 2019
## OOP_NanoTekSpice
## File description:
## Makefile of the whole project
##

BINARY_NAME = nanotekspice

BINARY_UT_NAME = unit_tests

CXX	=	g++ $(HEADER)

PATH_TEST = ./Tests

PATH_SRC = ./Src

UT_SRC =	$(PATH_TEST)/Parser/TestsOpenFile.cpp						\
			$(PATH_TEST)/Parser/TestsParseFile.cpp						\
			$(PATH_TEST)/Parser/TestsErrorHandling.cpp					\
			$(PATH_TEST)/Parser/Line/TestsClearLine.cpp					\
			$(PATH_TEST)/Parser/Line/TestsCommentLine.cpp				\
			$(PATH_TEST)/Parser/Line/TestsSplitLineInTwo.cpp			\
			$(PATH_TEST)/Parser/Checker/TestsIsUseless.cpp				\
			$(PATH_TEST)/Components/TestsFactoryInput.cpp				\
			$(PATH_TEST)/Components/TestsCircuit.cpp					\
			$(PATH_TEST)/Argument/TestsGetFilename.cpp					\
			$(PATH_TEST)/Argument/TestsGetInputValue.cpp				\
			$(PATH_TEST)/Simulation/TestsSimulationDisplayPrompt.cpp	\
			$(PATH_TEST)/Simulation/TestsSimulationExitProg.cpp			\
			$(PATH_TEST)/Simulation/TestsSimulationGetAction.cpp		\
			$(PATH_TEST)/Simulation/TestsIsItKeyValue.cpp				\

MAIN = $(PATH_SRC)/Main.cpp									\

SRC =	$(PATH_SRC)/Parser/Parser.cpp						\
		$(PATH_SRC)/Parser/Checker.cpp						\
		$(PATH_SRC)/Parser/LineParser.cpp					\
		$(PATH_SRC)/Components/Factory.cpp					\
		$(PATH_SRC)/Components/Component.cpp				\
		$(PATH_SRC)/Components/Input.cpp					\
		$(PATH_SRC)/Components/Output.cpp					\
		$(PATH_SRC)/Components/True.cpp						\
		$(PATH_SRC)/Components/False.cpp					\
		$(PATH_SRC)/Components/C4001.cpp					\
		$(PATH_SRC)/Components/Circuit.cpp					\
		$(PATH_SRC)/Error.cpp								\
		$(PATH_SRC)/Argument/ArgumentParser.cpp				\
		$(PATH_SRC)/Simulation/Simulation.cpp				\

HEADER	=	-I./Include/

CXXFLAGS	=	-W -Wextra -Werror

LDFLAGS = -lcriterion -lgcov --coverage

OBJS	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	$(CXX) -o $(BINARY_NAME) $(HEADER) $(OBJS)

debug:
	$(CXX) -o $(BINARY_NAME) $(HEADER) $(SRC) $(MAIN) -g3

tests_run:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

tests_run_coverage:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1
	echo "\n"
	gcov *.gcno

doxygen:
	echo "<h1>TEST</h1>" >> docs/index.html

clean:
	rm -f $(OBJS) *.gc*

fclean: clean
	rm -f $(BINARY_UT_NAME) $(BINARY_NAME)

re: fclean all