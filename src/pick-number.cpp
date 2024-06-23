#include "pick-number-game.hpp"
#include <cstdio>

int main() {
    pick_number_game game(puts);
    game.start();
}
