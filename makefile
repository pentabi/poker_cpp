HEADERS = deck.h card.h rank.h pokerhand.h SortedLinkedList.h
#(listing all header files here, separated by space)
SOURCES = $(HEADERS:.h=.cpp)
OBJECTS = $(HEADERS:.h=.o)
MAINSOURCE = PA2.cpp
MAINOBJ = $(MAINSOURCE:.cpp=.o)
TESTSOURCE = testPA2.cpp
TESTOBJ = $(TESTSOURCE:.cpp=.o)
TESTEXEC = testPA2
EXEC = Project2

$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ $^ -o $@

$(TESTEXEC): $(OBJECTS) $(TESTOBJ)
	g++ $^ -o $@

$(TESTOBJ): $(TESTSOURCE) $(HEADERS)
	g++ -c $< -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o
	rm -I `find ./ -type f -executable`
