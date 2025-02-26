#include "../inc/order_handler.h"


struct queue* create_queue(Order order)
{
    struct queue* new_queue = (struct queue*)malloc(sizeof(struct queue));
    new_queue->order = order;
    new_queue->next_order = NULL;
    return new_queue;
}

void insert_at_first(struct queue** head, Order order)
{
    struct queue* new_queue = create_queue(order);
    new_queue->next_order = *head;
    *head = new_queue;
}

void insert_at_end(struct queue** head, Order order)
{
    struct queue* new_queue = create_queue(order);
    if(*head == NULL)
    {
        *head = new_queue;
        return;
    }
    struct queue* temp = *head;
    while (temp->next_order != NULL)
    {
        temp = temp->next_order;
    }
    temp->next_order = new_queue;
}

void insert_at_position(struct queue** head, Order order, int position)
{
    struct queue* new_queue = create_queue(order);
    if(position == 0)
    {
        insert_at_first(head, order);
        return;
    }
    struct queue* temp = *head;
    for(int i=0; temp != NULL && i < position -1; i++)
    {
        temp = temp->next_order;
    }
    if(temp == NULL)
    {
        printf("Position out of range\n");
        free(new_queue);
        return;
    }
    new_queue->next_order = temp->next_order;
    temp->next_order = new_queue;
}

void delete_first(struct queue** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct queue* temp = *head;
    if(temp->next_order == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next_order->next_order != NULL)
    {
        temp = temp->next_order;
    }
    free(temp->next_order);
    temp->next_order = NULL;
}

void deleteAtPosition(struct queue** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct queue* temp = *head;
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next_order;
    }
    if (temp == NULL || temp->next_order == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct queue* next = temp->next_order->next_order;
    free(temp->next_order);
    temp->next_order = next;
}


int define_route(struct queue* head, Order order)
{
    queue* temp = head;

    int route[N_FLOORS] = {0};

    while(temp != NULL)
    {
        if(temp->order.order_type == ORDER_UP && temp->order.destination_floor > temp->order.current_floor)
        {
            route[temp->order.destination_floor-1] = 1;
        }
        if(temp->order.order_type == ORDER_DOWN && temp->order.destination_floor < temp->order.current_floor)
        {
            route[temp->order.destination_floor-1] = 1;
        }
        temp = temp->next_order;
    }
    return route;
}

void delete_destination(struct queue* head, int destination)
{
    queue* temp = head;
    int pos_in_queue;

    while(temp != NULL)
    {
        if(temp->order.destination_floor == destination)
        {
            deleteAtPosition(head, destination);
        }
    }
}