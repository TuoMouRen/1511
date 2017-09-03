#include <stdio.h>
#include "farnarkle.h"

// return number of farnarkles
int count_farnarkles(int tiles[N_TILES], int guess[N_TILES]) {
    int i,count=0;
    for(i=0;i<N_TILES;i++){
        if (tiles[i]==guess[i]){
            count++;
        }
    }    
    return count;
}
    

