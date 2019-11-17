#include "Board.h"
#include <iostream>
using namespace std;

void Board::clean(){
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				field[i][j] = ' ';
			}
	}
}

bool Board::isWinning(char ch)
{
	int sumchorizontal = 0;
	int sumcvertical = 0;
	int sumdiagonal1 = 0;
	int sumdiagonal2 = 0;
	//chorizontal check
	for (int i = 0; i < size; i++) {
		//diagonal 1
		if (field[i][i] == ch) {
			sumdiagonal1++;
		}

		//diagonal 2
		if (field[size-1 - i][i] == ch) {
			sumdiagonal2++;
		}
		for (int j = 0; j < size; j++) {

			//chorizontal
			if (field[i][j] == ch) {
				sumchorizontal++;
			}
			//vertical
			if (field[j][i] == ch) {
				sumcvertical++;
			}

			//check
			if (sumchorizontal == size || sumcvertical == size || sumdiagonal1 == size || sumdiagonal2 == size) {
				return true;
			}

		}
		sumchorizontal = 0;
		sumcvertical = 0;
	}
	
	return false;
}

void Board::display(){
	cout << "  | ";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " | ";
	}
	for (int i = 0; i < size; i++) {
		cout << endl << i + 1;
		for (int j = 0; j < size; j++) {
			cout << " | " << field[i][j];
		}
		cout << " | ";
	}

	cout << endl;
}

char Board::getField(int x,int y){
	return field[x][y];
}

void Board::setField(int x,int y,char a){
	field[x][y] = a;
}

int Board::getSize()
{
	return size;
}

Board::Board()
{
}

Board::Board(int size){
	this->size = size;

	field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	
	clean();
}

Board::~Board(){
}
