OBJS = test.o numConverter.o baseCalc.o
EXE = convert
CC = g++-12
CFLAGS += -g -c -Wall -Werror -std=c++17
LFLAGS += -Wall

$(EXE) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

test.o : numConverter.h baseCalc.h
	$(CC) $(CFLAGS) test.cpp

baseCalc.o : baseCalc.h
	$(CC) $(CFLAGS) baseCalc.cpp

numConverter.o: numConverter.h
	$(CC) $(CFLAGS) numConverter.cpp

clean:
	rm -f *.o $(EXE)