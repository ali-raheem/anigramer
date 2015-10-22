CC = gcc
CFLAGS = -O3 -g -s
OBJ = main.o anigramer.o
DEPS = anigramer.h
LIBS = -lreadline

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

anigramer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm $(OBJ)