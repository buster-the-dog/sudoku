CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/tester

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/sudoku_main.o: src/sudoku_main.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku_main.o src/sudoku_main.cpp

obj/tester.o: src/tester.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/tester.o src/tester.cpp

# -------------------------
# Executables

bin/tester: obj/tester.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/tester obj/tester.o obj/sudoku_main.o
