#include "../inc/elevatorFSM.h"

/**
 * @file elevatorFSM.c
 * @brief Implementation file for elevatorFSM.h
 */


//Switch case between states, will run in the main while loop of the program
void elevatorFSM(Elevator *anElevator){

    switch (get_current_state(anElevator))
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
        break;
    default:
        break;
    }
};






void set_current_state(Elevator *anElevator, Elevator_state_t a_current_state)
{
    anElevator->current_state = a_current_state;
}

Elevator_state_t get_current_state(Elevator *anElevator)
{
    return anElevator->current_state;
}


void set_destination_floor(Elevator *anElevator,int destination_floor)
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


int get_destination_floor(Elevator *anElevator)
{
    return anElevator->destination_floor;
}

void set_current_floor(Elevator *anElevator, int a_current_floor)
{
    anElevator->current_floor = a_current_floor;
}

int get_current_floor(Elevator *anElevator)
{
    return anElevator->current_floor;
}

void set_has_destination(Elevator *anElevator, bool has_a_destination)
{
    anElevator->has_destination = has_a_destination;
}

bool get_has_destination(Elevator *anElevator)
{
    return anElevator->has_destination;
}

void set_start_time(Elevator *anElevator)
{
    anElevator->start_time = time(NULL);
}

int get_time_difference(Elevator *anElevator)
{
    return (int)time(NULL) - anElevator->start_time;
}



//define the triggers from IDLE-state
void handle_IDLE(Elevator *anElevator)
{
    if(!get_has_destination(anElevator))
    {
        return;
    }
    else if(get_has_destination(anElevator))
    {   
        if(get_current_floor(anElevator) == get_destination_floor(anElevator)){
            printf("Hopp dra IDLE til DEST\n");
            set_start_time(anElevator);
      vectorrent_state(anElevator, MOVING);
        }
        return;
    }   
    else if(elevio_stopButton())
    {
        printf("Hopp dra IDLE til DEST\n");
        elevio_doorOpenLamp(1);
        set_start_time(anElevator);
        set_current_state(anElevator, AT_DESTINATION);
    }
};

//define the triggers from Moving-state
void handle_MOVING(Elevator *anElevator)
{
    //printf("%d\n", get_current_state(anElevator));
    if(elevio_floorSensor() != -1)
    {
        //Turn off the previous floor indicator 
        //elevio_floorIndicator(get_current_floor(anElevator));

        //update the current floor
        set_current_floor(anElevator, elevio_floorSensor());

        //Turn on the floor indicator
        //elevio_floorIndicator(get_current_floor(anElevator));
    }
    if(get_current_floor(anElevator)==get_destination_floor(anElevator))
    {
        elevio_motorDirection(DIRN_STOP);
        elevio_doorOpenLamp(1);
        set_start_time(anElevator);
        printf("Hopp fra MOVE til DEST\n");
        set_current_state(anElevator, AT_DESTINATION);
        return;
    }
    return;
};

//define the triggers from Handle_AT_DESTINATION-state
void handle_AT_DESTINATION(Elevator *anElevator)
{
    
    if(elevio_obstruction())
    {
        set_start_time(anElevator);
        return;
    }
    else if(get_time_difference(anElevator)>= 3)
    {
        elevio_doorOpenLamp(0);
        printf("Hopp fra at DEST til IDLE\n");
        set_current_state(anElevator, IDLE);
        return;
    }
};


void handle_EMERGENCY(Elevator *anElevator)
{
    
};


