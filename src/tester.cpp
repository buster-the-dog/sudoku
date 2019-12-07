#include <iostream>
#include "sudoku.hpp"
using namespace std;

int main(){
	Sudoku s;

	if (!s.Read_Grid()){
		cout << "Invalid Puzzle\n";
	}

	if (s.Solve()){
		s.Print();
	} else {
		cout << "Not solvable\n";
	}

	return 0;
}
