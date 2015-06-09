//***************************A5 - Quadris*****************************
//
// Grid Member Functions
//
//********************************************************************

#include "GridClass.h"
#include "Scoring.h"

using namespace std;

// Constructor
//***************************************************************************************
// Purpose: To construct a default grid.

GameGrid::GameGrid(){
	for	(int i = 0; i < ROWS; ++i){
		for (int j = 0; j < COLUMNS; ++j){
			theGrid[i][j].first = ' ';
			theGrid[i][j].second.second = 0;
		}
	}
	
	fallen = false;
	gameOver = false;
	
	level = 1;
	score = 0;
	highScore = 0;
	
	idnum = 1;
	
	x = 0, y = 0;
	
	graphics = true;
	seed = -1;
	
	w = new Xwindow();
	w2 = new Xwindow(50,50);
	width = 500;
	height = 500;
	
}

// Game Over Check
//***************************************************************************************
// Purpose: To check if the game has been lost by having the next block collide with another in
// the top left corner of the grid.
bool GameGrid::isGameOver(Tetrimino &current){
	for (int i = 0; i < 4; ++i) {
		if (blockCollision(current.getcoGridArray(i).first, current.getcoGridArray(i).second)) {
			gameOver = true;
			return true;
		}
	}
	return false;
}

// Collisions
//***************************************************************************************

// Purpose: Check if the block collides with a wall
bool GameGrid::wallCollision(int x){
	if (x < 0 || x > 9) {
		return true;
	}
	
	return false;
}

// Purpose: Check if a block collides with another block
bool GameGrid::blockCollision(int y, int x){
	if (theGrid[y][x].first != " ") {
		return true;
	}
	
	return false;
}

// Rotation
//***************************************************************************************
// Purpose: To rotate the block on the grid
void GameGrid::rotate(Tetrimino &current, string dir){
	if (current.gettype() == "O") {
		return;
	}
	vector < pair <int, int> > temp(4);
	
	for (int i = 0; i < 4; ++i) {
		temp[i].first = current.getcoGridArray(i).first;
		temp[i].second = current.getcoGridArray(i).second;
	}
	current.rotate(dir);
	
	// check collision
	for (int i = 0; i < 4; ++i) {
		if ((wallCollision((current.getcoGridArray(i).second + x))) ||
			((find(temp.begin(), temp.end(), make_pair((current.getcoGridArray(i).first + y), (current.getcoGridArray(i).second + x)))) == temp.end())
			&& blockCollision((current.getcoGridArray(i).first + y), (current.getcoGridArray(i).second + x))) {
			for (int i = 0; i < 3; ++i) {
				current.rotate(dir);
			}
			for (int i = 0; i < 4; ++i) {
				current.getcoGridArray(i).first += y;
				current.getcoGridArray(i).second += x;
			}
			return;
		}
	}
	
	// clear previous block
	for (int i = 0; i < 4; ++i) {
		theGrid[temp[i].first][temp[i].second].first = " ";
		if (graphics) {
			deleteCell(temp[i].first, temp[i].second);
		}
	}
	
	// set the grid
	for (int i = 0; i < 4; ++i) {
		current.getcoGridArray(i).first += y;
		current.getcoGridArray(i).second += x;
		theGrid[current.getcoGridArray(i).first][current.getcoGridArray(i).second].first = current.gettype();
		if (graphics) {
			drawCell(current.getcoGridArray(i).first, current.getcoGridArray(i).second,current.gettype());
		}
	}
	
}

// Movement
//***************************************************************************************

// Right
// Purpose: To move the block to the right.
void GameGrid::moveRight(Tetrimino& block){
	vector < pair <int, int> > temp(4);
	
	// initialize a temp array of co-ordinates
	for (int i = 0; i < 4; ++i) {
		temp[i].first = block.getcoGridArray(i).first;
		temp[i].second = block.getcoGridArray(i).second;
	}
	
	// Check for collision
	for (int i = 0; i < 4; ++i) {
		if (wallCollision((temp[i].second + 1)) ||
			(((find(temp.begin(), temp.end(), make_pair(temp[i].first, (temp[i].second + 1)))) == temp.end())
			 && blockCollision(temp[i].first, (temp[i].second + 1)))) {
				return;
			}
	}
	
	// clear previous block
	for (int i = 0; i < 4; ++i) {
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = " ";
		if (graphics) {
			deleteCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second);
		}
	}
	
	// set the grid
	for (int i = 3; i > -1; --i) {
		block.getcoGridArray(i).second = temp[i].second + 1;
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = block.gettype();
		if (graphics) {
			drawCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second,block.gettype());
		}
	}
	x+=1;
	
}	

