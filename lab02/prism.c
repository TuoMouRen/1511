#include <stdio.h>

int main (void) {

int length,width,height,volume,area,edgelength;
    printf("Please enter prism length: ");
    scanf("%d", &length);
    
    printf("Please enter prism width: ");
    scanf("%d", &width);
    
    printf("Please enter prism height: ");
    scanf("%d", &height);
    
    volume=length*width*height;
    area=2*(length*width+length*height+width*height);
    edgelength=4*(length+width+height);
    
    
    printf("A prism with sides %d %d %d has:\nvolume=%d\nArea=%d\nEdge length=%d\n",length,width,height,volume,area,edgelength);

    return 0;
}

