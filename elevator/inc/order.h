#include "elevio.h"
/**
 * @file order.h 
 * @brief This file contains the Order class
 */
typedef struct {
    int destinationFloor;
    MotorDirection direction;
} Order; 

Order makeOrder(int floor, MotorDirection direction); 