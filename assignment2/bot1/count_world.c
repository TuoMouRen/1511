#include <stdio.h>
#include "trader_bot.h"
#include "mybot.h"

int count_world(struct bot *b){
    struct location *start =  b->location;
    struct location *count = b->location;
    int length = 0;
    while (length == 0||count != start){ //count how many movements need to be done to run through the whole map.
        length++;
        count = count->next;
    }
//need to find half of the length to cover the whole map, but no duplicates when take into the forwards and backwards loops in the bestseller or bestbuyer
    int loop_length = 0; 
    if (length%2 == 0) { 
        loop_length = length/2;
    } else {
        loop_length = length/2 + 1;    
    }
    return loop_length;
}
 
