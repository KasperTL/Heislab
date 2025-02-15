#include "../source/driver/elevio.h"

/**
 * @file order.h 
 * @brief Header file for order.c 
 */


 typedef enum {
    ORDER_UP,
    ORDER_DOWN,
    ORDER_INSIDE
} Order_type_t;


 typedef struct {
    int destination_floor; // destination floor of the order 
    Order_type_t order_type; // type of order
 } Order;

Order make_order(int destination_floor, Order_type_t order_type);
