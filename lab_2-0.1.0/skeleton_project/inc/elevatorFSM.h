#pragma once
#include "../source/driver/elevio.h"
#include "order.h"
#include <stdbool.h>

/**
 * @file elevatorFSM.h 
 * @brief Header file for elevatorFSM.c 
 */

// Enum for the different states of the elevator
typedef enum {
    IDLE,
    MOVING,
    AT_DESTINATION,
    EMERGENCY
} Elevator_state_t; 

//Test, kanskje bruk senere
//typedef void(*state_handler_ptr_fun)(Elevator* anElevator);

typedef struct {
    Elevator_state_t current_state; // current state of the elevator
    int current_floor; // current floor of the elevator
    int destination_floor; // next order to be executed
    bool has_destination; // bool to determine if the elevator has a destination floor
    time_t start_time;
    //state_handler_ptr_fun;
} Elevator;



//Function that updates the destination floor (will be used by the order handler)
void set_current_state(Elevator *anElevator, Elevator_state_t a_current_state);
Elevator_state_t get_current_state(Elevator *anElevator);

//updates the destination floor of anElevator to the given int value(must be between 0 and 3)
void set_destination_floor(Elevator *anElevator,int destination_floor);
int get_destination_floor(Elevator *anElevator);

void set_current_floor(Elevator *anElevator, int a_current_floor);
int get_current_floor(Elevator *anElevator);

void set_has_destination(Elevator *anElevator, bool has_a_destination);
bool get_has_destination(Elevator *anElevator);

void set_start_time(Elevator *anElevator);
int get_time_difference(Elevator *anElevator);

void handle_IDLE(Elevator *anElevator);
void handle_MOVING(Elevator *anElevator);
void handle_AT_DESTINATION(Elevator *anElevator);
void handle_EMERGENCY(Elevator *anElevator);


//The main FSM loop, decides which handle function will run depending on the state of the elevator
void elevatorFSM(Elevator *anElevator);


