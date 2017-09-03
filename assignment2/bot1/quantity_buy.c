#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"

int quantity_buy(struct bot *b) {
    int quantity = 999;

    struct location *current_location = b->location;    
    int quantity_buyer = 0;
    int quantity_seller = current_location->quantity;

    struct location *forwards = current_location;
    struct location *backwards = current_location;          
    struct commodity *commodity_info = current_location->commodity;
    // loop through and find the closest buyer    
    int count2 = 0;
    while (count2 == 0 || forwards != current_location) {
        struct commodity *forwards_name = forwards->commodity;
        struct commodity *backwards_name = backwards->commodity;
        //check if its a buyer want the same commodity as the seller                
        if (forwards->type == LOCATION_BUYER && strcmp(commodity_info->name,forwards_name->name) == 0) { 
            quantity_buyer = forwards->quantity;//record quantity buyer need now
            break;
        }
        if (backwards->type == LOCATION_BUYER && strcmp(commodity_info->name,backwards_name->name) == 0) { 
            quantity_buyer = backwards->quantity;//record quantity buyer need now
            break;
        }                
            count2 ++; //count distance from the seller to the buyer
            forwards = forwards->next;
            backwards = backwards->previous;
    }



    int quantity_bot = 0, quantity_bands = 0;
    int quantity_weight = b->maximum_cargo_weight / commodity_info->weight;
    int quantity_volume = b->maximum_cargo_volume / commodity_info->volume;
    if (quantity_weight < quantity_volume) {
        quantity_bot = quantity_weight;
    } else {
        quantity_bot = quantity_volume;
    }
    //find the max quantity bot can carry
    if (quantity_buyer < quantity_seller) {
        quantity_bands = quantity_buyer;
    } else {
        quantity_bands = quantity_seller;
    }
    //find the max quantity can be purchased from seller to buyer
    if (quantity_bands < quantity_bot) {
        quantity = quantity_bands;
    } else {
        quantity = quantity_bot;
    }
    //find the final max quantity can be bought
    return quantity;
}
