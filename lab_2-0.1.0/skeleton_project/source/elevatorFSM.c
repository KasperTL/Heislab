#include "../inc/elevatorFSM.h"

/**
 * @file elevatorFSM.c
 * @brief Implementation file for elevatorFSM.h
 */


//Switch case between states, will run in the main while loop of the program
void elevatorFSM(Elevator *anElevator){
//printf("%d\n", get_current_state(anElevator));
    switch (get_current_state(anElevator))
    {
    case IDLE:
        printf("TETET");
        handle_IDLE(anElevator);
        break;
    case MOVING:
        //printf("I MOVING");
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
    printf("FORS");
    if(!get_has_destination(anElevator))
    {
        return;
    }
    else if(get_has_destination(anElevator))
    {
        printf("kkk");
        if(get_current_floor(anElevator) < get_destination_floor(anElevator))
        {
            printf("hei");
            MotorDirection(DIRN_UP);
            set_current_state(anElevator, MOVING);
        }
        else if(get_current_floor(anElevator) > get_destination_floor(anElevator))
        {
            MotorDirection(DIRN_DOWN);
            set_current_state(anElevator, MOVING);
        }
        
        return;
    }
    else if(elevio_stopButton())
    {
        elevio_doorOpenLamp(1);
        set_start_time(anElevator);
        set_current_state(anElevator, AT_DESTINATION);
    }
};

//define the triggers from Moving-state
void handle_MOVING(Elevator *anElevator)
{
    if(get_current_floor(anElevator)==get_destination_floor(anElevator))
    {
        MotorDirection(DIRN_STOP);
        elevio_doorOpenLamp(1);
        set_start_time(anElevator);
        set_current_state(anElevator, AT_DESTINATION);
        return;
    }
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
        set_current_state(anElevator, IDLE);
        return;
    }
};


void handle_EMERGENCY(Elevator *anElevator)
{
    
};


