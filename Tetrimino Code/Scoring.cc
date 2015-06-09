//***************************A5 - Quadris*****************************
//
// Scoring
//
//********************************************************************
#include <iostream>

using namespace std;

// Calculate score for a cleared row.
int scoreRows(int total, int level){
	return ((total + level) * (total + level));
}

// Calculate score for a cleared block.
int scoring(int level){
    return ((level + 1)*(level + 1));
}          
