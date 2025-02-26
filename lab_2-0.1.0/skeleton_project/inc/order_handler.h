#pragma once
#include "order.h"
#include "elevatorFSM.h"
#include "../source/driver/elevio.h"

typedef struct queue
{
    Order order;
    struct queue* next_order;
}queue;

struct queue* create_queue(Order order);

void insert_at_first(struct queue** head, Order order);

void insert_at_end(struct queue** head, Order order);

void insert_at_position(struct queue** head, Order order, int position);

void delete_first(struct queue** head);

void deleteAtPosition(struct queue** head, int position);

int define_route(struct queue* head, Order order);

void delete_destination(struct queue* head, int destination);