#include <stdio.h>
#include "trader_bot.h"
#include "mybot.h"

// return distance to nearest fuel station
// if nearest fuel station is backwards return negative int
// if nearest fuel is current location return 0

int nearest_fuel(struct bot *b) {

    // locations are linked in a circular list
    // move a pointer forwards around list
    // and move a pointer backwards around the list
    // stop when either reaches a PETROL_STATION and also make sure it has fuel left!

    struct location *start = b->location;
    struct location *forwards = b->location;
    struct location *backwards = b->location;
    int distance = 0, n = 0;
    while (distance == 0 || forwards != start) {
        if (forwards->type == LOCATION_PETROL_STATION && forwards->quantity >= b->fuel_tank_capacity/2 ) { // find the one with plenty fuel left, 
            n = distance;
            break;
        }
        if (backwards->type == LOCATION_PETROL_STATION && backwards->quantity >= b->fuel_tank_capacity/2) {
            n = -distance;
            break;
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
    return n;
}
