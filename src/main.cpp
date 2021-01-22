#include "../header/board.h"
#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    // decide who goes first turn
    bool x_first = true;
    while (true) {
        srand(time(nullptr));
        int x_choice = rand() % (100 + 1 - 1) + 1;
        int o_choice = rand() % (100 + 1 - 1) + 1;
        while (true) {
            std::cout << "Player X select a number between 1 - 100" << std::endl;
            std::cin >> x_choice;
            if (x_choice > 100 || x_choice < 1) {
                continue;
            }
            break;
        }
        while (true) {
            std::cout << "Player O select a number between 1 - 100" << std::endl;
            std::cin >> o_choice;
            if (o_choice > 100 || o_choice < 1 || o_choice == x_choice) {
                continue;
            }
            break;
        }
        int rand_number = rand() % (100 + 1 - 1) + 1;

        if (abs(x_choice - rand_number) == abs(o_choice - rand_number)) {
            std::cout << "Result was a tie, select again" << std::endl;
            continue;
        }

        x_first = (abs(x_choice - rand_number) < abs(o_choice - rand_number));
        break;
    }

    if (x_first) {
        std::cout << "Player X goes first" << std::endl;
    }
    else {
        std::cout << "Player O goes first" << std::endl;
    }
    std::cout << std::endl;

    Board board = Board(x_first);
    
    std::string player_x = "Player X enter your move: ";
    std::string player_o = "Player O enter your move: ";

    board.draw_board();

    // start game
    while (true) {
        if (board.get_turn()) {
            std::cout << player_x;
            int x, y;
            std::cin >> x >> y;
            std::cout << std::endl;

            if (board.is_valid({x, y})) {
                board.make_move({x, y});
            }
            else {
                std::cout << "(" << x << ", " << y << ") is not a valid move" << std::endl;
                continue;
            }
        }
        else {
            std::cout << player_o;
            int x, y;
            std::cin >> x >> y;
            std::cout << std::endl;
            
            if (board.is_valid({x, y})) {
                board.make_move({x, y});
            }
            else {
                std::cout << "(" << x << ", " << y << ") is not a valid move" << std::endl;
                continue;
            }
        }
        board.draw_board();
        if (board.game_over()) {
            std::cout << "Game over: " << board.status() << std::endl;
            std::cout << std::endl;
            return 0;
        }
        board.switch_turn();
    }
}

