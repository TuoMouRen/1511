#include <stdio.h>
int main(void) {
    
    int count,a,b;
    printf("Enter how many cubes: ");
    scanf("%d",&count);
    a=1;
    while (a<count+1){
        b=a*a*a;
        printf("%d^3 = %d\n",a,b);
        a=a+1;
        
    }

    return 0;
}
