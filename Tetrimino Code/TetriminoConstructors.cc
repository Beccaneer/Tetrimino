//***************************A5 - Quadris*****************************
//
// Constructors for the Tetriminos
//
//********************************************************************

#include "TetriminoClass.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Constructor - I-Block
//*****************************************************************************
Iblock::Iblock(){
	
	// Dimensions for the block
	currH = 1;
	currW = 4;
	
	// Block type
	type = "I";
	
	// Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrDefault.resize(1);
    for (int m = 0 ; m < 1 ; m++){
        arrDefault[m].resize(4);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(1);
    for (int m = 0 ; m < 1 ; m++){
        arrCurrent[m].resize(4);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
	arrDefault[0][0]=type;
	arrDefault[0][1]=type;
	arrDefault[0][2]=type;
	arrDefault[0][3]=type;
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
	for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 0;
	
	coArray[1].first = 0;
	coArray[1].second = 1;
	
	coArray[2].first = 0;
	coArray[2].second = 2;
	
	coArray[3].first = 0;
	coArray[3].second = 3;
    
    // Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
    for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 3;
        coGridArray[m].second = coArray[m].second;
	}      
	
} // END constructor Iblock


// Constructor - J-Block
//*****************************************************************************
Jblock::Jblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 3;
    
    // Block type
    type = "J";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(3);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(3);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[0][0] = type;
    arrDefault[1][0] = type;
    arrDefault[1][1] = type;
    arrDefault[1][2] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 0;
	
	coArray[1].first = 1;
	coArray[1].second = 0;
	
	coArray[2].first = 1;
	coArray[2].second = 1;
	
	coArray[3].first = 1;
	coArray[3].second = 2;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
	for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Jblock


// Constructor - L-Block
//*****************************************************************************
Lblock::Lblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 3;
    
    // Block type
    type = "L";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(3);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(3);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[0][2] = type;
    arrDefault[1][0] = type;
    arrDefault[1][1] = type;
    arrDefault[1][2] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 2;
	
	coArray[1].first = 1;
	coArray[1].second = 0;
	
	coArray[2].first = 1;
	coArray[2].second = 1;
	
	coArray[3].first = 1;
	coArray[3].second = 2;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
	for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Lblock


// Constructor - O-Block
//*****************************************************************************
Oblock::Oblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 2;
    
    // Block type
    type = "O";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(2);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(2);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[0][0] = type;
    arrDefault[1][0] = type;
    arrDefault[0][1] = type;
    arrDefault[1][1] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 0;
	
	coArray[1].first = 1;
	coArray[1].second = 0;
	
	coArray[2].first = 0;
	coArray[2].second = 1;
	
	coArray[3].first = 1;
	coArray[3].second = 1;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
	for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Oblock


// Constructor - S-Block
//*****************************************************************************
Sblock::Sblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 3;
    
    // Block type
    type = "S";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(3);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(3);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[1][0] = type;
    arrDefault[1][1] = type;
    arrDefault[0][1] = type;
    arrDefault[0][2] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 1;
	coArray[0].second = 0;
	
	coArray[1].first = 1;
	coArray[1].second = 1;
	
	coArray[2].first = 0;
	coArray[2].second = 1;
	
	coArray[3].first = 0;
	coArray[3].second = 2;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
	for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Sblock


// Constructor - Z-Block
//*****************************************************************************
Zblock::Zblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 3;
    
    // Block type
    type = "Z";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(3);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(3);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[0][0] = type;
    arrDefault[0][1] = type;
    arrDefault[1][1] = type;
    arrDefault[1][2] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 0;
	
	coArray[1].first = 0;
	coArray[1].second = 1;
	
	coArray[2].first = 1;
	coArray[2].second = 1;
	
	coArray[3].first = 1;
	coArray[3].second = 2;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
    for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Zblock


// Constructor - T-Block
//*****************************************************************************
Tblock::Tblock(){
	
	// Dimensions for the block
    currH = 2;
    currW = 3;
    
    // Block type
    type = "T";
    
    // Resizes the "arrDefault" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
    arrDefault.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrDefault[m].resize(3);
	}
	
	// Resizes the "arrCurrent" vector to the appropriate currH and currW
	// Initially arrDefault is the same as arrCurrent
	arrCurrent.resize(2);
    for (int m = 0 ; m < 2 ; m++){
        arrCurrent[m].resize(3);
	}
	
	// Sets the appropriate spots in arrDefault for the block type
    arrDefault[0][0] = type;
    arrDefault[0][1] = type;
    arrDefault[0][2] = type;
    arrDefault[1][1] = type;                 
	
	// Copies arrDefault to arrCurrent
	// Initially arrDefault is the same as arrCurrent
    for (int i = 0; i < currH; i++){
		for (int j = 0; j < currW; j++){
			arrCurrent[i][j] = arrDefault[i][j];
		}
	}
	
	// To set each individual co-ord of the block into coArray
	coArray[0].first = 0;
	coArray[0].second = 0;
	
	coArray[1].first = 0;
	coArray[1].second = 1;
	
	coArray[2].first = 0;
	coArray[2].second = 2;
	
	coArray[3].first = 1;
	coArray[3].second = 1;
	
	// Sets coGridArray to be equal to coArray
	coGridArray.resize(4);
	for (int m = 0; m < 4; m++){
        coGridArray[m].first = coArray[m].first + 2;
        coGridArray[m].second = coArray[m].second;
	}      
	
}; // END constructor Tblock