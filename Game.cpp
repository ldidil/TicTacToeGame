#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Game::start() {
	int i = 1;
	while (true) {
		display();
		turn(i);
		system("cls");
		if (isWinning(i) || i == 9) {
			display();
			endOfGame(i);
			i = 0;
		}
		i++;
	}
}

void Game::clean() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void Game::display() {
	cout << "    POINTS" << endl;
	cout << player1.getName() << " " << player1.getPoints() << "    " << player2.getName() << " " << player2.getPoints() << endl;
	cout << "   1    2    3";
	for (int i = 0; i < 3; i++) {
		cout << endl << "   -----------" << endl << i + 1;
		for (int j = 0; j < 3; j++) {
			cout << " | " << board[i][j];
		}
		cout << " | ";
	}
	cout << endl << "   -----------" << endl;

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
	char ch = 0; {
		if (i % 2 == 1) {
			ch = player1.getSymbol();
		}

		else if (i % 2 == 0) {
			ch = player2.getSymbol();
		}

	}
	int sumchorizontal = 0;
	int sumcvertical = 0;
	int sumdiagonal1 = 0;
	int sumdiagonal2 = 0;
	//chorizontal check
	for (int i = 0; i < 3; i++) {
		//diagonal 1
		if (board[i][i] == ch) {
			sumdiagonal1++;
		}

		//diagonal 2
		if (board[2 - i][i] == ch) {
			sumdiagonal2++;
		}
		for (int j = 0; j < 3; j++) {

			//chorizontal
			if (board[i][j] == ch) {
				sumchorizontal++;
			}
			//vertical
			if (board[j][i] == ch) {
				sumcvertical++;
			}

			//check
			if (sumchorizontal == 3 || sumcvertical == 3 || sumdiagonal1 == 3 || sumdiagonal2 == 3) {
				return true;
			}

		}
		sumchorizontal = 0;
		sumcvertical = 0;
	}

	return false;
}

void Game::addNew(int x, int y, char ch) {
	board[x][y] = ch;
}

bool Game::isAllowed(int x, int y) {
	if (x < 3 && y < 3) {
		if (board[x][y] == ' ') {
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
	cout << "PLAY AGAIN?" << endl << "1.YES\t2.NO" << endl;;
	int j; cin >> j;
	if (isWinning(i)) {
		addPoint(i);
	}

	if (j == 2) {
		exit(0);
	}
	clean();
	system("cls");
}

Game::Game() {
	//making players
	this->player1 = Player(1);
	this->player2 = Player(2);

	//making board
	clean();


}

Game::~Game() {
}