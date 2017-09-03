#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"

int get_quantity(struct bot *b, int cargo_quantity) {


//count the length of the world
    int loop_length = count_world(b);

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;
    int distance = 0, quantity =  0, profit = 0;
    int quantity2buy = 0;





//forwards
    while ((distance == 0 || forwards != start) && distance <= loop_length) {
        struct commodity *forwards_name = forwards->commodity;
        if (forwards->type == LOCATION_BUYER  && start->commodity == forwards->commodity) {
        //need to match the type of the commodity in cargo// also the buyer must still want commodity and the quantity is not zero!

            if (forwards->quantity < cargo_quantity){ // find max quantity can be sold;
                quantity = forwards->quantity;
            } else {
                quantity = cargo_quantity;
            }


            int unit_price_buyer = forwards->price;
            int profit_current = (unit_price_buyer-start->price)*quantity; //current profit
            if (profit_current > profit) { //check which buyer can make good profit!
                //record this buyer profit
                profit = profit_current;
                quantity2buy = quantity;
            }
        }
        forwards = forwards->next;
        distance++;
    }




//backwards    
    distance = 0 ;  //reset
    while ((distance == 0 || backwards != start) && distance <= loop_length) {
        struct commodity *backwards_name = backwards->commodity;
        if (backwards->type == LOCATION_BUYER  && start->commodity == forwards->commodity) {
        //need to match the type of the commodity in cargo// also the buyer must still want commodity and the quantity is not zero!

            if (backwards->quantity < cargo_quantity){ // find max quantity can be sold;
                quantity = backwards->quantity;
            } else {
                quantity = cargo_quantity;
            }

            int unit_price_buyer = backwards->price;
            int profit_current = (unit_price_buyer-start->price)*quantity; //current profit
            if (profit_current > profit) { //check which buyer can make good profit!
                //record this buyer profit and quantity2buy 
                profit = profit_current;
                quantity2buy = quantity;
            }
        }
        backwards = backwards->previous;
        distance++;
    }
 
    return quantity2buy;
}
