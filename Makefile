DEPS = numConverter.o baseCalc.o
TEST = tester
EXE = calculator 
CC = g++-12
CFLAGS += -g -c -Wall -Werror -std=c++17
LFLAGS += -Wall

$(EXE) : main.o $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

$(TEST) : test.o $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TEST)
main.o : numConverter.h baseCalc.h
	$(CC) $(CFLAGS) main.cpp

test.o : numConverter.h baseCalc.h
	$(CC) $(CFLAGS) test.cpp

baseCalc.o : baseCalc.h
	$(CC) $(CFLAGS) baseCalc.cpp

numConverter.o: numConverter.h
	$(CC) $(CFLAGS) numConverter.cpp

clean:
	rm -f *.o $(EXE)
