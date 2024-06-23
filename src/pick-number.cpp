#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <stdexcept>
#include "pick-number-game.hpp"
#include "retry-policy.hpp"

int get_input() {
    int guess;
    if (1 != std::scanf("%d", &guess)) {
        throw std::runtime_error("Invalid input");
    }
    return guess;
}

void clear_stdin() {
    // remove any remaining characters in the input buffer
    std::cin.ignore(INT_MAX, '\n');
}

int pick_number() {
    // get a random integer between 1 and 100
    return 1 + std::rand() % 100;
}

int main() {
    // randomize the random number generator
    std::srand(std::time(nullptr));
    pick_number_game game(
        std::puts, 
        retry_policy{get_input, clear_stdin}, 
        pick_number);
    game.start();
}
