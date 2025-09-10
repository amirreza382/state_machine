Elavator State Machine


This project is an elevator simulation implemented in C++20 using a state machine pattern. A doubly linked list is used to represent and transition between elevator states such as idle, moving up, moving down, and doors open.

⚙️ Features

C++20 implementation

State machine architecture

Doubly linked list for state transitions

Basic elevator states: Idle, Moving Up, Moving Down, Doors Open

🖥️ Build & Run
g++ -std=c++20 main.cpp elevator.cpp state_machine.cpp linked_list.cpp -o elevator
./elevator

📚 Future Work

Add scheduling algorithms

Support multiple elevators
