CFLAGS = -O -std=c++17 -Wall -Wextra
CC = g++ 

SOURCES = 	1Stream.cpp \
			2Containers.cpp \
			3Templates.cpp

EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

$(EXECUTABLES): % : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES)
