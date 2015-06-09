//***************************A5 - Quadris*****************************
//
// Command Interpretor Header
//
//********************************************************************

#ifndef __COMMANDTREE_H__
#define __COMMANDTREE_H__
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

// A Tree that will hold all of the commands letter by letter in a 
// tree hierarchy (similar to A3Q3 Trie structure)
struct CommandTree {
    enum { NumChars = 26 };
	
    bool isCommand; // Flag to signal that the current node in the tree is a command
	std::string foundCommand; // The command that the current node corresponds to
	CommandTree *letters[NumChars]; // The children of this node
	
	// Initializes a default CommandTree
    CommandTree() {
        isCommand = false;
		for ( int i = 0; i < NumChars; i += 1 ) {
			letters[i] = NULL;
		}
    }
};

void insert( CommandTree &node, const std::string &word, const std::string &command);
void createCommandTree(CommandTree &node);
void searchRest( const CommandTree &node, std::string &command);
void searchCommand( const CommandTree &node, const std::string &input, std::string &command);

#endif