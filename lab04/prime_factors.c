#include<stdio.h>
int main(void){

    int a,b,c,d;
    printf("Enter number: ");
    scanf("%d",&a);
    
    b=0;
    c=2;
    d=a;
    while(c<a){
        if(d%c==0){
            if(b==0){
                printf("The prime factorization of %d is:\n",a);
            }else{
                printf(" * ");
            }
            printf("%d",c);
            d=d/c;
            b++;
        }else{
            c++;
        }
    }
    if (b==0){
        printf("%d is prime\n",a);       
    }else{
        printf(" = %d\n",a);
    }
    return 0;
}        





