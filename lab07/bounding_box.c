#include<stdio.h>
void get_bounding_box(int height, int width, int pixels[height][width],
int *start_row, int *start_column, int *box_height, int *box_width){
    int col,row,stop=0;
    for (row = 0;row < height;row++){
        for (col = 0;col < width;col++){
            if (pixels[row][col]==1){
                *start_row = row;
                stop=1;               
                break;
            }
        }
        if (stop==1){
            break;
        }
    }
    stop=0;
    for (col = 0;col < width;col++){
        for (row = 0;row<height;row++){
            if (pixels[row][col]==1){
                *start_column = col;
                stop=1;
                break;
            }
        }
        if (stop==1){
            break;
        }
    }
    stop=0;
    for (row = height-1;row>=0;row--){
        for (col = 0;col<width;col++){
            if (pixels[row][col]==1){
                *box_height=row-*start_row+1;
                stop=1;
                break;
            }
        }
        if (stop==1){
            break;
        }
    }
    stop=0;
    for (col = width-1;col>=0;col--){
        for (row = 0;row<height;row++){
            if (pixels[row][col]==1){
                *box_width=col-*start_column+1;
                stop=1;                        
                break;
            }
        }
        if (stop==1){                       
            break;   
        }
    }
}








    
