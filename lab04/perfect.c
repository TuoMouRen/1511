#include<stdio.h>
int main(void){
    
    int number,b,c;
    printf("Enter number: ");
    scanf("%d",&number);
    counter = 1;
    sum = 0;
    printf("The factors of %d are:\n",number);   
    while (counter<=number){             
        if (number % counter == 0){
            printf("%d\n",counter);
            sum += counter;        
        }       
        counter++;
    }    
    printf("Sum of factors = %d\n",sum);    
    if (number%2 == 0) {
        printf("%d is a perfect number\n",number);
    } else {
        printf("%d is not a perfect number\n",number);
    }

return 0;
}
