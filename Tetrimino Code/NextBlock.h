#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include "TetriminoClass.h"

Tetrimino* Fetch_Tetrimino(std::string s);
Tetrimino* Next_zero(std::ifstream& filestr, int a);
Tetrimino* Next_one(int);
Tetrimino* Next_two(int);
Tetrimino* Next_three(int);
Tetrimino* NextBlock(int level, std::ifstream& sream, int s);