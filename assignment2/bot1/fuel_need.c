#include <stdio.h>
#include "trader_bot.h"
#include "mybot.h"

int fuel_need(struct bot *b ,int distance){
    struct location *start =  b->location; 
    if (distance > 0) {
        for (int n = 0; n < distance; n++) {
            start = start->next;
        }
    } else {
        for (int n = 0; n > distance; n--) {
            start = start->previous;
        }  
    }   // set start to seller/dump
    
    //nearest fuel station from the seller/dump:
    
    struct location *forwards = start;
    struct location *backwards = start;
    int distance2 = 0,distance_final = 0;
    while (distance2 == 0 || forwards != start) {
        if (forwards->type == LOCATION_PETROL_STATION) {
            distance_final = distance2;
            break;
        }
        if (backwards->type == LOCATION_PETROL_STATION) {
            distance_final = -distance2;
            break;
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance2++;
    }
return distance_final;
}
