#include "../inc/startup_sequence.h"


void startup_sequence(Elevator *anElevator)
{
    for(int floor = 0; floor < 4; floor++)
    {
        for(ButtonType button = BUTTON_HALL_UP; button <= BUTTON_CAB; button++)
        {
            elevio_buttonLamp(floor, button, 0);
        }
    }
    while(elevio_floorSensor() == -1)
    {
        elevio_motorDirection(DIRN_UP);
    }
    elevio_motorDirection(DIRN_STOP);
    printf("Startup til IDLE\n");
    set_current_state(anElevator, IDLE);
    set_current_floor(anElevator, elevio_floorSensor());
    set_has_destination(anElevator, false);
    elevio_floorIndicator(elevio_floorSensor());
    return;
}