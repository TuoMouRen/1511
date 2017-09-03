#include<stdio.h>
int main(void){

    int a,b,c,count1,count2,d,e;    
    printf("Enter number: ");
    scanf("%d",&a);
    b = 2;
    c = 1;   
    count1 = 0;
    count2 = 0;
    printf("The prime factorization of %d is:\n",a);
    while (b<=a){
        e = 1;       
        if (a%b == 0) {
            d = 2;                        
            while (d<b){
                if (b%d==0){            
                   e = 0;
                   d = d + 1;
                }else{
                    break; 
                    //just cant have another idea....                  
                }
            }
            if (e == 1){
                printf("%d",b);
            }
        }                
    b=b+1;
    } 
return 0;
} 
