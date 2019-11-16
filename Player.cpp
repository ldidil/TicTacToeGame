#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;


char Player::getSymbol() {
	return symbol;
}

string Player::getName() {
	return name;
}

int Player::getPoints() {
	return points;
}

void Player::setPoint(int i) {
	points = i;
}


Player::Player(int number) {
	points = 0;
	string n;
	char ch;

	cout << "PLAYER " << number << endl << " Set your nickname: ";
	cin >> n;
	this->name = n;

	cout << endl << "Set your symbol: ";
	try {
		cin >> ch;
	}
	catch (exception & e)
	{
		cout << "ERROR" << endl;
		throw;
	}
	this->symbol = ch;
	system("cls");
}

Player::Player() {
	name = "name";
	symbol = 'X';
}

Player::~Player() {
}