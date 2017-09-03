#include<stdio.h>
void print_image(int height, int width, int pixels[height][width]){
    int row,col;
    for (row = height-1;row>=0;row--){
        for (col=0;col<width;col++){
            if (pixels[row][col]==0){
                printf(".");
            }else if (pixels[row][col]==1){
                printf("*");
            }
        }
        printf("\n");    
    } 
}                
        
