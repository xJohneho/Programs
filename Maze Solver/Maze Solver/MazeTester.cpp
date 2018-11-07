#include "DFSMazeGenerator.h"


int main() {
	MazeGenerator Level[MAZESIZE][MAZESIZE];
	MazeGenerator test = MazeGenerator();
	test.runMazeGen(Level);
	_getch();
	return 0;
}

