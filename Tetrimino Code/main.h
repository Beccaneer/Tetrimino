//***************************A5 - Quadris*****************************
//
// Main File Header
//
//********************************************************************

#include <iostream>
#include <stdlib.h>
#include "GridClass.h"
#include "TetriminoClass.h"
#include "NextBlock.h"

void commandInterpreter(GameGrid &, Tetrimino *, Tetrimino *, std::ifstream& sream);
void textDisplay(GameGrid &, const Tetrimino &);
void graphicDisplay(GameGrid &, Tetrimino &);

