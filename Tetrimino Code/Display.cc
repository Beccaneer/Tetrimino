#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "window.h"
#include "main.h"

using namespace std;

// Text Display
// Purpose: Print a text version of the game.
void textDisplay(GameGrid &gameGrid, const Tetrimino &next){
	cout << "Level:" << right << setw(10) << gameGrid.getLevel() << endl;
	cout << "Score:" << right << setw(10) << gameGrid.getScore() << endl;
	cout << "Hi Score:" << right << setw(7) << gameGrid.getHighScore() << endl;
	cout << "----------" << endl;
	
	cout << gameGrid;
	
	cout << "----------" << endl;
	cout << "Next:" << endl;
	
	cout << next;
}

// converts an int into a string
string stringer(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

// Graphic Display
// Purpose: Print a graphical represetation of the game
void graphicDisplay(GameGrid &gameGrid, Tetrimino &next){
	gameGrid.w->drawString(10, 20, "Level:");
	gameGrid.w->fillRectangle(100, 10, 100, 15, 0);
	gameGrid.w->drawString(100, 20, stringer(gameGrid.getLevel()));
	
	gameGrid.w->drawString(10, 35, "Score:");
	gameGrid.w->fillRectangle(100, 25, 100, 15, 0);
	gameGrid.w->drawString(100, 35, stringer(gameGrid.getScore()));
	
	gameGrid.w->drawString(10, 50, "Hi Score:");
	gameGrid.w->fillRectangle(100, 40, 100, 15, 0);
	gameGrid.w->drawString(100, 50, stringer(gameGrid.getHighScore()));
	
	gameGrid.w->drawString(10, 65, "-------------------------");	
	
	gameGrid.w->drawString(10, 350, "-------------------------");
	
	gameGrid.w2->fillRectangle(0,0,50,50,0);
	for (int i = 0; i < next.getcurrH(); ++i){
		for (int j = 0; j < next.getcurrW(); ++j){
		    if (next.getarrDefault()[i][j] == next.gettype()){
				gameGrid.w2->fillRectangle(15 * j, i * 15, 15, 15, 9);
		    }
		}
	}
}