
#include <stdio.h>
#include "farnarkle.h"

// return number of arkles
int count_arkles(int tiles[N_TILES], int guess[N_TILES]) {
    int i,count[MAX_TILE]={0},arkles=0;
    for(i=0;i<N_TILES;i++){
        count[tiles[i]-1]++;
    } 
    for (i=0;i<N_TILES;i++){
            if (count[guess[i]-1]>0){
                count[guess[i]-1]--;        
                arkles++;
            }
    }
    arkles=arkles-count_farnarkles(tiles,guess);

    return arkles; 
}








