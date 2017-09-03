#include "trader_bot.h"

#define NO_BUYER -999


int nearest_buyer(struct bot *b);
int nearest_fuel(struct bot *b);
int quantity_buy(struct bot *b);
int fuel_need(struct bot *b ,int distance);
int bestseller(struct bot *b);
int count_world(struct bot *b);
int nearest_dump(struct bot *b);
  
