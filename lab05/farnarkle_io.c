#include <stdio.h>
#include "farnarkle.h"

// read N_TILES tiles into array tiles
// return 1 if successful, 0 otherwise
int read_tiles(int tiles[N_TILES]) {
    int i=0;    
    while (i < N_TILES) {
        if (scanf("%d", &tiles[i]) == 1){
            i++;                                          
        }else{
            break;        
        }
    }    
    if (i==N_TILES){
        return 1;
    }else {
        return 0;
    }
}
// print tiles on a single line
void print_tiles(int tiles[N_TILES]) {
    int i;
    for (i=0;i < N_TILES;i++) {
        printf("%d ", tiles[i]);
    }
    printf("\n");

}
