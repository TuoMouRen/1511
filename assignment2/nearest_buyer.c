#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"

int bestbuyer(struct bot *b) {


//count the length of the world
    int loop_length = count_world(b);



    struct location *start = b->location;
    struct location *forwards = b->location;
    struct location *backwards = b->location;
    int distance = 0, quantity =  0, income = 0, distance_final = NO_BUYER;   // if there is no buyer meet the conditions, it will return NO_BUYER=-999





//forwards

    while ((distance == 0 || forwards != start) && distance <= loop_length) {
        struct commodity *forwards_name = forwards->commodity;
        if (forwards->type == LOCATION_BUYER  && strcmp(b->cargo->commodity->name,forwards_name->name) == 0 && forwards->quantity >= 0) {
        //need to match the type of the commodity in cargo// also the buyer must still want commodity and the quantity is not zero!

            if (forwards->quantity < b->cargo->quantity){ // find max quantity can be sold;
                quantity = forwards->quantity;
            } else {
                quantity = b->cargo->quantity;
            }
            int income_current = quantity * forwards->price; //current income now;
            if (income_current > income) { //check which buyer can make good profit!
                distance_final = distance;//record this buyer distance and quantity
                income = income_current;
            }
        }
        forwards = forwards->next;
        distance++;
    }






//backwards    
    distance = 0 ;  //reset
    while ((distance == 0 || backwards != start) && distance <= loop_length) {
        struct commodity *backwards_name = backwards->commodity;
        if (backwards->type == LOCATION_BUYER  && strcmp(b->cargo->commodity->name,backwards_name->name) == 0 && backwards->quantity >= 0) {
        //need to match the type of the commodity in cargo// also the buyer must still want commodity and the quantity is not zero!

            if (backwards->quantity < b->cargo->quantity){ // find max quantity can be sold;
                quantity = backwards->quantity;
            } else {
                quantity = b->cargo->quantity;
            }
            int income_current = quantity * backwards->price; //current income now;
            if (income_current > income) { //check which buyer can make good profit!
                distance_final = -distance;//record this buyer distance and quantity
                income = income_current;
            }
        }
        backwards = backwards->previous;
        distance++;
    }
 
    return distance_final;
}
