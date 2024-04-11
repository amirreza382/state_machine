//
// Created by akiam on 28/11/2023.
//
#include "../../inc/input/input.h"



    // Constructor
    INP::input::input() : prv_access(false), pressed_button(0)  , counti{true}{
    }
    // Destructor
    INP::input::~input() {
    if (elevatorInstance != nullptr) {
        delete elevatorInstance;
        elevatorInstance = nullptr;
      }
    }

     // Function for processing input of user
void INP::input::process_input(int input) {
        pressed_button = input;

        // Checking if user is blocked to use elevator or no
        if (is_blocked()) {
            std::cout << "User is blocked. Wait for a moment.\n";
            return;
        }

        // Non private floors

        if (pressed_button >= -1 && pressed_button <= 8) {
            // Regular floors (FLOOR_P1 to FLOOR_8)
            std::cout << "You pressed :" << get_pressed_button() << "\n";

            // Instance of Elevator class
            if (elevatorInstance == nullptr) {
                elevatorInstance = new Elevator<Floor>;
            }


            if(true){
            elevatorInstance->processElevatorRequestInfo(input);}
        } else if (pressed_button == -2 ||
                  pressed_button == 9 ||
                   pressed_button == 10 ){
            // Private levels (FLOOR_P2 and FLOOR_9&10)
            double entered_password{};
            int max_attempts = 3;

            // Loop for asking and checking password after prv levels had been pressed
            while (max_attempts > 0) {
                pv_levels();
                std::cout << "\nPlease enter your password for gaining access: \n";
                std::cin >> entered_password;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Error reading password input.\n";

                    return;
                }
                // Processing request after approving the password
                if (validate_password(entered_password, password)) {
                    // Correct password, allow access
                    if (elevatorInstance == nullptr) {
                        elevatorInstance = new Elevator<Floor>;
                    }

                    elevatorInstance->processElevatorRequestInfo(input);
                    return;
                } else {
                    // Incorrect password
                    std::cout << "Incorrect password. Attempts remaining: " << max_attempts - 1 << "\n";
                    max_attempts--;

                    if (max_attempts == 0) {

                        block_user();
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return;
                    }
                }
            }
        } else {
            // Invalid input
            std::cout << "Invalid input\n";
        }
    }

     // Function for Helping user
    void INP::input::help() {
        std::cout << "Help state intiated!!!\nWe are calling '911' (They will not come anyways)\n";
        std::string content = read_from_file("Help.txt");
        std::ifstream infile("Help.txt");
        if (!infile.is_open()) {
            std::cerr << "Error opening file: " << "Help.txt" << std::endl;
            return;
        }

        std::cout << content << std::endl;
    }


    void INP::input::pv_levels() {
        std::cout << "PV Levels  had been choosen \n";
    }

    int INP::input::get_pressed_button() const {
        return pressed_button;
    }

    bool INP::input::validate_password(double entered_password, double  correct_password) {
        if (entered_password == correct_password) return true;
        else return false;
    }
    // if user is block , he/she cannot use elevator for 30 sec
    bool INP::input::is_blocked() {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - block_start_time).count();
        return elapsed_time < 30;
    }

    void INP::input::block_user() {
        std::cout << "Too many incorrect attempts. User blocked for 30 seconds.\n";
        block_start_time = std::chrono::steady_clock::now();
    }

    std::string INP::input::read_from_file(const std::string &filename) {
        std::ifstream infile(filename);
        std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
        return content;
    }



    void INP::input::start_menu() {
        std::cout << "Start : S\n";
        std::cout << "Tutorial : H \n";
        std::cout << "Exit : Q\n";
    }

    void INP::input::menu() {
        std::cout << "Welcome to the GG Elevator\n";
        std::cout
                << "In the GG coaperation building we want your absulote comfort,\n Thats why we have elevator(which probobly will not work)\n";
        std::cout << "Menu : M \n";
    }

    void INP::input::invalid_input(){
        std::cout << "Invalid input. Please try again.)\n";
    }

