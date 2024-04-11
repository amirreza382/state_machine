//#include "inc/Elevator/Elevator.h"
//#include "inc/Input/input.h"
#include <iostream>
#include <limits> // for std::numeric_limits
#include "src/Program/program.cpp"

int main(){


        try {
            program_main(); // Call the main program function
            return 0;  // Return 0 to indicate successful execution
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            return 1;  // Return 1 to indicate an error
        } catch (...) {
            std::cerr << "Unknown exception caught" << std::endl;
            return 1;  // Return 1 to indicate an error
        }







    /*  INP::input userInput;
      int count = 0;
      int size = 0;
      userInput.menu();
      while (true) {


          std::string userPressedButton{};
          int pressed_level{};

          std::cin >> userPressedButton;
          if (userPressedButton == "M" || userPressedButton == "m") {
              size++;
              if (count == 0) {
                  userInput.start_menu();
                  std::cin >> userPressedButton;

                  if (userPressedButton == "H" || userPressedButton == "h") {
                      userInput.help();
                      count++;
                  } else if (userPressedButton == "S" || userPressedButton == "s") {
                      while (true) {
                          std::cout << "Please choose your destination (-2 - 10)\n";

                          if (std::cin >> pressed_level) {
                              if (pressed_level >= -2 && pressed_level <= 10) {
                                  count++;
                                  break;
                              } else {
                                  std::cout << "Invalid input. Please enter a valid int.\n";
                                  std::cin.clear();
                                  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                            }
                          } else {
                              std::cout << "Invalid input. Please enter a valid int.\n";
                              std::cin.clear();
                              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                          }
                      }
                  } else if (userPressedButton == "Q" || userPressedButton == "q") {
                      std::cout << "Thank you for using our broken ass elevator!!\n";
                      break;
                  } else {
                      std::cout << "\nInput Invalid!!!\nPlease Enter again!!\n";
                      count = 0;
                  }
              }
          } else {
              std::cout << "\nInput Invalid!!!\nPlease Enter again!! ('M' or 'm')\n";
              size = 0;
          }

          if (count > 0 && size > 0) {
              std::cout << "Do you wish to continue?\n";
              std::cout << "[Y/N] ??\n";

              std::string dummy{};
              std::cin >> dummy;

              if (dummy == "Y" || dummy == "y") {
                  count -- ;

                  size = 1;
              } else if (dummy == "n" || dummy == "N") {
                  std::cout << "Thank you for using our broken ass elevator!!\n";
                  break;
              }
          } else {
              std::cout << "Press an acceptable button :)\n";
          }

          // Process user input
          userInput.process_input(pressed_level);
      }
  */
    return 0;
}
