#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include "sudoku.hpp"
using namespace std;
//implements functions defined in sudoku class

Sudoku::Sudoku(){
	Clear_Grid(); //clear grid sets you up with an new empty grid
} //constructor

void Sudoku::Clear_Grid(){
	string s;

	grid.resize(0);
	for (int i = 0; i < 9; i++){
		grid.push_back((string) "---------");
	}
} //Resets grid and fills with hyphens

void Sudoku::Print(bool effects){
	int i, j;

	if (!effects){
		for (i = 0; i < (int) grid.size(); i++){
			cout << grid[i] << '\n';
		}
	} else {
		for (i = 0; i < (int) grid.size(); i++){
			if ((i % 3) == 0 && i != 0) cout << endl;
			for (j = 0; j < 9; j++){
				if ((j % 3) == 0 && j != 0) cout << ' ';
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
} //prints grid. if effects is set to false, it just prints the 9 strings on their own line

bool Sudoku::Read_Grid(){
	int i;
	string s;

	grid.resize(0);

	while (getline(cin, s)){
		if (s == "") break;
		//check length
		if ((int) s.size() != 9) return false;
		//iterate thru string make sure all chars are valid
		for (int i = 0; i < (int) s.size(); i++){
			if ((s[i] - '0' > 9) && (s[i] >= 0) && (s[i] != '-')){
				return false;
			}
		}
		grid.push_back(s);
	}

	//if the grid is not the correct size, put it back to the empty grid and return false
	if (grid.size() != 9) {
		Clear_Grid();
		return false;
	}

	for (i = 0; i < 9; i++){
		if (!Is_Row_Valid(i) ||
			!Is_Col_Valid(i) ||
			!Is_Panel_Valid(i / 3, i % 3)){
			return false;
		}
	}


	return true;
}

bool Sudoku::Solve(){
	if (Recursive_Solve(0, 0)){
		return true;
	}
	return false;
}

bool Sudoku::Is_Row_Valid(int r){
	int i;
	vector <bool> check;

	check.resize(9, false);

	for (i = 0; i < 9; i++){
		if (grid[r][i] == '-') continue;
		if (check[grid[r][i] - '0'] == false){
			check[grid[r][i] - '0'] = true;
		} else {
			return false;
		}
	}

	return true;
}//checks if the given row is solved

bool Sudoku::Is_Col_Valid(int c){
	int i;
	vector <bool> check;

	check.resize(9, false);

	for (i = 0; i < 9; i++){
		if (grid[i][c] == '-') continue;
		if (check[grid[i][c] - '0'] == false){
			check[grid[i][c] - '0'] = true;
		} else {
			return false;
		}
	}

	return true;
}//checks if given col is valid

bool Sudoku::Is_Panel_Valid(int r, int c){
	int i, j;
	vector <bool> check;

	check.resize(9, false);

	for (i = 3 * r; i < 3 + (3 * r); i++){
		for (j = 3 * c; j < 3 + (3 * c); j++){
			if (grid[i][j] == '-') continue;
			if (check[grid[i][j] - '0'] == false){
				check[grid[i][j] - '0'] = true;
			} else {
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::Recursive_Solve(int r, int c){
	//base case: the puzzle is solved, so iterate thru the puzzle (starting at r and c)
	//and if there are no dashes it is solved.
	int i;

	while (r < 9 && grid[r][c] != '-'){
		c++;
		if (c == 9){
			c = 0;
			r++;
		}
	}

	//if r is 9, we are done
	if (r == 9) return true;

	//insert vals 1-9 in the place of the first dash found
	
	for (i = 1; i < 10; i++){
		grid[r][c] = i + '0';
		
		if (Is_Row_Valid(r) &&
			Is_Col_Valid(c) &&
			Is_Panel_Valid(r / 3, c / 3) &&
			Recursive_Solve(r, c)) {
			return true;
		}
	}

	//if we haven't returned by now, it's not a solution,
	//so set r and c back to - and ret false
	
	grid[r][c] = '-';
	return false;
}
