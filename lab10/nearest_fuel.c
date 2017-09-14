#include"trader_bot.h"
#include <stdio.h>
int nearest_fuel(struct bot *b){
    struct location *head = b->location ;
    int countback = 0, countfor = 0;// count ++ (forwards and backwards) of each location until it reach the fuel station

//forwards;
    while (head != NULL){
        if(head->type != LOCATION_PETROL_STATION) {
            countfor++;
            head = head->next;
        } else if (head->type == LOCATION_PETROL_STATION) {
            //countfor++;
            break;
        }
    }   

//backwards;
    head = b->location ;//reset head;
    while (head != NULL){
        if(head->type != LOCATION_PETROL_STATION) {
            countback++;
            head = head->previous;
        } else if (head->type == LOCATION_PETROL_STATION) {
            //countback++;
            break;
        }
    }

//check nearest distance
    if(countback >= countfor) {
        return countfor;
    } else {
        return -countback;
    }

}

