#include"trader_bot.h"
#include <stdio.h>

char *get_bot_name(void);
void get_action(struct bot *b, int *action, int *n){

    int nearest_dis;
    nearest_dis = nearest_fuel(b);
    if (nearest_dis == 0) {
        if (b->fuel < b->fuel_tank_capacity) {      //check if require fill the fuel
            *action = ACTION_BUY;
            *n = b->fuel_tank_capacity-b->fuel;
        } else {                                      // MOVE WITH FULL TANK
            *action = ACTION_MOVE;
            *n = b->maximum_move;
        }
    } else {
        *action = ACTION_MOVE;
        if (nearest_dis > b->maximum_move) {
            *n = b->maximum_move;
        } else {
            *n = nearest_dis;
        }
    }
}

char *get_bot_name(void) {
    return "Fuel Bot";
}
