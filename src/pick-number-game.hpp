#pragma once

template<typename say_t, typename input_t, typename picker_t>
class pick_number_game {
public:
    pick_number_game(say_t say, input_t input, picker_t picker) : 
    say_{say}, input_{input}, picker_{picker} {}
    void start() {
        say_("Welcome to the pick a number game!");
        say_("I'm thinking of a number between 1 and 100.");
        say_("Can you guess what it is?");
        int number = picker_();
        int guess = 0;
        int tries = 0;
        while (guess != number && ++tries < 5) {
            guess = input_();
            if (guess < number) {
                say_("Too low!");
            } else if (guess > number) {
                say_("Too high!");
            }
        }
        if (guess == number) {
            say_("Congratulations! You guessed the number!");
        } else {
            say_("Sorry, you didn't guess the number.");
        }
    }
private:
    say_t say_;
    input_t input_;
    picker_t picker_;
};
