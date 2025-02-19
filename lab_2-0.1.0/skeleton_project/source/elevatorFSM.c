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
    case MOVING:
        handle_MOVING(elevator);
        break;
    case AT_DESTINATION:
        handle_AT_DESTINATION(elevator);
        break;
    case EMERGENCY: 
        handle_EMERGENCY(elevator);
    default:
        break;
    }
};


void update_destination(Elevator *elevator,int destination_floor)
{
    
};


void handle_IDLE(Elevator *elevator)
{
    
};


void handle_MOVING(Elevator *elevator)
{

};


void handle_AT_DESTINATION(Elevator *elevator)
{

};


void handle_EMERGENCY(Elevator *elevator)
{

};