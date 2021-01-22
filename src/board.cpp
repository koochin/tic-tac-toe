#include "../header/board.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

Board::Board(bool first) : turn(first) {}

// public

bool Board::is_valid(const std::pair<int, int> coord) {
	if (coord.first > 0 && coord.first < 4 && coord.second > 0 && coord.second < 4) {
		auto square = convert_coord(coord);
		auto mask = create_mask(square);
		// is square available
		return (mask & x) != mask && (mask & o) != mask;
	}
	return false;
}

void Board::make_move(const std::pair<int, int> coord) {
	auto square = convert_coord(coord);
	auto mask = create_mask(square);
	// set bit for square
	if (turn) {
		x |= mask;
	}
	else {
		o |= mask;
	}
	// update board
	update_board(coord);
}

bool Board::get_turn() {
	return turn;
}

void Board::switch_turn() {
	turn ^= 1;
}

bool Board::game_over() {
	auto state = turn ? x : o;
	for (auto win : wins) {
		if ((state & win) == win) {
			game_message = "Player " + std::string(turn ? "X" : "O") + " won!";
			return true;
		}
	}
	// board is full
	// result is a draw
	if ((x | o) == 0b111111111) {
		return true;
	}
	return false;
}

std::string Board::status() {
	return game_message;
}


// private

int Board::create_mask(const int n) {
	return 1 << (n - 1);
}

int Board::convert_coord(const std::pair<int, int> coord) {
	//unsigned int square = convert_coord(coord);
	//return board_map[square];
	return board_map[coord.first - 1][coord.second - 1];
}

void Board::update_board(const std::pair<int, int> coord) {
	int r = coord.first;
	int c = coord.second;
	r *= 2;
	c *= 2;
	/*
	if (r == 2) {
		r++;
	}
	else if (r == 3) {
		r += 2;
	}
	if (c == 2) {
		c++;
	}
	else if (c == 3) {
		c += 2;
	}
	*/
	board[r][c] = turn ? "X" : "O";
}

void Board::draw_board() {
	std::stringstream ss;
	for (auto row : board) {
		for (auto square : row) {
			ss << square;
		}
		ss << "\n";
	}
	std::cout << ss.str() << std::endl;
}