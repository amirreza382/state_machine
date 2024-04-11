// input.h

#ifndef STATE_MACHINE_INPUT_H
#define STATE_MACHINE_INPUT_H
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include "../Elevator/Elevator.h"
#include <random>

enum MenuOption { MENU = 1, START, HELP, EXIT};

MenuOption getMenuOption();

template <typename T> class Elevator;
    enum class Floor;


namespace INP {

    class input {
    public:
        input();

        ~input();

        void process_input(int input);

        void help();

        void levels();

        void pv_levels();

        int get_pressed_button() const;

        std::string read_from_file(const std::string &filename);

        // void bombom(int number_pass);
        int getElevatorRequestInfo(int floor);

        void start_menu();

        void menu();

        void invalid_input();
        bool counti;


    private:
        std::vector<int> levels_;
        bool prv_access;
        double password = 1234;
        int pressed_button;
        Elevator<Floor>* elevatorInstance{};

        double password_level_9{};
        double password_level_10{};

        int incorrect_password_attempts = 0;

        std::chrono::steady_clock::time_point block_start_time;

        static bool validate_password(double entered_password, double  correct_password);

        bool is_blocked();

        void block_user();
    };
}
#endif // STATE_MACHINE_INPUT_H