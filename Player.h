#pragma once
using namespace std;
#include <string>

class Player
{
private:
	char symbol;
	string name;
	int points;
public:
	char getSymbol();
	string getName();
	int getPoints();
	void setPoint(int i);

	Player(int number);
	Player();
	~Player();
};