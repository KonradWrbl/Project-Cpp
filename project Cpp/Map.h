#pragma once
#include "State.h"
#include "Node.h"
#include <vector>

////////////////////////////////////////////////////////////
//	Class describing whole map of the maze
////////////////////////////////////////////////////////////
class Map
{
public: 
	////////////////////////////////////////////////////////////
	//	Method loads map from file to maze table
	////////////////////////////////////////////////////////////
	void load();

	////////////////////////////////////////////////////////////
	//	Getter
	////////////////////////////////////////////////////////////
	int getWidth();

	////////////////////////////////////////////////////////////
	//	Getter
	////////////////////////////////////////////////////////////
	int getHeight();

	////////////////////////////////////////////////////////////
	//	Method returns position on the maze table
	////////////////////////////////////////////////////////////
	State getAt(int i, int j);

	////////////////////////////////////////////////////////////
	//	Method returns table of describing cells and founded path
	////////////////////////////////////////////////////////////
	Node** pathFinder();

private:

	////////////////////////////////////////////////////////////
	//	Method checks dist of nodes from the end of maze
	////////////////////////////////////////////////////////////
	void check(Node**, int);

	////////////////////////////////////////////////////////////
	//	Method selects the path
	////////////////////////////////////////////////////////////
	void select(Node**);

private:
	int height;
	int width;
	State** maze;
	std::vector<Node> neighbours;
};

