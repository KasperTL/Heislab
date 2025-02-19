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
void update_destination(Elevator *anElevator,int destination_floor);


void handle_IDLE(Elevator *anElevator);
void handle_MOVING(Elevator *anElevator);
void handle_AT_DESTINATION(Elevator *anElevator);
void handle_EMERGENCY(Elevator *anElevator);


//The main FSM loop, decides which handle function will run depending on the state of the elevator
void elevatorFSM(Elevator *anElevator);


//Time thing
void set_time(Elevator *anElevator);
int get_time_difference(Elevator *anElevator);

