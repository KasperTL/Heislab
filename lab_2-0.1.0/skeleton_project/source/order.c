#include "../inc/order.h"

/**
 * @file order.c
 * @brief Implementation file for order.h
 */

Order make_order(int destination_floor, int current_floor, Order_type_t order_type) {
    Order new_order;
    new_order.destination_floor = destination_floor;
    new_order.current_floor = current_floor;
    new_order.order_type = order_type;
    return new_order;
}