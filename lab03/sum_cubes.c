#include <stdio.h>
int main(void) {
    
    int count,a,b,sum;
    printf("Sum how many cubes? ");
    scanf("%d",&count);
    a=1;
    sum=0;
    while (a<count+1){
        b=a*a*a;
        if (a==count) {
            printf("%d^3 ",a);
        } else { 
            printf("%d^3 + ",a);
        }        
        a=a+1;           
        sum=sum+b;
    }
    printf("= %d\n",sum);
    return 0;
}
