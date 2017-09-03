#include <stdio.h>
int main(void) {

    int a,b,c;
    printf("Square size: ");
    scanf("%d", &b);
    a=1;
    c=b*b;
    while(a<c+1) {
        printf("*");
        if (a%b==0) {
            printf("\n");
        }        
        a=a+1;    
    }

    return 0;
}
