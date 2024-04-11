



// Due to usage of Template and advice of the teachers we implemented everything in the header file,
// and comented all the privious implementation here.







/*

  #include <thread>
#include "../../inc/Elevator/Elevator.h"
#include "../../inc/Elevator/LinkedList.h"


template <typename T>
Elevator<T>::Elevator()  {
    initializeFloors();
}

template <typename T>
Elevator<T>::~Elevator() {
    Node<T>* currentNode = floors.getHead();
    while (currentNode) {
        Node<T>* nextNode = currentNode->getNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

template <typename T>
void Elevator<T>::initializeFloors() {
    for (int i = 0; i <= static_cast<int>(Floor::FLOOR_10); ++i) {
        floors.addNode(static_cast<T>(i));
    }

    currentFloor = floors.getHead()->next->next;
}

template <typename T>
void Elevator<T>::moveToFloor(T targetFloor) {
if (currentFloor == NULL) initializeFloors();
    int count = 0;
    if (targetFloor) {
        // Traverse the linked list to find the target floor
        while (currentFloor->getFloor() != targetFloor) {
            // Update the current node based on the direction
            if (currentFloor->getFloor() < targetFloor) {
                if ( count == 0)std::cout << "inside while loop of moveToFloor" << std::endl; count++;
                currentFloor = currentFloor->getNext();
            } else if (currentFloor->getFloor() > targetFloor) {
                currentFloor = currentFloor->getPrev();
            }

            // Print the current floor and wait for 1 second
            std::cout << "Elevator at Floor " << static_cast<int>(currentFloor->getFloor() - 2) << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

template <typename T>
void Elevator<T>::processElevatorRequestInfo(int elevatorInfo) {
    T targetFloor;

    if (elevatorInfo >= -2 && elevatorInfo <= 10) {
        targetFloor = static_cast<T>(elevatorInfo + 2);
    } else {
        std::cout << "Invalid floor input: " << elevatorInfo << std::endl;
        return;
    }

    moveToFloor(targetFloor);
}

template <typename T>
Node<T>* Elevator<T>::findFloorNode(T targetFloor) {
    if (!currentFloor) {
        std::cerr << "Error: Elevator not initialized." << std::endl;
        return nullptr;
    }
    Node<T>* currentNode = currentFloor;

    while (currentNode) {
        if (currentNode->data == targetFloor) {
            return currentNode;
        } else {
            int direction = static_cast<int>(targetFloor) - static_cast<int>(currentNode->data);

            if (direction > 0) {
                currentNode = currentNode->next;
            } else if (direction < 0) {
                currentNode = currentNode->prev;
            }
        }
    }

    return nullptr;
}


*/