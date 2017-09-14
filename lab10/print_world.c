#include"trader_bot.h"
#include <stdio.h>
void print_world(struct bot *b){
    

    struct location *head = b->location ;
    while (head != NULL){
        if (head->type == LOCATION_START) {
            printf("%s: start\n",head->name);
        }else if (head->type == LOCATION_SELLER) {

            printf("%s: will sell %d units of %s for $%d\n",head->name,head->quantity,head->commodity->name,head->price);        
        }else if (head->type == LOCATION_BUYER) {

            printf("%s: will buy %d units of %s for $%d\n",head->name,head->quantity,head->commodity->name,head->price);      
        }else if (head->type == LOCATION_PETROL_STATION) {
            printf("%s: Petrol station %d units of available fuel for $%d\n",head->name,head->quantity,head->price);        
        }else if (head->type == LOCATION_DUMP) {
            printf("%s: dump\n",head->name);
        }else if (head->type == LOCATION_OTHER) {
            printf("%s: other\n",head->name);
        }
        
        head = head->next;
        if (head == b->location) {
            break;
        }    
    }   
}
