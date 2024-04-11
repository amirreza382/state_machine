// Elevator.h

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include "LinkedList.h"
#include "../Input/input.h"
#include <thread>

// Enum to represent the floors
enum class Floor {
    INVALID_VALUE=-3 ,
    FLOOR_P2=-2,
    FLOOR_P1, FLOOR_G,
    FLOOR_1, FLOOR_2, FLOOR_3, FLOOR_4, FLOOR_5,
    FLOOR_6, FLOOR_7, FLOOR_8, FLOOR_9, FLOOR_10
};


template <typename T>
class Elevator {
private:
    // Creating instance of Floors and Nodes
    Node<T>* currentFloor;
    LinkedList<T> floors;
public:
    //Constructor and Destructor
    Elevator();
    ~Elevator();

    void initializeFloors();

    void moveToFloor(T targetFloor);

    void resetElevatorState();

    void processElevatorRequestInfo(int elevatorInfo);

    Node<T>* findFloorNode(T targetFloor);
};

template <typename T>
Elevator<T>::Elevator() : currentFloor(nullptr) {
    if (!currentFloor)
        initializeFloors();    resetElevatorState();


}


template <typename T>
Elevator<T>::~Elevator() {
    Node<T>* currentNode = floors.getHead();
    while (currentNode) {
        Node<T>* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

}

// Initializeing floor using a loop from begining till end
template <typename T>
void Elevator<T>::initializeFloors() {
    if (!floors.getHead()) {
        for (int i = static_cast<int>(Floor::INVALID_VALUE); i <= static_cast<int>(Floor::FLOOR_10); ++i) {
            floors.addNode(static_cast<T>(i));
        }
    }

    currentFloor = floors.getHead()->next->next->next ;

}


// Resetting current state after each usage
template <typename T>
void Elevator<T>::resetElevatorState() {
    // Find the node corresponding to the ground floor (FLOOR_G)
    currentFloor = findFloorNode(static_cast<T>(Floor::FLOOR_G));

    if (!currentFloor) {
        std::cerr << "Error: Ground floor not found." << std::endl;
    }
}
// Main funcition for traversing between the linked list
template <typename T>
void Elevator<T>::moveToFloor(T targetFloor) {
    if (!currentFloor) {
        std::cerr << "Error: Elevator not initialized." << std::endl;
        resetElevatorState();
    }

    int count = 0;
    if (targetFloor != Floor::INVALID_VALUE) {
        // Traverse the linked list to find the target floor
        while (currentFloor && currentFloor->data != targetFloor) {
            // Update the current node based on the direction
            if (currentFloor->data < targetFloor) {
                if (count == 0) std::cout << "Using Elevator" << std::endl;
                count++;
                currentFloor = currentFloor->next;
            } else if (currentFloor->data > targetFloor) {
                currentFloor = currentFloor->prev;
            }

            // Print the current floor and wait for 1 second
            if (currentFloor) {
                // -2 here and -1 after in next if is for transforming enum to INT and printing it
                std::cout << "Elevator at Floor " << static_cast<int>(currentFloor->data) << std::endl;
                // 1 Sec Delay is to simulate and actual elevator :)
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        // Depands on which floor (near head or tail) hd been choosen one of the logic down or above will be used
        if (currentFloor) {
            std::cout << "Elevator reached the destination Floor " << static_cast<int>(currentFloor->data) << std::endl;
        } else {
            std::cout << "Invalid target floor." << std::endl;
        }
    }
    else {
        std::cout << "Invalid target floor." << std::endl;
    }

}

// Function that is called in Input class and get the user pressed as int and transferm it as enum
template <typename T>
void Elevator<T>::processElevatorRequestInfo(int elevatorInfo) {
    T targetFloor{};

    if (elevatorInfo >= -2 && elevatorInfo <= 10) {
        targetFloor = static_cast<T>(elevatorInfo );
    } else {
        std::cout << "Invalid floor input: " << elevatorInfo << std::endl;
        return;
    }

    moveToFloor(targetFloor);
}

// Function for deciding the traversing direction of linked list
template <typename T>
Node<T>* Elevator<T>::findFloorNode(T targetFloor) {
    if (!currentFloor) {
        std::cerr << "Error: Elevator not initialized." << std::endl;
        return nullptr;
    }

    Node<T>* currentNode = currentFloor;
        // A loop that indicates direction of traverse
    while (currentNode && currentNode->data != targetFloor) {
        if (currentNode->data < targetFloor) {
            currentNode = currentNode->next;
        } else {
            currentNode = currentNode->prev;
        }
    }

    if (currentNode && currentNode->data == targetFloor) {
        return currentNode;
    }

    std::cerr << "Error: Target floor not found." << std::endl;
    return nullptr;
}



#endif // ELEVATOR_H
