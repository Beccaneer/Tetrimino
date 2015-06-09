//***************************A5 - Quadris*****************************
//
// Next Block Function
//
//********************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include "TetriminoClass.h"
#include "NextBlock.h"

using namespace std;

// Fetch_Tetrimino Function
//***************************************************************************************
// Purpose: consumes a string and creates/returns a pointer to a block based on that type
Tetrimino* Fetch_Tetrimino(string s){
	Tetrimino *newblock;
	if (s == "I") {     // I-Block
		newblock = new Iblock();
	}
	if (s == "J") {    // J-Block
		newblock = new Jblock();
	}
	if (s == "L") {    // L-Block
		newblock = new Lblock();
	}
	if (s == "O") {    // O-Block
		newblock = new Oblock();
	}
	if (s == "S") {    // S-Block
		newblock = new Sblock();
	}
	if (s == "Z") {    // Z-Block
		newblock = new Zblock();
	}
	if (s == "T") {    // T-Block
		newblock = new Tblock();
	}
	return newblock;
}


// Next_zero Function
//***************************************************************************************
// Purpose: Returns the next block in level 0, from the file sequence.txt
Tetrimino* Next_zero(ifstream& filestr, int a){
	string s;
	if (filestr >> s){
		return Fetch_Tetrimino(s);
	}
	else {
		filestr.close();
		filestr.open("sequence.txt");//CHANGE THIS PATH
		return NextBlock(0, filestr, a);
	}	
}

// Next_one Function
//***************************************************************************************
// Purpose: Returns the next block in level 1, in accordance with the proper probability
Tetrimino* Next_one(int s){
	int seed = time(NULL);
	if (s != -1) {seed = s;};
	int random;
	string Tetrimino_array[12];    // the array of types of blocks for the proper porbability 
	Tetrimino_array[0] = "S";
	Tetrimino_array[1] = "Z";
	Tetrimino_array[2] = "I";
	Tetrimino_array[3] = "I";
	Tetrimino_array[4] = "T";
	Tetrimino_array[5] = "T";
	Tetrimino_array[6] = "J";
	Tetrimino_array[7] = "J";
	Tetrimino_array[8] = "L";
	Tetrimino_array[9] = "L";
	Tetrimino_array[10] = "O";
	Tetrimino_array[11] = "O";
	
	srand ( seed );
	random = rand() %11;           // gets a random place in the array
	
	return Fetch_Tetrimino(Tetrimino_array[random]);
}; 


// Next_two Function
//***************************************************************************************
// Purpose: Returns the next block in level 2, in accordance with the proper probability
Tetrimino* Next_two(int s){
	int seed = time(NULL);
	if (s != -1) {seed = s;};
	int random;
	string Tetrimino_array[7];     // array for types of blocks to give proper probability
	Tetrimino_array[0] = "S";
	Tetrimino_array[1] = "Z";
	Tetrimino_array[2] = "I";
	Tetrimino_array[3] = "T";
	Tetrimino_array[4] = "J";
	Tetrimino_array[5] = "L";
	Tetrimino_array[6] = "O";
	
	srand ( seed );
	random = rand() %6;            // gets random place in the array
	
	return Fetch_Tetrimino(Tetrimino_array[random]);
}; 


// Next_three Function
//***************************************************************************************
// Purpose: Returns the next block in level 3, in accordance with the proper probability
Tetrimino* Next_three(int s){
	int seed = time(NULL);
	if (s != -1) {seed = s;};
	int random;
	string Tetrimino_array[9];     // array for types of blocks to give proper probability
	Tetrimino_array[0] = "S";
	Tetrimino_array[1] = "S";
	Tetrimino_array[2] = "Z";
	Tetrimino_array[3] = "Z";
	Tetrimino_array[4] = "I";
	Tetrimino_array[5] = "T";
	Tetrimino_array[6] = "J";
	Tetrimino_array[7] = "L";
	Tetrimino_array[8] = "O";
	
	srand ( seed );
	random = rand() %8;      // gets random place in the array
	
	return Fetch_Tetrimino(Tetrimino_array[random]);
}; 

// NextBlock Function
//***************************************************************************************
// Purpose: Returns the next block by calling on the appropriate function for the level

Tetrimino* NextBlock(int level, ifstream& sream, int s){
	if (level == 0) {
		return Next_zero(sream, s);
	}
	if (level == 1) {
		return Next_one(s);
	}
	if (level == 2) {
		return Next_two(s);
	}
	if (level == 3) {
		return Next_three(s);
	}
}
