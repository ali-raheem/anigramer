CC = gcc
CFLAGS = -O3 -g -s
#-std=c99
OBJ = main.o anigramer.o
DEPS = anigramer.h
#LIBS = -lreadline
BIN = anigramer

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
upx: $(BIN)
	rm -f $(BIN)-upx
	upx $(BIN) -o $(BIN)-upx
clean:
	rm -f $(OBJ) $(BIN) $(BIN)-upx
test:
	yes
