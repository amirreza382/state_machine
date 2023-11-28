//
// Created by akiam on 22/11/2023.
//

#ifndef STATE_MACHINE_STATEMACHINE_H
#define STATE_MACHINE_STATEMACHINE_H
#include <iostream>
#include <unordered_map>
#include <functional>


template <typename State , typename Event>




class StateMachine {
public:
    using TransitionFunction = std::function<void()>;
    void addTransition(const State & from , const Event & event , const State & to , const TransitionFunction & transition){
        transitions_[std::make_pair(from , event)] = std::make_pair(to , transition);
    }
    void SetState(const State& state){
        current_state_ = state;
    }
    void ProcessEvent (const Event & event){
        auto transition = transitions_.find(std::make_pair(current_state_ , event));
        if (transition != transition.end()){
            transition->second.second();
            current_state_ = transition->second.first;
        }else{
            std::cout << "Invalid input.\n";
        }
    }
private:
    State current_state_;
    std::unordered_map<std::pair<State , Event>, std::pair<State , TransitionFunction>> transitions_;

};


#endif //STATE_MACHINE_STATEMACHINE_H
