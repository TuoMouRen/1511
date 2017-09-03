#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include "mybot.h"


char *get_bot_name(void) {
    return "C H I N A     NO .1";
}

void get_action(struct bot *b, int *action, int *n) {




    struct location *now = b->location;
// if in a fuel station and fuel is no full 
    if (now->type == LOCATION_PETROL_STATION && b->fuel != b->fuel_tank_capacity && now->quantity >= b->fuel_tank_capacity/2) {
        *action = ACTION_BUY;
        int fuel_used = b->fuel_tank_capacity-b->fuel;
        if (now->quantity > fuel_used) {       //check the max quantity of fuel can be bought!
            if (fuel_used < b->cash/now->price) {       
                *n = fuel_used;
            }else{
                *n = b->cash/now->price;
            }
        } else {
            if (now->quantity < b->cash/now->price) {       
                *n = now->quantity;
            }else{
                *n = b->cash/now->price;
            }
        }


// cargo has no commodity: 
    }else if (b->cargo == NULL) {
        int distance1/*to best seller*/ = bestseller(b);
            printf("%d",distance1);
        if (b->turns_left <= 6) {   // stop buy anything when it only 4 turns left because each sell-buy loop will need(ACTION_MOVE,ACTION_BUY,ACTION_MOVE,ACTION_SELL) 4 turns at least(one ACTION_MOVE no more than maximum_move )
            *action =ACTION_MOVE;
            *n = 0;
        

        } else if (distance1 != 0) { // not at the seller
            int fuel_require = fuel_need(b,distance1);
            if (abs(distance1)+abs(fuel_require) <= b->fuel) { 
            //if the current fuel_left will make bot to the fuel station after action buy then move to seller first
                *action = ACTION_MOVE;
                *n = distance1;
            } else {
                *action = ACTION_MOVE;
                *n = nearest_fuel(b);    
            }        
        } else if (distance1 == 0){
            *action = ACTION_BUY;
            *n = quantity_buy(b);
        }





// cargo has commodity:
    } else if (b->cargo != NULL){
        int distance2/*to nearst buyer*/ =bestbuyer(b);
        if (now->type == LOCATION_DUMP && distance2 == NO_BUYER) {  //"-999" means if no buyer meet the conditions(in bestbuyer function)
            *action = ACTION_DUMP;      
        
        }else if (distance2 != 0 && distance2 != NO_BUYER) {   //not at the buyer
            int fuel_require = fuel_need(b,distance2);
            if (abs(distance2)+abs(fuel_require) <= b->fuel) { 
                *action = ACTION_MOVE;
                *n = distance2;
            } else {
                *action = ACTION_MOVE;
                *n = nearest_fuel(b);                
            }

        } else if (distance2 == 0) {
            if (now->quantity >= b->cargo->quantity) { // check if the buyer still wanna buy my commodity; 
                *action = ACTION_SELL;
                *n = b->cargo->quantity;
            } else if (now->quantity != 0) {
                *action = ACTION_SELL;
                *n = now->quantity;
            } else if (now->quantity == 0) {
                int dump_distance = nearest_dump(b);
                int fuel_require = fuel_need(b,dump_distance);
                if (abs(dump_distance)+abs(fuel_require) <= b->fuel) { 
                    *action = ACTION_MOVE;
                    *n = dump_distance;
                } else {
                    *action = ACTION_MOVE;
                    *n = nearest_fuel(b);
                }
            }        

        } else if (distance2 == NO_BUYER){
            int dump_distance = nearest_dump(b);
            int fuel_require = fuel_need(b,dump_distance);
            if (abs(dump_distance)+abs(fuel_require) <= b->fuel) { 
                *action = ACTION_MOVE;
                *n = dump_distance;
            } else {
                *action = ACTION_MOVE;
                *n = nearest_fuel(b);
            }
        }

    }

}

