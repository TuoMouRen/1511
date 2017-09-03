#include <stdio.h>
#include "trader_bot.h"
#include "mybot.h"

int nearest_dump(struct bot *b) {


    struct location *start = b->location;
    struct location *forwards = b->location;
    struct location *backwards = b->location;
    int distance = 0, dump_distance = 0;
    while (distance == 0 || forwards != start) {
        if (forwards->type == LOCATION_DUMP) {
            dump_distance = distance;
            break;
        }
        if (backwards->type == LOCATION_DUMP) {
            dump_distance = -distance;
            break;
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
    return dump_distance;
}
