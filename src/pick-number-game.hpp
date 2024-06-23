#pragma once

template<typename say_t>
class pick_number_game {
public:
    pick_number_game(say_t say) : say(say) {}
    void start() {
        say("Welcome to the pick a number game!");
    }
    private:
    say_t say;
};
