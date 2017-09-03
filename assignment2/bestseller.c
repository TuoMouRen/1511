#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"


int bestseller(struct bot *b) {



    int n1 = 0, n2 = 0, n3 = 0;
//     n1=dis1   distance from currect location to bestseller
//     n2=profit usage is profit
//     n3=dis2   distance from bestseller and its cloest buyer + distance from currect location to bestseller
    int distance1 = 0, quantity = 0;
    int unit_price_buyer = 0, unit_price_seller = 0, profit = 0;
    int quantity_buyer = 0, quantity_seller = 0, quantity_cash = 0, quantity_bot = 0;//bands=buyer and seller

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


            //find the max quantity can be bought from current buyer
            struct commodity *commodity_info = seller_location->commodity;
            int quantity_weight = b->maximum_cargo_weight / commodity_info->weight;
            int quantity_volume = b->maximum_cargo_volume / commodity_info->volume;
            quantity_cash = b->cash / seller_location->price; 
            if (quantity_weight < quantity_volume) {
                if (quantity_weight < quantity_cash) {
                    quantity_bot = quantity_weight;
                } else {
                    quantity_bot = quantity_cash;
                }                    
            } else {
                if (quantity_volume < quantity_cash) {
                    quantity_bot = quantity_volume;
                } else {
                    quantity_bot = quantity_cash;
                }  
            }
            //find the max quantity bot can carry

            if (quantity_bot < quantity_seller) {
                quantity = quantity_bot;
            } else {
                quantity = quantity_seller;
            }
            //find the max quantity can be purchased between seller and bot limits
            
            //start think if this is the best buy-sell loop.
            struct commodity *cargo_name = seller_location->commodity;
            profit = get_profit(seller_location, b, cargo_name, quantity, unit_price_seller,distance1);
            if (profit > n2) {
                n2 = profit;   //record profit
                n1 = distance1;//record distance from currect location to bestseller
                //n3 = distance1 + distance2;// redcord total distance from current location to                 
            }
        }        
        seller_location = seller_location->next;
        distance1++; //count distance to the seller
    }
    



 



/////////////////////////////////////////////////////////////////////






   
    seller_location = start;    
    distance1 = 0, quantity = 0;
//loop through backward the world till we find a seller within 30move.
    while ((distance1 == 0||seller_location != start) && distance1 <= loop_length) { 
        
        if (seller_location->type == LOCATION_SELLER) { // find a seller
            //record unit_price and quantity left from the seller
            unit_price_seller = seller_location->price;
            quantity_seller = seller_location->quantity;                  
           

            
            //find the max quantity can be bought from current buyer
            struct commodity *commodity_info = seller_location->commodity;
            int quantity_weight = b->maximum_cargo_weight / commodity_info->weight;
            int quantity_volume = b->maximum_cargo_volume / commodity_info->volume;
            quantity_cash = b->cash / seller_location->price; 
            if (quantity_weight < quantity_volume) {
                if (quantity_weight < quantity_cash) {
                    quantity_bot = quantity_weight;
                } else {
                    quantity_bot = quantity_cash;
                }                    
            } else {
                if (quantity_volume < quantity_cash) {
                    quantity_bot = quantity_volume;
                } else {
                    quantity_bot = quantity_cash;
                }  
            }
            //find the max quantity can be purchased from seller to buyer
            
            if (quantity_seller < quantity_bot) {
                quantity = quantity_seller; 
            } else {
                quantity = quantity_bot;
            }
            //find the final max quantity can be bought       

            //start think if this is the best buy-sell loop.
            struct commodity *cargo_name = seller_location->commodity;
            profit = get_profit(seller_location, b, cargo_name, quantity, unit_price_seller,distance1);
            if (profit > n2) {
                n2 = profit;   //record profit
                n1 = -distance1;//record distance from currect location to bestseller
                //n3 = distance1 + distance2;// redcord total distance from current location to                 
            }
        }  
        seller_location=seller_location->previous;
        distance1++; //count distance to the seller
    }


    return n1;// this func only need to find best seller.
}
