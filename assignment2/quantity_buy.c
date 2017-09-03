#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"

int quantity_buy(struct bot *b) {
    int quantity = 999;
    struct location *current_location = b->location;
    struct commodity *commodity_info = current_location->commodity;
    int quantity_seller = current_location->quantity;




    int quantity_bot = 0, quantity_bands = 0;
    int quantity_weight = b->maximum_cargo_weight / commodity_info->weight;
    int quantity_volume = b->maximum_cargo_volume / commodity_info->volume;
    if (quantity_weight < quantity_volume) {
        quantity_bot = quantity_weight;
    } else {
        quantity_bot = quantity_volume;
    }

    //find the max quantity bot can carry
    if (quantity_bot > quantity_seller) {
        quantity_bands = quantity_seller;
    } else {
        quantity_bands = quantity_bot;
    }

    int a = get_quantity(b, quantity_bands);
    int c = (b->cash - get_fuel_price(b, 0, 0))/current_location->price;
    if (a>c) {
        quantity=c;
    }else{
        quantity=a;  
    }      
    
    
    //find the final max quantity can be bought
    return quantity;
}
