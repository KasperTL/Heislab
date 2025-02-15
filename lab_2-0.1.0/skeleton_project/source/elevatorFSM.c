#include "../inc/elevatorFSM.h"

/**
 * @file elevatorFSM.c
 * @brief Implementation file for elevatorFSM.h
 */



void elevatorFSM(Elevator *elevator){
    switch (elevator->current_state)
    {
    case IDLE:
        handle_IDLE(elevator);
        break;
    case MOVING_UP:
        handle_MOVING_UP(elevator);
        break;
    case MOVING_DOWN:
        handle_MOVING_DOWN(elevator);
        break;
    case DOOR_OPEN:
        handle_DOOR_OPEN(elevator);
        break;
    case DOOR_CLOSING:
        handle_DOOR_CLOSING(elevator);
        break;
    case EMERGENCY: 
        handle_EMERGENCY(elevator);
    default:
        break;
    }
};