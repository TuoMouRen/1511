#include <stdio.h>
#include <math.h>
int main (void) {

double a,b,c,s,area;
   
    printf("Enter side 1: ");
    scanf("%lf", &a);
    
    printf("Enter side 2: ");
    scanf("%lf", &b);
    
    printf("Enter side 3: ");
    scanf("%lf", &c);
      
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    
    if (!(a+b>c&&a+c>b&&b+c>a)){
        printf("Error: triangle inequality violated.\n");
    } else{
        printf("Area=%lf\n",area);
    }
    return 0;
}

