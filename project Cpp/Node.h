#pragma once

////////////////////////////////////////////////////////////
//	Class(Structure) describing current position on the map
////////////////////////////////////////////////////////////
class Node
{
public:
	int x = 0;
	int y = 0;
	int dist = 0;
	bool visited = false;
	bool isPainted = false;
};

