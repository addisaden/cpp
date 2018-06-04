CC = g++ -std=c++11
CFLAGS = -I /usr/include/
LDFLAGS = -L /usr/lib/ -I /usr/include/
LDLIBS = -l glut -l GLEW -l GL

all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o triangle.out triangle.cpp

clean:
	rm -f *.o triangle

