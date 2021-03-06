#include <iostream>
#include "piece.h"

using namespace std;

Piece::Piece() {
	weight = 0;
	ident = '*';
	lm = 1;
	hasSp = false;
}

Pawn::Pawn() {
	weight = 10;
	ident = 'P';
	isInit = true;
	type = 0;
	moveArr = new std::pair<int, int>[1];
	moveArr[0].first = 0;
	moveArr[0].second = -1;
	spMoveArr = new std::pair<int, int>[3];
	spMoveArr[0].first = -1;
	spMoveArr[0].second = -1;
	spMoveArr[1].first = 1;
	spMoveArr[1].second = -1;
	spMoveArr[2].first = 0;
	spMoveArr[2].second = -2;
	lm = 1;
	sp = 3;
	hasSp = true;
}

Pawn::Pawn(bool side) {
	weight = 10;
	ident = 'P';
	isInit = true;
	type = side;
	int temp;
	if(type) temp = -1;
	else temp = 1;
	moveArr = new std::pair<int, int>[1];
	moveArr[0].first = 0;
	moveArr[0].second = temp;
	spMoveArr = new std::pair<int, int>[3];
	spMoveArr[0].first = -1;
	spMoveArr[0].second = temp;
	spMoveArr[1].first = 1;
	spMoveArr[1].second = temp;
	spMoveArr[2].first = 0;
	spMoveArr[2].second = temp*2;
	lm = 1;
	sp = 3;
	hasSp = true;
}

Rook::Rook() {
	weight = 50;
	ident = 'R';
	isInit = true;
	type = 0;
	int z = 0;
	moveArr = new std::pair<int, int>[28];
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = 0;
		moveArr[z].second = x < 0 ? -1*(8 + x):x;
		moveArr[27-z].first = x < 0 ? x:(8-x);
		moveArr[27-z].second = 0;
		z++;
	}
	lm = 28;
	hasSp = false;
}

Rook::Rook(bool side) {
	weight = 50;
	ident = 'R';
	isInit = true;
	type = side;
	int z = 0;
	moveArr = new std::pair<int, int>[28];
	for(int x = -7; x < 8; x++) {
			if(x == 0) x++;
			moveArr[z].first = 0;
			moveArr[z].second = x < 0 ? -1*(8 + x):x;
			moveArr[27-z].first = x < 0 ? x:(8-x);
			moveArr[27-z].second = 0;
			z++;
		}
	lm = 28;
	hasSp = false;
}

Knight::Knight() {
	weight = 32;
	ident = 'N';
	isInit = true;
	type = 0;
	int z = 0;
	moveArr = new std::pair<int, int>[8];
	for(int y = -1; y < 2; y+=2) {
		for(int x = -1; x < 2; x+=2) {
			moveArr[z].first = 2 * x;
			moveArr[z].second = y;
			z++;
		}
	}
	for(int y = -1; y < 2; y+=2) {
		for(int x = -1; x < 2; x+=2) {
			moveArr[z].first = y;
			moveArr[z].second = 2 * x;
			z++;
		}
	}
	lm = 8;
	hasSp = false;
}

Knight::Knight(bool side) {
	weight = 32;
	ident = 'N';
	isInit = true;
	type = side;
	int z = 0;
	moveArr = new std::pair<int, int>[8];
	for(int y = -1; y < 2; y+=2) {
		for(int x = -1; x < 2; x+=2) {
			moveArr[z].first = 2 * x;
			moveArr[z].second = y;
			z++;
		}
	}
	for(int y = -1; y < 2; y+=2) {
		for(int x = -1; x < 2; x+=2) {
			moveArr[z].first = y;
			moveArr[z].second = 2 * x;
			z++;
		}
	}
	lm = 8;
	hasSp = false;
}

Bishop::Bishop() {
	weight = 33;
	ident = 'B';
	isInit = true;
	type = 0;
	int z = 0;
	moveArr = new std::pair<int, int>[28];
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8+x):x;
		moveArr[z].second = x < 0 ? -1*(8+x):x;
		moveArr[27-z].first = x < 0 ? x:(8-x);
		moveArr[27-z].second = x < 0 ? -x:-1*(8-x);
		z++;
	}
	lm = 28;
	hasSp = false;
}

Bishop::Bishop(bool side) {
	weight = 33;
	ident = 'B';
	isInit = true;
	type = side;
	int z = 0;
	moveArr = new std::pair<int, int>[28];
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8+x):x;
		moveArr[z].second = x < 0 ? -1*(8+x):x;
		moveArr[27-z].first = x < 0 ? x:(8-x);
		moveArr[27-z].second = x < 0 ? -x:-1*(8-x);
		z++;
	}
	lm = 28;
	hasSp = false;
}


King::King() {
	weight = 2000;
	ident = 'K';
	isInit = true;
	type = 0;
	int z = 0;
	moveArr = new std::pair<int, int>[8];
	for(int x = -1; x < 2; x++) {
		for(int y = -1; y < 2; y++) {
			if(x == y && y == 0) y++;
			moveArr[z].first = x;
			moveArr[z].second = y;
			z++;
		}
	}
	lm = 8;
	hasSp = false;
}

King::King(bool side) {
	weight = 2000;
	ident = 'K';
	isInit = true;
	type = side;
	int z = 0;
	moveArr = new std::pair<int, int>[8];
	for(int x = -1; x < 2; x++) {
		for(int y = -1; y < 2; y++) {
			if(x == y && y == 0) y++;
			moveArr[z].first = x;
			moveArr[z].second = y;
			z++;
		}
	}
	lm = 8;
	hasSp = false;
}

Queen::Queen() {
	weight = 99;
	ident = 'Q';
	isInit = true;
	type = 0;
	int z = 0;
	moveArr = new std::pair<int, int>[56];
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8+x):x;
		moveArr[z].second = x < 0 ? -1*(8+x):x;
		moveArr[27-z].first = x < 0 ? x:(8-x);
		moveArr[27-z].second = x < 0 ? -x:-1*(8-x);
		z++;
	}
	z = 28;
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = 0;
		moveArr[z].second = x < 0 ? -1*(8 + x):x;
		z++;
	}
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8 + x):x;
		moveArr[z].second = 0;
		z++;
	}
	lm = 56;
	hasSp = false;
}

Queen::Queen(bool side) {
	weight = 99;
	ident = 'Q';
	isInit = true;
	type = side;
	int z = 0;
	moveArr = new std::pair<int, int>[56];
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8+x):x;
		moveArr[z].second = x < 0 ? -1*(8+x):x;
		moveArr[27-z].first = x < 0 ? x:(8-x);
		moveArr[27-z].second = x < 0 ? -x:-1*(8-x);
		z++;
	}
	z = 28;
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = 0;
		moveArr[z].second = x < 0 ? -1*(8 + x):x;
		z++;
	}
	for(int x = -7; x < 8; x++) {
		if(x == 0) x++;
		moveArr[z].first = x < 0 ? -1*(8 + x):x;
		moveArr[z].second = 0;
		z++;
	}
	lm = 56;
	hasSp = false;
}

