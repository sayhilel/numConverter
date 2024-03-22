#this Makefile follows a template that was given to me in 310, most Makefiles for projects will follow a similar format.
OBJS = BaseNumber.o
TEST = tester
EXE = calculator 
CC = g++
CFLAGS += -g -c -Wall -Werror -std=c++17
LFLAGS += -Wall

.PHONY: all $(EXE) $(TEST) clean

all: $(EXE)

$(EXE): main.o $(OBJS)
	$(CC) $(LFLAGS) main.o $(OBJS) -o $(EXE)

$(TEST): test.o $(OBJS)
	$(CC) $(LFLAGS) test.o $(OBJS) -o $(TEST)

main.o: BaseNumber.h baseCalc.h
	$(CC) $(CFLAGS) main.cpp

test.o: BaseNumber.h baseCalc.h
	$(CC) $(CFLAGS) test.cpp

baseCalc.o: baseCalc.h
	$(CC) $(CFLAGS) baseCalc.cpp

BaseNumber.o: BaseNumber.h
	$(CC) $(CFLAGS) BaseNumber.cpp

clean:
	rm -f *.o $(EXE) $(TEST)