// Left
// Purpose: To move the block to the left.
void GameGrid::moveLeft(Tetrimino& block){
	vector < pair <int, int> > temp(4);
	
	// initialize a temp array of co-ordinates
	for (int i = 0; i < 4; ++i) {
		temp[i].first = block.getcoGridArray(i).first;
		temp[i].second = block.getcoGridArray(i).second;
	}
	
	// Check for collision
	for (int i = 3; i > -1; --i) {
		if (wallCollision((temp[i].second - 1)) ||
			(((find(temp.begin(), temp.end(), make_pair(temp[i].first, (temp[i].second - 1)))) == temp.end()) 
			 && blockCollision(temp[i].first, (temp[i].second - 1)))) {
				return;
			}
	}
	
	// clear previous block
	for (int i = 0; i < 4; ++i) {
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = " ";
		if (graphics) {
			deleteCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second);
		}
	}
	
	// set the grid
	for (int i = 0; i < 4; ++i) {
		block.getcoGridArray(i).second = temp[i].second - 1;
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = block.gettype();
		if (graphics) {
			drawCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second,block.gettype());
		}
	}
	x-=1;
}

// Down
// Purpose: to move the block down.
void GameGrid::moveDown(Tetrimino& block){
	vector < pair <int, int> > temp(4);
	
	// initialize a temp array of co-ordinates
	for (int i = 0; i < 4; ++i) {
		temp[i].first = block.getcoGridArray(i).first;
		temp[i].second = block.getcoGridArray(i).second;
	}
	
	// Check for collision
	for (int i = 0; i < 4; ++i) {
		if (((temp[i].first + 1 ) > 17) || ((find(temp.begin(), temp.end(), make_pair((temp[i].first + 1), temp[i].second)) == temp.end()) 
											&& blockCollision((temp[i].first + 1), temp[i].second))) {
			for (int i = 0; i < 4; ++i) {//SCORING ASSIGNMENT
				theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].second = make_pair(level, idnum);
			}
			idnum+=1;
			fallen = true;
			return;
		}
	}
	
	// clear previous block
	for (int i = 0; i < 4; ++i) {
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = " ";
		if (graphics) {
			deleteCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second);
		}
	}
	
	// set the grid
	for (int i = 3; i >= 0; --i) {
		block.getcoGridArray(i).first = temp[i].first + 1;
		theGrid[block.getcoGridArray(i).first][block.getcoGridArray(i).second].first = block.gettype();
		if (graphics) {
			drawCell(block.getcoGridArray(i).first, block.getcoGridArray(i).second,block.gettype());
		}
	}
	y+=1;
}

// Purpose: To drop the block.
void GameGrid::drop(Tetrimino& block){
	while (true) {
		if (fallen) {
			fallen = false;
			return;
		}
		moveDown(block);
	}
}

// Row Clearing
//***************************************************************************************
// Purpose: To check if there are any full rows and complete the associated scoring
void GameGrid::fullRows(){
	int total = 0; // used to calculate score
	
	for (int i = 3; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			if (theGrid[i][j].first == " ") {
				break;
			}
			if (j == (COLUMNS - 1)) {
				clearRows(i);
				total+= 1;
			}
		}
	}
	if (total != 0) {score += scoreRows(total, level);};
}

// Purpose: To clear the full rows and complete any associated scoring
void GameGrid::clearRows(int row){
	if (graphics){
	    for (int i = 0; i < ROWS; ++i){
			for (int j = 0; j < COLUMNS; ++j)
				deleteCell(i,j);
	    }
	}
	for (int i = row; i > 0; --i) {
		for (int j = 0; j < COLUMNS; ++j) {
			pair <int,int> cell = theGrid[i][j].second;
			theGrid[i][j] = theGrid[(i - 1)][j];
			Scoring_Search(cell.first, cell.second);
			if (graphics){
				drawCell(i,j,theGrid[i][j].first);
			}
		}
	}
}


// Purpose: Search if there are any fragments of a deleted block left, if
// not scoring is done.
void GameGrid::Scoring_Search(int level, int idnum){
	bool IsItThere = false;
	for (int i = 0 ; i < 18 ; i++){
		for (int j = 0 ; j < 10 ; j++){
			if (theGrid[i][j].first != " "){
				if (theGrid[i][j].second.second == idnum){
					IsItThere = true;
				}
			}
		} // for int j
	} // for int i
	
	if (IsItThere == false){
        score = scoring(level) + score;
	}
}

// Print Function
//***************************************************************************************	
// Purpose: Print the grid.
ostream& operator<<(ostream &out, const GameGrid &g){
	for	(int i = 0; i < ROWS; ++i){
		for (int j = 0; j < COLUMNS; ++j){
			out << g.theGrid[i][j].first;
		}
		out << endl;
	}
	
	return out;
}

// Graphic Functions
//***************************************************************************************
// Purpose: To draw a graphical represention of a cell on the grid
void GameGrid::drawCell(int y,int x,string type){
	if (type == "I") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 5);
	}
	if (type == "L") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 4);
	}
	if (type == "J") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 8);
	}
	if (type == "O") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 6);
	}
	if (type == "S") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 3);
	}
	if (type == "T") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 7);
	}
	if (type == "Z") {
		w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 2);
	}
}

// Purpose: To clear a moved cell from the graphical grid
void GameGrid::deleteCell(int y,int x){
	w->fillRectangle(15 * x, 70 + (y * 15), 15, 15, 0);
}
