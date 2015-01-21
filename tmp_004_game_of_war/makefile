CC = g++ -std=c++11
EXE = game_of_war.out

all: base
	$(CC) -o $(EXE) main.cpp *.o

base:
	$(CC) -c base.cpp

run:
	./$(EXE)

clean:
	rm -f *.o $(EXE)
