//***************************A5 - Quadris*****************************
//
// Command Interpretor Helper Functions
//
//********************************************************************

#include "CommandInterpreter.h"

using namespace std;

// Initialization Functions
//***************************************************************************************

// Insert: CommandTree &, const string &, const string &
// Purpose: To insert a command into the CommandTree letter by letter
// Output: Void
void insert( CommandTree &node, const string &word, const string &command){
	// If the word is empty then set the current node as a command and assign the command
	if (word.empty()){ 
		node.isCommand = true;
		node.foundCommand = command;
		return;
	}
	else {
		int letter = word[0] - 'a';
		
		// Check if the letter in the word does not exist, if so create new node
		if (node.letters[letter] == NULL) {
			node.letters[letter] = new CommandTree;
		}
		
		insert(*node.letters[letter], word.substr(1, (word.length() - 1)), command);
	}
	
	return;
}

// CreateCommand: CommandTree &
// Purpose: To initialize the Command Tree with all of the commands used for the game
// Output: Void
void createCommandTree(CommandTree &node){
	insert(node, "left", "left");
	insert(node, "right", "right");
	insert(node, "down", "down");
	insert(node, "drop", "drop");
	insert(node, "clockwise", "clockwise");
	insert(node, "counterclockwise", "counterclockwise");
	insert(node, "levelup", "levelup");
	insert(node, "leveldown", "leveldown");
	insert(node, "restart", "restart");
}


// Search Functions
//***************************************************************************************

// SearchCommand: const CommandTree &, const string &, string &
// Purpose: To go through the Command Tree letter by letter with the given input.
// once the input is exhausted the function will pass to SearchRest which will
// search for the rest of the command if possible.
// Output: Void
void searchCommand( const CommandTree &node, const string &input, string &command){
	// If input is exhauseted call on SearchRest
	if (input.empty()){
		searchRest(node, command);
		return;
	}
	else {
		char letter = input[0] - 'a';
		
		// If the letter is not found then there is no command corresponding to input
		if(node.letters[letter] == NULL){
			return;
		}
		
		searchCommand(*node.letters[letter], input.substr(1, (input.length() - 1)), command);
	}
	return;
}

// SearchRest: const CommandTree &, string &
// Purpose: To go through the Command Tree and search for a possible command once the
// original input is exhausted. If a command is found, the command variable in the 
// commandInterpreter function is set to that command. If there is a possibility of 
// more than one command then the command variable is not set.
// Output: Void
void searchRest( const CommandTree &node, string &command){
	// If a command is found set the command variable with the command at that node.
	if (node.isCommand == true) {
		command = node.foundCommand;
		return;
	}
	else {
		int count = 0;
		int letter = 0;
		for (int i = 0; i < 26; ++i) {
			if (node.letters[i] != NULL) {
				letter = i;
				count += 1;
			}
		}
		if (count <= 1) {
			searchRest(*node.letters[letter], command);
		}
		
		return;
	}
	return;
}
