// Copyright (c) 2025 Dylan Mutabazi All rights reserved
// Created by Dylan Mutabazi
// Date: April 2025
// Guesses a number between 0-9 in a loop until you get it

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int passcode = 152;

int main() {
    // Initial greeting
    std::cout << "Hello mate, ";
    std::cout << "in this game we play russian roulette.";
    std::cout << "\n But first you must decode this phrase";
    std::cout << "'OB' into an integer,";
    std::cout << "you have 3 guess. Good luck and have fun";

    // Sets number of tries for passcode to 3
    int lives = 3;

    // Passcode loop
    while (true) {
        std::cout << "\n"<< std::endl;
        std::string user_passcode;
        std::cout << "What is the passcode: ";
        std::cin >> user_passcode;

        // Tries to convert user_input into int
        try {
            int user_passcode_int = std::stoi(user_passcode);

            if (user_passcode_int == passcode) {
                std::cout << "you can start playing";

                // Creates a variable chambers with arrays of zeros and ones.
                // 0 represent empty chambers, 1 represent bullet
                std::vector<int> chambers = {0, 1, 0, 0, 0, 0};

                // Shuffles the arrays
                std::random_shuffle(chambers.begin(), chambers.end());

                // loops 6 times
                for (int i = 0; i < 6; i++) {
                    std::cout << "\n"<< std::endl;
                    std::string fire;
                    std::cout << "Press any key to fire ";
                    std::cin >> fire;

                    // If the value in chamber is 1 then your dead
                    if (chambers[i] == 1) {
                        std::cout << "\n"<< std::endl;
                        std::cout << "BANG !!! ... you died" << std::endl;
                        break;
                    } else {
                        std::cout << "\n"<< std::endl;
                        std::cout << "good job you survived." << std::endl;
                        std::cout << "\n" << std::endl;
                        std::string again;
                        std::cout << "Do you wanna go again (y/n)? ";
                        std::cin >> again;

                        // asks if they want to go gain
                        if (again == "y" || again == "Y" || again == "Yes"
                            || again == "YES" || again == "yes") {
                            std::cout << "\n" << std::endl;
                        } else if (again == "n" || again == "N" ||
                            again == "No" || again == "NO" || again == "no") {
                            std::cout << "\n" << std::endl;
                            std::cout << "goodbye";
                            break;
                        } else {
                            std::cout << "\n" << std::endl;
                            std::cout << "see ya";
                            break;
                        }
                    }
                }
                break;

                // remove 1 from life
                // each time get passcode wrong
            } else {
                std::cout << "\n" << std::endl;
                lives--;
                std::cout << user_passcode_int;
                std::cout << " is not the right code. you have ";
                std::cout << lives << " chances left.";
                if (lives <= 0) {
                    std::cout << "\n" << std::endl;
                    std::cout << "Your guesses are done" << std::endl;
                    break;
                }
            }

            // Catches the exceptions/ error while trying to convert to int
        } catch (...) {
            std::cout << user_passcode << " is not an integer" << std::endl;
            break;
        }
    }
}
