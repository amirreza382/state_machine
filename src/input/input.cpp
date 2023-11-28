//
// Created by akiam on 28/11/2023.
//
#include "../../inc/input/input.h"
#include <iostream>
#include <fstream>




input::input() : prv_access(false), password(0), pressed_button(0) {
}

void input::process_input(int input) {
    pressed_button = input;

    if (is_blocked()) {
        std::cout << "User is blocked. Wait for a moment.\n";
        return;
    }

    if (pressed_button >= 1 && pressed_button <= 8) {
        levels();
    } else if (pressed_button == 9 || pressed_button == 10) {
        // Ask for password for levels 9 and 10
        double entered_password;
        std::cout << "Enter password: ";
        std::cin >> entered_password;

        if (validate_password(entered_password, (pressed_button == 9) ? password_level_9 : password_level_10)) {
            pv_levels();
        } else {
            std::cout << "Incorrect password. Attempts remaining: " << (3 - incorrect_password_attempts) << "\n";
            incorrect_password_attempts++;

            if (incorrect_password_attempts >= 3) {
                block_user();
            }
        }
    } else if (pressed_button == 0) {
        help();
    } else {
        std::cout << "Invalid input\n";
    }
}

void input::help() {
    std::cout << "Help state\n";
    std::string content = read_from_file("help_info.txt");
    std::cout << content << std::endl;
}

void input::levels() {
    std::cout << "Levels state\n";
}

void input::pv_levels() {
    std::cout << "PV Levels state\n";
}

int input::get_pressed_button() const {
    return pressed_button;
}

bool input::validate_password(double entered_password, double correct_password) {
    return entered_password == correct_password;
}

bool input::is_blocked() {
    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - block_start_time).count();
    return elapsed_time < 30;
}

void input::block_user() {
    std::cout << "Too many incorrect attempts. User blocked for 30 seconds.\n";
    block_start_time = std::chrono::steady_clock::now();
}

std::string input::read_from_file(const std::string& filename) {
    std::ifstream infile(filename);
    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    return content;
}