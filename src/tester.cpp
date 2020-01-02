#include <iostream>
#include "sudoku.hpp"
using namespace std;

int main(int argc, char **argv){
	Sudoku s;
	string filename;

	if (argc != 2) {
		cerr << "Usage: ./tester [filename]\n";
	}

	filename = argv[1];

	if (!s.Read_Grid(filename)){
		cout << "Invalid Puzzle\n";
	}

	if (s.Solve()){
		s.Print();
	} else {
		cout << "Not solvable\n";
	}

	return 0;
}
