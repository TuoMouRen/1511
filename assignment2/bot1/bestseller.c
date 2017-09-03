#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"


int bestseller(struct bot *b) {



    int n1 = 0, n2 = 0, n3 = 0;
//     n1=dis1   distance from currect location to bestseller
//     n2=profit usage is profit
//     n3=dis2   distance from bestseller and its cloest buyer + distance from currect location to bestseller
    int distance1 = 0, quantity = 0, distance2 = 0 ;
    int unit_price_buyer = 0, unit_price_seller = 0, profit = 0;
    int quantity_buyer = 0, quantity_seller = 0, quantity_bot = 0, quantity_bands;//bands=buyer and seller

//start from the first seller on the list below the current locations:
    struct location *start =  b->location;    
    struct location *seller_location = b->location;

//count the length of the world
    int loop_length = count_world(b); 





//loop through forward the world till we find a seller within 30move.
    while ((distance1 == 0||seller_location != start) && distance1 <= loop_length) { 
        
        if (seller_location->type == LOCATION_SELLER) { // find a seller
            //record unit_price and quantity left from the seller
            unit_price_seller = seller_location->price;
            quantity_seller = seller_location->quantity;            
            
            struct location *forwards = seller_location;
            struct location *backwards = seller_location;          
            struct commodity *commodity_info = seller_location->commodity;
            // loop through and find the closest buyer
            int count2 = 0;
            while (count2 == 0 || forwards != seller_location) {
                struct commodity *forwards_name = forwards->commodity;
                struct commodity *backwards_name = backwards->commodity;
                //check if its a buyer want the same commodity as the seller                
                if (forwards->type == LOCATION_BUYER && strcmp(commodity_info->name,forwards_name->name) == 0) { 
                    distance2 = count2;
                    unit_price_buyer = forwards->price;//record unit price from buyer
                    quantity_buyer = forwards->quantity;//record quantity buyer need now
                    break;
                }
                if (backwards->type == LOCATION_BUYER && strcmp(commodity_info->name,backwards_name->name) == 0) { 
                    distance2 = -count2;
                    unit_price_buyer = backwards->price;//record unit price from buyer
                    quantity_buyer = backwards->quantity;//record quantity buyer need now
                    break;
                }                
                count2 ++; //count distance from the seller to the buyer
                forwards = forwards->next;
                backwards = backwards->previous;
            }
            
            //find the max quantity can be bought from current buyer
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
        }       
        //start think if this is the best buy-sell loop.
        profit = (unit_price_buyer-unit_price_seller)*quantity;
        if (profit > n2) {
            n2 = profit;   //record profit
            n1 = distance1;//record distance from currect location to bestseller
            n3 = distance1 + distance2;// redcord total distance from current location to                 
        }
        
        seller_location = seller_location->next;
        distance1++; //count distance to the seller
    }
    






    
    seller_location = start;    
    distance1 = 0, quantity = 0, distance2 = 0;
//loop through backward the world till we find a seller within 30move.
    while ((distance1 == 0||seller_location != start) && distance1 <= loop_length) { 
        
        if (seller_location->type == LOCATION_SELLER) { // find a seller
            //record unit_price and quantity left from the seller
            unit_price_seller = seller_location->price;
            quantity_seller = seller_location->quantity;                  
           
            struct location *forwards = seller_location;
            struct location *backwards = seller_location;          
            struct commodity *commodity_info = seller_location->commodity;
            // loop through and find the closest buyer
            int count2 = 0;
            while (count2 == 0 || forwards != seller_location) {
                struct commodity *forwards_name = forwards->commodity;
                struct commodity *backwards_name = backwards->commodity;
                //check if its a buyer want the same commodity as the seller                
                if (forwards->type == LOCATION_BUYER && strcmp(commodity_info->name,forwards_name->name) == 0) { 
                    distance2 = count2;
                    unit_price_buyer = forwards->price;//record unit price from buyer
                    quantity_buyer = forwards->quantity;//record quantity buyer need now
                    break;
                }
                if (backwards->type == LOCATION_BUYER && strcmp(commodity_info->name,backwards_name->name) == 0) { 
                    distance2 = -count2;
                    unit_price_buyer = backwards->price;//record unit price from buyer
                    quantity_buyer = backwards->quantity;//record quantity buyer need now
                    break;
                }                
                count2 ++; //count distance from the seller to the buyer
                forwards = forwards->next;
                backwards = backwards->previous;
            }
            
            //find the max quantity can be bought from current buyer
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
        }       
        //start think if this is the best buy-sell loop.
        profit = (unit_price_buyer-unit_price_seller)*quantity;
        if (profit > n2) { //replace n2 with profit if profit larger than before one
            n2 = profit;   //record profit
            n1 = -distance1;//record distance from currect location to bestseller
            n3 = distance1 + distance2;// redcord total distance from current location to                 
        }
  
        seller_location=seller_location->previous;
        distance1++; //count distance to the seller
    }


    return n1;// this func only need to find best seller.
}
