#include "../inc/elevatorFSM.h"

/**
 * @file elevatorFSM.c
 * @brief Implementation file for elevatorFSM.h
 */


//Switch case between states, will run in the main while loop of the program
void elevatorFSM(Elevator *anElevator){
    switch (anElevator->current_state)
    {
    case IDLE:
        handle_IDLE(anElevator);
        break;
    case MOVING:
        handle_MOVING(anElevator);
        break;
    case AT_DESTINATION:
        handle_AT_DESTINATION(anElevator);
        break;
    case EMERGENCY: 
        handle_EMERGENCY(anElevator);
    default:
        break;
    }
};

//updates the destination floor of anElevator to the given int value(must be between 0 and 3)
void update_destination(Elevator *anElevator,int destination_floor)
{
    if(destination_floor<0 || destination_floor > (N_FLOORS-1))
    {
        //later implent interupt
        //prints "Floor out of bound"
        printf("Floor out of bound");
    }
    anElevator->destination_floor = destination_floor;
    return;
};

//define the triggers from IDLE-state
void handle_IDLE(Elevator *anElevator)
{
    if(!anElevator->has_destination)
    {
        return;
    }
    else if(anElevator->has_destination)
    {
        if(anElevator->current_floor < anElevator->destination_floor)
        {
            MotorDirection(DIRN_UP);
        }
        else if(anElevator->current_floor > anElevator->destination_floor)
        {
            MotorDirection(DIRN_DOWN);
        }
        anElevator->current_state = MOVING;
        return;
    }
    else if(elevio_stopButton())
    {
        elevio_doorOpenLamp(1);
        set_time(anElevator);
        anElevator->current_state = AT_DESTINATION;
    }
};

//define the triggers from Moving-state
void handle_MOVING(Elevator *anElevator)
{
    if(anElevator->current_floor==anElevator->destination_floor)
    {
        MotorDirection(DIRN_STOP);
        elevio_doorOpenLamp(1);
        set_time(anElevator);
        anElevator->current_state = AT_DESTINATION;
        return;
    }
};

//define the triggers from Handle_AT_DESTINATION-state
void handle_AT_DESTINATION(Elevator *anElevator)
{
    if(elevio_obstruction())
    {
        set_time(anElevator);
        return;
    }
    else if(get_time_difference(anElevator)>= 3)
    {
        elevio_doorOpenLamp(0);
        anElevator->current_state = IDLE;
        return;
    }
};


void handle_EMERGENCY(Elevator *anElevator)
{
    
};


void set_time(Elevator *anElevator)
{
    anElevator->start_time = time(NULL);
}

int get_time_difference(Elevator *anElevator)
{
    return (int)time(NULL) - anElevator->start_time;
}