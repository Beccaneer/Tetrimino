//***************************A5 - Quadris*****************************
//
// Tetrimino Member Functions
//
//********************************************************************


#include "TetriminoClass.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Rotate Function
//***************************************************************************************
// Purpose: to update the current block by rotating it clock-wise or counter-clock-wise
//          depending on input

void Tetrimino::rotate (string s){
	
    int tempH = currH;
	int tempW = currW;
	
	// switching height and width in order to rotate
    currH = tempW;
	currW = tempH;
    
    string temparray[currH][currW];
    pair <int,int>tempcoords[4]; 
    
    // Counter-Clockwise Rotation
	if (s == "ccw"){
		if (type =="O"){  
			return;  // O-Block doesn't need to rotate, so just exit
		}
		for (int m = 0; m < 4; m++){
			if (m == 0){
				tempcoords[m].first = abs((1 - (currH - coArray[3].second)));  // changing Y coord
				tempcoords[m].second = coArray[3].first;                       // changing X coord
			} else {
				tempcoords[m].first = abs((1 - (currH - coArray[m-1].second)));// changing Y coord
				tempcoords[m].second = coArray[m-1].first;                     // changing X coord
			}
		} // for
	} // if
	
	// Clockwise Rotation
    else if (s == "cw") {
		if (type =="O"){
            return;  // O-Block doesn't need to rotate, so just exit
		}
		for (int m = 0; m < 4; m++){
			if (m == 0){
				tempcoords[m].first = coArray[3].second;                       // changing Y coord
				tempcoords[m].second = abs(1 - (currW - coArray[3].first));    // changing X coord
			} else {
                tempcoords[m].first = coArray[m-1].second;                     // changing Y coord
                tempcoords[m].second = abs(1 - (currW - coArray[m-1].first));  // changing X coord
			}
		} // for
	} // else if
	
	// To copy the recently updated coords into coArray and coGridArray to be used in Grid
	for (int m = 0 ; m < 4; m++){
		
        temparray[tempcoords[m].first][tempcoords[m].second] = type;
		coArray[m].first = tempcoords[m].first;
		coArray[m].second = tempcoords[m].second;
		
        if (currW == 3){
            coGridArray[m].first = tempcoords[m].first + 2;
            coGridArray[m].second = tempcoords[m].second;
        }
        else if (type != "I"){
            coGridArray[m].first = tempcoords[m].first + 1;
            coGridArray[m].second = tempcoords[m].second;
		}
		else if (type == "I"){
			if (currW == 4){
                coGridArray[m].first = tempcoords[m].first + 3;
                coGridArray[m].second = tempcoords[m].second;
			} else{
                coGridArray[m].first = tempcoords[m].first;
                coGridArray[m].second = tempcoords[m].second;
			}
			
		}
		
	} // for
	
	
	arrCurrent.resize(4);
    for (int m = 0 ; m < 4 ; m++){
        arrCurrent[m].resize(1);
	}
	
	/*
	 for (int i = 0 ; i < currH ; i++){
	 for (int j = 0 ; j < currW ; j++){
	 arrCurrent[i][j] = temparray[i][j];
	 //cout << "arrCurrent is: " << arrCurrent[i][j];
	 }
	 } // for
	 */
}


// Print Function
//***************************************************************************************	
// Purpose: Print a Block
ostream& operator<<(ostream &out, const Tetrimino &t){
	for	(int i = 0; i < t.currH ; ++i){
		for (int j = 0; j < t.currW; ++j){
			if (t.arrDefault[i][j] == t.type) {
				out << t.arrDefault[i][j];
			}
			else {
				out << ' ';
			}
			
		}
		out << endl;
	}
	
	return out;
}
