#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES],guess[N_TILES],farnarkles=0,turn =1;  
    create_random_tiles(hidden_sequence); 
     
    while (farnarkles !=N_TILES) { 
        printf("Enter guess for turn %d: ",turn); 
        if (read_tiles(guess) != 1) {  
            printf("Could not read guess\n");  
            return 1;  
        }  
        farnarkles=count_farnarkles(hidden_sequence, guess);  
        printf("%d farnarkles ", farnarkles);  
        printf("%d arkles\n", count_arkles(hidden_sequence,guess) );  
        turn ++;  
    }  
    printf("You win\n" );  
    return 0;  
} 
