// input.h

#ifndef STATE_MACHINE_INPUT_H
#define STATE_MACHINE_INPUT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

enum level {
    HELP,
    LEVELS,
    PV_LEVELS
};

class input {
public:
    input();
    void process_input(int input);
    void help();
    void levels();
    void pv_levels();
    int get_pressed_button() const;
    std::string read_from_file(const std::string& filename);

private:
    std::vector<int> levels_;
    bool prv_access;
    double password;
    int pressed_button;

    double password_level_9;
    double password_level_10;

    int incorrect_password_attempts;

    std::chrono::steady_clock::time_point block_start_time;

    bool validate_password(double entered_password, double correct_password);
    bool is_blocked();
    void block_user();
};

#endif // STATE_MACHINE_INPUT_H