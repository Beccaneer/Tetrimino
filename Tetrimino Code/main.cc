//***************************A5 - Quadris*****************************
//
// Main File
//
//********************************************************************

// Project: Quadris
// Purpose: Runs a game called Quadris which acts in a similar way to Tetris
// The key difference between Quadris and Tetris is that it is not in real time.
// The major compoenents of this program are: blocks, grid, command interpreter,
// display, scoring and a command-line interface.

#include "main.h"
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
	bool g = true; // set graphics flag
	int s = -1; // seed
	
	GameGrid gameGrid;
	
	// Command-line Interface
	// Purpose: To take in commands from the command line
	// and adjust the game accordingly.
	// -text runs the game using only text
	// -seed seeds the random number generator with the provided seed
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i],"-text") == 0) {
			g = false;
			gameGrid.setGraphics(g);
		}
		if (strcmp(argv[i], "-seed") == 0) {
			string a = argv[i + 1];
			s = atoi(a.c_str());
			gameGrid.setSeed(s);
		}
	}
	
	ifstream filestr("sequence.txt"); // File used for level 0
	
	// The main loop of the game. The game will continue until there
	// is no longer any input from the user
	do {
		// Initialize Game Grid
		int hs = gameGrid.getHighScore();
		gameGrid = GameGrid();
		gameGrid.setHighScore(hs);
		
		// Initialize the current and next tetrimino
		Tetrimino *current = NextBlock(gameGrid.getLevel(), filestr, s);
		Tetrimino *next = NextBlock(gameGrid.getLevel(), filestr, 1);
		
		// Place the tetrimino into the grid
		if (g){
			graphicDisplay(gameGrid, *next);
		}
		gameGrid.setGrid(current);
		
		// Display the Game Grid
		textDisplay(gameGrid, *next);
		
		gameGrid.setGameOver(false);
		
		// Call the command interpreter to begin the game play
		commandInterpreter(gameGrid, current, next, filestr);
		
	} while(gameGrid.getGameOver()); // check if game is over and to restart
	
	return 0;
}


