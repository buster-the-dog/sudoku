#pragma once

#include <vector>

class Sudoku{
	public:
		Sudoku(); //constructor
		void Clear_Grid(); //Resets grid and fills with hyphens

		void Print(bool effects = true); //prints grid. if effects is set to false, it just prints the 9 strings on their own line

		bool Read_Grid(std::string filename);
		bool Solve();

	protected:
		std::vector <std::string> grid;

		bool Is_Row_Valid(int r);
		bool Is_Col_Valid(int c);
		bool Is_Panel_Valid(int r, int c);
		
		bool Recursive_Solve(int r, int c);
};
		
