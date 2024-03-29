#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"

class Game
{
private:
	Board board;
	Player player1;
	Player player2;
public:
	void start();
	void turn(int i);
	void shot(Player p);
	bool isWinning(int i);
	void addNew(int x, int y, char ch);
	bool isAllowed(int x, int y);
	void addPoint(int i);
	void endOfGame(int i);
	Game();
	~Game();
};