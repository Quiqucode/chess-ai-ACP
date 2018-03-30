#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "ai.h"
#include "piece.h"

class Board {
	private:
		Piece board[8][8];
		Player white;
		Player black;
	public:
		Board(); //Default constructor, white is human and black is AI
		Board(Player white, Player black); //Initialize the Board with two players that are specified to be either AI or human
		bool movePiece(int x1, int y1, int x2, int y2); //Moves a piece from (x1, y1) to (x2, y2); returns true and moves the piece if the move is legal and false otherwise; also handles capturing pieces; this is likely where a bulk of the initial code that runs the game will be
		bool whiteCheckmate(); //Checks whether or not white is in checkmate; will be checked after each move
		bool blackCheckmate(); //Checks whether or not black is in checkmate; will be checked after each move
		void printBoard(); //Prints out the current state of the board
};

#endif /* BOARD_H */