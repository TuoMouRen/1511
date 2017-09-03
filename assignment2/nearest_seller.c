#include <stdio.h>
#include "trader_bot.h"
#include "mybot.h"

int nearest_seller(struct bot *b) {

    // locations are linked in a circular list
    // move a pointer forwards around list
    // and move a pointer backwards around the list
    // stop when either reaches a seller

    struct location *start = b->location;
    struct location *forwards = b->location;
    struct location *backwards = b->location;
    int distance = 0;
    while (distance == 0 || forwards != start) {
        if (forwards->type == LOCATION_SELLER) {
            return distance;
        }
        if (backwards->type == LOCATION_SELLER) {
            return -distance;
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
}
