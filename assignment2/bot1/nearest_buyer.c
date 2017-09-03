#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "mybot.h"

int nearest_buyer(struct bot *b) {

    // locations are linked in a circular list
    // move a pointer forwards around list
    // and move a pointer backwards around the list
    // stop when either reaches a buyer

    struct location *start = b->location;
    struct location *forwards = b->location;
    struct location *backwards = b->location;
    int distance = 0,   distance_final = NO_BUYER;   // if there is no buyer meet the conditions, it will return NO_BUYER = -999
    while (distance == 0 || forwards != start) {
        struct commodity *forwards_name = forwards->commodity;
        struct commodity *backwards_name = backwards->commodity;
        if (forwards->type == LOCATION_BUYER  && strcmp(b->cargo->commodity->name,forwards_name->name) == 0 && forwards->quantity >= b->cargo->quantity) {
            distance_final = distance;                     //need to match the type of the commodity in cargo // also the buyer must still want commodity and the quantity is no less than that in cargo!
            break;        
        }
        if (backwards->type == LOCATION_BUYER && strcmp(b->cargo->commodity->name,backwards_name->name) == 0 && backwards->quantity >= b->cargo->quantity) {
            distance_final = -distance;
            break;        
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
    return distance_final;
}
