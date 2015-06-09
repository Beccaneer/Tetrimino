#include "CommandInterpreter.h"
#include "main.h"

using namespace std;

// CommandInterpretor
// Purpose: To take input from the user and determine if it is a valid command.
// If the input is a valid command then the programs associated with the command
// are run. If a multiplier, n, prefixes the command, then that command is run n
// times. If drop is called the next block will be set to drop.
// Output: void
void commandInterpreter(GameGrid &grid, Tetrimino *current, Tetrimino *next, std::ifstream& filestr){
	CommandTree *node = new CommandTree;// Create empty CommandTree
	
	int multiplier = 1; // Holds any multiplier prefix
	string command = ""; // Holds the given command
	
	createCommandTree(*node);// Place all of the commands into a CommandTree
	
	string input; // Input from user
	
	// Loop through commands until input is exhausted
	while (cin >> input) {
		
		// Get Multiplier if supplied
		if (isdigit(input[0])) {
			multiplier = 0;
			while (isdigit(input[0])) {
				multiplier = (multiplier * 10) + (input[0] - 48);
				input = input.substr(1, (input.length() - 1));
			}
		}
		
		// Determine if input is a valid command
		searchCommand(*node, input, command);
		
		// Directions: left, right, down, drop
		if (command == "left") {
			while (multiplier != 0) {
				grid.moveLeft(*current);
				--multiplier;
			}
			textDisplay(grid, *next);
		}
		else if (command == "right") {
			while (multiplier != 0) {
				grid.moveRight(*current);
				--multiplier;
			}
			textDisplay(grid, *next);
		}
		else if (command == "down") {
			while (multiplier != 0) {
				grid.moveDown(*current);
				grid.setFallen(false);
				--multiplier;
			}
			textDisplay(grid, *next);
		}
		else if (command == "drop") {
			while (multiplier != 0) {
				// Set up for the next Tetrimino to be dropped
				grid.drop(*current);
				grid.fullRows(); // check for full rows
				if (grid.getScore() >= grid.getHighScore()){
					grid.setHighScore(grid.getScore());
				}
				delete current;
				current = next;
				if (grid.isGameOver(*current)) { // check if game is over
					textDisplay(grid, *next);
					cout << "Game Over" << endl;
					return;
				}
				grid.setGrid(current);
				Tetrimino *newb = NextBlock(grid.getLevel(), filestr, grid.getSeed());
				next = newb;
				grid.setX(0);
				grid.setY(0);
				--multiplier;
			}
			textDisplay(grid, *next);
			if (grid.getGraphics()){
				graphicDisplay(grid, *next);
			}
		}
		
		
		// Rotations: clockwise, counterclockwise
		else if (command == "clockwise") {
			while (multiplier != 0) {
				grid.rotate(*current, "cw");
				--multiplier;
			}
			textDisplay(grid, *next);
		}
		else if (command == "counterclockwise") {
			while (multiplier != 0) {
				grid.rotate(*current, "ccw");
				--multiplier;
			}
			textDisplay(grid, *next);
		}
		
		
		// Levels: levelup, leveldown
		else if (command == "levelup") {
			while (multiplier != 0) {
				if (grid.getLevel() < 3) {
					grid.setLevel(1);
				}
				--multiplier;
			}
			textDisplay(grid, *next);
			if (grid.getGraphics()){
				graphicDisplay(grid, *next);
			}
		}
		else if (command == "leveldown") {
			while (multiplier != 0) {
				if (grid.getLevel() > 0) {
					grid.setLevel(-1);
				}
				--multiplier;
			}
			textDisplay(grid, *next);
			if (grid.getGraphics()){
				graphicDisplay(grid, *next);
			}
			
		}
		
		// Other: restart
		else if (command == "restart") {
			grid.setGameOver(true);
			return;
		}
		else {
			// Message given to used if input is invalid
			cout << "Command is ambiguous" << endl;
		}
		
		
		command = "";
		multiplier = 1;
		
	}
	return;
}
