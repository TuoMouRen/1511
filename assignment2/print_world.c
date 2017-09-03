#include <stdio.h>
#include "trader_bot.h"

// print details of all locations in the Trader Bot world
// starting from bot's current location and going forwards
void print_world(struct bot *b) {

    struct location *bot_location = b->location;
    int n_printed = 0; // sentinal variable for loop

    // locations are linked in a circular list
    struct location *l =  bot_location;
    while (n_printed == 0 || l != bot_location) {
        printf("%s: ", l->name);
        if (l->type == LOCATION_START) {
            printf("start\n");
        } else if (l->type == LOCATION_BUYER) {
            printf("will buy %d units of %s for $%d\n" , l->quantity, l->commodity->name, l->price);
        } else if (l->type == LOCATION_SELLER) {
            printf("will sell %d units of %s for $%d\n" , l->quantity, l->commodity->name, l->price);
        } else if (l->type == LOCATION_PETROL_STATION) {
            printf("Petrol station %d units of available fuel for $%d\n", l->quantity, l->price);
        } else if (l->type == LOCATION_DUMP) {
            printf("dump\n");
        } else if (l->type == LOCATION_OTHER) {
            printf("other\n");
        }
        l = l->next;
        n_printed++;
    }
}
