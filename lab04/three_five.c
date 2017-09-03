#include<stdio.h>
int main(void){

    int a,b;    
    printf("Enter number: ");
    scanf("%d",&a);
    b = 1;    
    while (b<a){
        if (b%3 == 0||b%5 == 0) {
            printf("%d\n",b);
        }        
        b = b+1;
    }
        

return 0;
}
