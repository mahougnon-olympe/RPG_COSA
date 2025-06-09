/*
** EPITECH PROJECT, 2025
** RPG_COSA
** File description:
** inventory
*/

#include "include/inventory.h"
#include "include/my_rpg.h"
#include <stdio.h>
#include <string.h>
#include "inventory.h"

//Fonction pour créer et initialiser l'invetaire à zéro 
void create_inventory(Inventory *stock)
{
    stock->count = 0;
}

//Fonction pour ajouter un item dans l'inventaire
void add_item(Inventory *stock, char *name, int quantity)
{
    int i = 0;
    //Dans cette boucle, on parcourt le nombre d'items présents dans l'inventaire, si l'objet existe déjà, on ajoute le nombre de fois voulu
    //l'objet dans l'inventaire et on sort ensuite avec return.
    for (i = 0; i < stock->count; i++) {
        if (strcmp(stock->items[i].name, name) == 0) {
            stock->items[i].quantity += quantity;
            return;
        }
    }
    //si l'inventaire n'est pas encore plein on ajoute un nouvel objet
    //on vérifie d'abord s'il y a de la place dans l'inventaire
    if (stock->count < MAX_ITEM) {
        //ensuite on copie le nom du nouvel objet dans le tableau 
        strncpy(stock->items[stock->count].name, name, sizeof(stock->items[stock->count].name) - 1); // sizeof pour éviter de dépasser la taille de notre tableau inventaire et 1 pour notre \0
        stock->items[stock->count].quantity = quantity; // stocker combien de fois on a cet objet
        stock->count++; // et on augmente notre compteur parce qu'on vient de rajouter un objet
    } else {
        printf("No more space in the inventory\n"); // si la condition n'est pas respectée c'est que le tableau est pleain et on affiche alors un message d'erreur
    }
}