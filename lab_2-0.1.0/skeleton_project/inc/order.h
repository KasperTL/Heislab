#include "../source/driver/elevio.h"
#include "utilities.h"

/**
 * @file order.h 
 * @brief Header file for order.c 
 */


 typedef enum {
    ORDER_UP,
    ORDER_DOWN,
} Order_type_t;

typedef enum {
   INSIDE,
   OUTSIDE
} Order_out_inside_t;

 typedef struct {
    int destination_floor; // destination floor of the order 
    int current_floor;
    Order_type_t order_type; // type of order
    Order_out_inside_t inside_or_outside;
 } Order;

Order make_order(int destination_floor, int current_floor, Order_type_t order_type);
