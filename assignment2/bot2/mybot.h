#include "trader_bot.h"

#define NO_BUYER -999
#define ACTION_SELF_DESTRUCTION 999


int bestbuyer(struct bot *b);
int nearest_fuel(struct bot *b);
int quantity_buy(struct bot *b);
int fuel_need(struct bot *b, int distance);
int bestseller(struct bot *b);
int count_world(struct bot *b);
int nearest_dump(struct bot *b);
int get_profit(struct location *start, struct bot *b, struct commodity *cargo_name, int cargo_quantity, int unit_price_seller, int now2buyer);
int get_quantity(struct bot *b, int cargo_quantity);
int get_fuel_price(struct bot *b, int distance1, int now2buyer);






