#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include <unistd.h>
#include "../inc/elevatorFSM.h"
#include "../inc/startup_sequence.h"
#include "../inc/buttons.h"
#include "../inc/order_handler.h"



int main(){
    elevio_init();
    
    Elevator T;
    ElevatorOrders O;
    ElevatorOrders_init(&O);

    startup_sequence(&T);

    while(1){
        if(elevio_stopButton()!=1)
        {
            elevio_stopLamp(0);
            check_buttons(&O,&T);
        }
        else
        {
            elevio_stopLamp(1);
            set_start_time(&T);
            set_has_destination(&T, false);
            set_current_state(&T,EMERGENCY);
        }
    
        nanosleep(&(struct timespec){0, 20}, NULL);
        elevatorFSM(&T,&O);
    }

    return 0;
}

