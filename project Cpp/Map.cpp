#include "Map.h"
#include <fstream>
#include <string>
#include <Windows.h>

void Map::load()
{
	std::string line;
	std::fstream file;

	file.open("maze.txt");

	if (file.good() == true) {
		std::getline(file, line);
		sscanf_s(line.c_str(), "%d %d", &this->width, &this->height);
		this->maze = new State * [this->height];
		for (int i = 0; i < this->height; i++) {
			this->maze[i] = new State[this->width];
			for (int j = 0; j < this->width + 1; j++) { //bierzemy pod uwagê znak koñca lini!!!
				char c;
				file.get(c);
				if (j < this->width) {
					this->maze[i][j] = c == 'B' ? State::White : (c == 'C' ? State::Black : State::None);
				}
			}
		}
		file.close();
	}
}

int Map::getWidth()
{
	return this->width;
}

int Map::getHeight()
{
	return this->height;
}

State Map::getAt(int i, int j)
{
	return this->maze[i][j];
}

Node** Map::pathFinder()
{
	Node** tab = new Node * [this->height];
	for (int i = 0; i < this->height; i++) {
		tab[i] = new Node[this->width];
		for (int j = 0; j < this->width; j++) {
			tab[i][j].x = j;
			tab[i][j].y = i;
		}
	}
	this->neighbours.push_back(tab[this->height - 1][this->width - 1]);
	check(tab, 0);
	select(tab);
	return tab;
}

void Map::check(Node** node, int dist)
{
	std::vector<Node> temporaryNeighbours;

	for (auto j : this->neighbours) {
		node[j.y][j.x].dist = dist;
		node[j.y][j.x].visited = true;

		if (j.y < this->height-1 && !node[j.y + 1][j.x].visited && this->maze[j.y + 1][j.x] == State::White) {
			temporaryNeighbours.push_back(node[j.y + 1][j.x]);
		}
		if (j.y > 0 && !node[j.y - 1][j.x].visited && this->maze[j.y - 1][j.x] == State::White) {
			temporaryNeighbours.push_back(node[j.y - 1][j.x]);
		}
		if (j.y < this->width - 1 && !node[j.y][j.x + 1].visited && this->maze[j.y][j.x + 1] == State::White) {
			temporaryNeighbours.push_back(node[j.y][j.x + 1]);
		}
		if (j.y > 0 && !node[j.y][j.x - 1].visited && this->maze[j.y][j.x - 1] == State::White) {
			temporaryNeighbours.push_back(node[j.y][j.x - 1]);
		}
	}

	this->neighbours = temporaryNeighbours;

	if (!this->neighbours.empty()) {
		check(node, dist + 1);
	}
}

void Map::select(Node** tab)
{
	int x = 0, y = 0;

	while (x != this->width - 1 || y != this->height - 1) {
		int dist = tab[y][x].dist;
		tab[y][x].isPainted = true;
		if (y < this->height - 1 && tab[y + 1][x].visited && tab[y + 1][x].dist < dist) {
			y++;
			continue;
		}
		if (y > 0 && tab[y - 1][x].visited && tab[y - 1][x].dist < dist) {
			y--;
			continue;
		}
		if (x < this->width - 1 && tab[y][x + 1].visited && tab[y][x + 1].dist < dist) {
			x++;
			continue;
		}
		if (x > 0 - 1 && tab[y][x - 1].visited && tab[y][x - 1].dist < dist) {
			x--;
			continue;
		}
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"This maze cannot be passed.\nDo you want to try another?",
			(LPCWSTR)L"Warning!!!",
			MB_OK
		);
		break;
	}
	tab[y][x].isPainted = true;
}

