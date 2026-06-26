CXX = g++
FLAGS = -g -std=c++98 -Wall -Werror 
OBFS = main.o interface.o logic.o

all:
	./program

program: $(OBFS)
	$(CXX) $(FLAGS) $(OBFS) -o program

test:
	make ./test.o

interface.o: interface.cpp interface.h
	$(CXX) -c $(FLAGS) interface.cpp -o interface.o

logic.o: logic.cpp logic.h
	$(CXX) -c $(FLAGS) logic.cpp -o logic.o

main.o: main.cpp logic.h interface.h
	$(CXX) -c $(FLAGS) main.cpp -o main.o

test.o: test.cpp	
	$(CXX) $(FLAGS) test.cpp -o test.o

clean:
	rm -f *.o all