/*
** EPITECH PROJECT, 2025
** my inventiry ;h
** File description:
** my inventory .h
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEM 6

typedef struct Object {
    char name[10];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEM];;
    int count;
} Inventory;

void create_inventory(Inventory *stock);
void add_item(Inventory *stock, char *name, int quantity);
#endif