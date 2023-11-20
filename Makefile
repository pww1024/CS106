CFLAGS = -O -std=c++17 -Wall -Wextra
CC = g++ 
SRC = 1stream.cpp
OBJ = $(SRC:.cpp = .o) 

main: $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f main *.o
