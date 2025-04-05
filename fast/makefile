CC = g++
CFLAGS = -Wall -Wdeprecated -Oz
LIBS = -lncurses

OBJS = main.o renderer.o sort_array.o algorithms.o

main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main
