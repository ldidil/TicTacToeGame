#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Game::start() {
	int i = 1;
	while (true) {
		board.display();
		turn(i);
		system("cls");
		if (isWinning(i) || i == 9) {
			board.display();
			endOfGame(i);
			i = 0;
		}
		i++;
	}
}


void Game::turn(int i)
{
	if (i % 2 == 1) {
		cout << "Turn " << player1.getName() << endl;;
		shot(player1);
	}

	else if (i % 2 == 0) {
		cout << "Turn " << player2.getName() << endl;
		shot(player2);
	}

}

void Game::shot(Player p)
{
	int x, y;
	do {
		cout << "Coordinate X: ";
		cin >> x;
		x--;
		cout << endl << "Coordinate Y: ";
		cin >> y;
		y--;
		if (isAllowed(x, y) == false) {
			cout << "Wrong Coordinates, try again" << endl;
		}
	} while (isAllowed(x, y) != true);

	addNew(x, y, p.getSymbol());

}

bool Game::isWinning(int i) {
	bool x;
	if (i % 2 == 1) {
		x=board.isWinning(player1.getSymbol());
	}
	else if (i % 2 == 0) {
		x=board.isWinning(player2.getSymbol());
	}
	return x;
}
	


void Game::addNew(int x, int y, char ch) {
	board.setField(x,y,ch);
}

bool Game::isAllowed(int x, int y) {
	if (x < board.getSize() && y < board.getSize()) {
		if (board.getField(x,y) == ' ') {
			return true;
		}
	}
	return false;
}

void Game::addPoint(int i) {
	if (i % 2 == 1) {
		player1.setPoint(player1.getPoints() + 1);
	}

	else if (i % 2 == 0) {
		player2.setPoint(player2.getPoints() + 1);
	}
}

void Game::endOfGame(int i) {
	cout << "END OF GAME" << endl;
	cout << "   POINTS" << endl;
	cout << player1.getName() << " " << player1.getPoints() << "\t" << player2.getName() << " " << player2.getPoints() << endl;
	cout << "PLAY AGAIN?" << endl << "1.YES\t2.NO" << endl;;
	int j; cin >> j;
	if (isWinning(i)) {
		addPoint(i);
	}

	if (j == 2) {
		exit(0);
	}
	board.clean();
	system("cls");
}

Game::Game() {
	this->player1 = Player(1);
	this->player2 = Player(2);

	cout << "Size of board: ";
	int s;
	cin >> s;
	this->board = Board(s);
}

Game::~Game() {
}