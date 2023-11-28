#include <iostream>

int main() {

    statemachine<elevator_state> machine;
    machine.add_state( .... );
    machine.connect_states( state1, input, state2 );


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
