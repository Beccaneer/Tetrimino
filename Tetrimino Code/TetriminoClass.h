//***************************A5 - Quadris*****************************
//
// Tetrimino Header
//
//********************************************************************


#ifndef __TETRIMINO_H__
#define __TETRIMINO_H__
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// *****************************
// Superclass for Tetriminos
// *****************************

// Contains the variables and functions for each individual block type

class Tetrimino{
protected:
    // Multi-dimensional vectors to represent small grids to show the shape of the blocks  
	std::vector<std::vector<std::string> > arrDefault; // Used by Grid
	std::vector<std::vector<std::string> > arrCurrent; // Used for testing purposes
    
    // List of co-ords respresenting the spots of each block
    std::pair <int,int>coArray[4]; // the co-ords in the small self-contained grid
	std::vector < std::pair <int,int> > coGridArray;  // the co-ords used in relation to the large GameGrid
	
	// Dimensions for the smaller grid - to be the smallest possible for each block
    int currH, currW; // currH = Height, currW = Width
    
    // Representing the type of block
	std::string type;   // Single character: "I", "T", "S" etc.
	
public:
	
	void rotate(std::string s); // rotates the Tetrimino, clockwise or counterclockwise
	
	// Below are simply "get" functions to avoid problems with storing variables privately
	std::vector<std::vector<std::string> > getarrDefault() {return arrDefault;};
	std::vector<std::vector<std::string> > getarrCurrent() {return arrCurrent;};
	
    std::pair <int,int> *getcoArray() {return coArray;};
	std::pair <int,int>  &getcoGridArray(int i) {return coGridArray[i];}; 
	
    int getcurrH() {return currH;};
	int getcurrW() {return currW;};
	
    std::string gettype() {return type;};
	
	friend std::ostream& operator<<(std::ostream &out, const Tetrimino &t); // cout operator
	
};

// *****************************
// Sub-classes for Tetriminos
// *****************************
// The constructors are stored separately in TetriminoConstructors.cc

// ********* I-Block *************
class Iblock:public Tetrimino{
   	
public:
	Iblock(); // constructor
};

// ********* J-Block *************
class Jblock: public Tetrimino{
	
public:
	Jblock();  // constructor
}; 

// ********* L-Block *************
class Lblock: public Tetrimino{
	
public:
	Lblock();  // constructor
}; 

// ********* O-Block *************
class Oblock: public Tetrimino{
public:
	Oblock();  // constructor
}; 

// ********* S-Block *************
class Sblock: public Tetrimino{
public:
	Sblock();  // constructor
}; 

// ********* Z-Block *************
class Zblock: public Tetrimino{
public:
	Zblock();  // constructor
}; 

// ********* T-Block *************
class Tblock: public Tetrimino{
public:
	Tblock();  // constructor
}; 

#endif
