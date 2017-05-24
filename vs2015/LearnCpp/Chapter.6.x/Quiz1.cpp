#include "stdafx.h"
#include <iostream>

enum Items
{
    HealthPotions,
    Torches,
    Arrows,
    MaxItems
};

int countTotalItems(int *carrying)
{
    int totalItems = 0;
    
    for(int i=0; i < MaxItems; i++)
    {
        totalItems += carrying[i];
    }

    return totalItems;
}

void quiz1()
{
    int carrying[MaxItems] { 2, 5, 10 };

    int total = countTotalItems(carrying);

    std::cout << total << std::endl;
}

/* Quiz time
 * 1) Pretend you’re writing a game where the player can hold 3 types of items : 
 * health potions, torches, and arrows.
 * Create an enum to identify the different types of items, and a fixed array to store the number 
 * of each item the player is carrying(use built - in fixed arrays, not std::array).The player 
 * should start with 2 health potions, 5 torches, and 10 arrows.Write a function called 
 * countTotalItems() that returns how many items the player has in total.Have your main() function 
 * print the output of countTotalItems().
 */