#include "../source/driver/elevio.h"
#include "order.h"

/**
 * @file elevatorFSM.h 
 * @brief Header file for elevatorFSM.c 
 */

// Enum for the different states of the elevator
typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPEN,
    DOOR_CLOSING,
    EMERGENCY
} Elevator_state_t; 


typedef struct {
    Elevator_state_t current_state; // current state of the elevator
    int current_floor; // current floor of the elevator
    int destination_floor; // next order to be executed
} Elevator;

//Function that updates the destination floor (will be used by the order handler)
void update_destination(Elevator *elevator,int destination_floor);


void handle_IDLE(Elevator *elevator);
void handle_MOVING_UP(Elevator *elevator);
void handle_MOVING_DOWN(Elevator *elevator);
void handle_DOOR_OPEN(Elevator *elevator);
void handle_DOOR_CLOSING(Elevator *elevator);
void handle_EMERGENCY(Elevator *elevator);


//The main FSM loop, decides which handle function will run depending on the state of the elevator
void elevatorFSM(Elevator *elevator);

