#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include "mybot.h"

// return distance to nearest fuel station
// if nearest fuel station is backwards return negative int
// if nearest fuel is current location return 0

int get_fuel_price(struct bot *b, int seller2buyer, int now2seller) {


    struct location *test =  b->location; 
    if ( seller2buyer > 0) {
        for (int count = 0; count < seller2buyer; count++) {
            test = test->next;
        }
    } else if (seller2buyer < 0){
        for (int count = 0; count > seller2buyer; count--) {
            test = test->previous;
        }
    }           // set test to buyer



    struct location *start = test;
    struct location *forwards = test;
    struct location *backwards = test;
    int distance = 0, n = 0, price = 0;
    while (distance == 0 || forwards != start) {
        if (forwards->type == LOCATION_PETROL_STATION && forwards->quantity >= b->fuel_tank_capacity/2 ) { // find the one with plenty fuel left, 
            n = distance;
            price = forwards -> price; 
            break;
        }
        if (backwards->type == LOCATION_PETROL_STATION && backwards->quantity >= b->fuel_tank_capacity/2) {
            n = -distance;
            price = backwards -> price;
            break;
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }

    int get_price = price*(abs(n)+abs(seller2buyer)+abs(now2seller));





    return get_price;
}
