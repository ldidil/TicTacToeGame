#pragma once
class Board
{
private:
	char** field;
	int size;
public:
	void clean();
	bool isWinning(char ch);
	void display();
	char getField(int x, int y);
	void setField(int x, int y, char a);
	int getSize();
	Board(int size);
	Board();
	~Board();
};

