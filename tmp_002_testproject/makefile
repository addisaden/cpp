CC = g++
OUT = tmp_002_testproject.out

all: hw
	$(CC) -o $(OUT) main.cpp *.o

hw:
	$(CC) -c hw.cpp

clean:
	rm *.o $(OUT)

run:
	./$(OUT)
