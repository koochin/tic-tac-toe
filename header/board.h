#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

class Board {
	private:
		bool turn = 0;
		//std::vector<int> wins = {448, 56, 7, 73, 146, 273, 84};
		std::vector<int> wins = {0b001001001, 0b010010010, 0b100100100, 
								 0b000000111, 0b000111000, 0b111000000,
								 0b100010001, 0b001010100};
		int x = 0b000000000;
		int o = 0b000000000;
		int create_mask(const int n);
		// std::vector<int> board_map(34, 0);
		// set 11, 12, 13, 21, 22, 23, 31, 32, 33 to bit values of squares
		/*
		std::map<std::pair<int, int>, unsigned int> board_map = {{{1, 1}, 1U}, 
																 {{1, 2}, 2U}, 
																 {{1, 3}, 3U}, 
																 {{2, 1}, 4U}, 
																 {{2, 2}, 5U}, 
																 {{2, 3}, 6U}, 
																 {{3, 1}, 7U}, 
																 {{3, 2}, 8U}, 
																 {{3, 3}, 9U}};
		*/
		std::vector<std::vector<int>> board_map = {{1, 4, 7}, 
												   {2, 5, 8}, 
												   {3, 6, 9}};
	    int convert_coord(const std::pair<int, int> coord);
	    std::string game_message = "Draw";
	    // pieces go in rows 1, 3, 5
	    // 			and cols 1, 3, 5
	    // (1, 3, 5) X (1, 3, 5) possible coords
		std::vector<std::vector<std::string>> board = {{" ", " ", "1", " ", "2", " ", "3", " ", "c"}, 
													   {" ", "|", "-", "|", "-", "|", "-", "|", " "}, 
											 		   {"1", "|", " ", "|", " ", "|", " ", "|", " "}, 
											 		   {" ", "|", "-", "|", "-", "|", "-", "|", " "},
											 		   {"2", "|", " ", "|", " ", "|", " ", "|", " "},
											 		   {" ", "|", "-", "|", "-", "|", "-", "|", " "},
											 		   {"3", "|", " ", "|", " ", "|", " ", "|", " "},
											 		   {" ", "|", "-", "|", "-", "|", "-", "|", " "},
											 		   {"r", " ", " ", " ", " ", " ", " ", " ", " "}};
	public:
		Board(bool first);
		bool is_valid(const std::pair<int, int> coord);
		void make_move(const std::pair<int, int> coord);
		bool get_turn();
		void switch_turn();
		bool game_over();
		std::string status();
		void update_board(const std::pair<int, int> coord);
		void draw_board();
};