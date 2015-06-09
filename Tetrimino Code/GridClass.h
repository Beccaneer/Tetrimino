#ifndef __GAMEGRID_H__
#define __GAMEGRID_H__
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "window.h"
#include "TetriminoClass.h"

// Dimensions of the Game Grid
const int ROWS = 18; // 3 extra rows are given for rotation
const int COLUMNS = 10;

// Game Grid Class which represents the board
class GameGrid {
	// The board
	std::pair <std::string, std::pair <int, int> > theGrid[ROWS][COLUMNS];
	
	bool fallen; // Check if a block has fallen
	bool gameOver; // Check if the game is over
	
	// Level and scores
	int level;
	int score;
	int highScore;

	// Command-Line
	bool graphics;
	int seed;
	
	int x,y;
	int idnum;
	
public:	
	// Graphics
	Xwindow *w;
	Xwindow	*w2;
	int width;
	int height;
	
	GameGrid(); // Constructor
	~GameGrid(){}; // Default Destructor
	
	// Game Over
	bool isGameOver(Tetrimino &);
	void setGameOver(bool status){gameOver = status;};
	bool getGameOver(){return gameOver;};
	
	// Collision
	bool wallCollision(int);
	bool blockCollision(int, int);
	
	// Rotation 
	void rotate(Tetrimino&, std::string);
	
	// Movement
	void moveRight(Tetrimino&);
	void moveLeft(Tetrimino&);
	void moveDown(Tetrimino&);
	void drop(Tetrimino&);
	void setFallen(bool b){fallen = b;};
	
	// Row Clearing
	void fullRows();
	void clearRows(int row);
	
	// Level
	void setLevel(int l){level += l;};
	int getLevel(){return level;};
	
	// Scoring
	void setScore(int s){score = s;};
	int getScore(){return score;};
	void setHighScore(int hs){highScore = hs;};
	int getHighScore(){return highScore;};
	void Scoring_Search(int, int);
	
	// Set Grid
	void setGrid(Tetrimino *current){
		for (int i = 0; i < 4; ++i) {
			theGrid[current->getcoGridArray(i).first][current->getcoGridArray(i).second].first = current->gettype();
			if (graphics) {
				drawCell(current->getcoGridArray(i).first, current->getcoGridArray(i).second,current->gettype());
			}
		}
	}
	
	void setGraphics(bool a){graphics = a;};
	void setSeed(int a){seed = a;};
	int getSeed(){return seed;};
	bool getGraphics(){return graphics;};
	void setX(int n){x=n;};
	void setY(int n){y=n;};
	
	// Print Function
	friend std::ostream& operator<<(std::ostream &out, const GameGrid &g);
	
	// Graphics
	void drawCell(int,int,std::string);
	void deleteCell(int,int);
};

#endif
