#include <stdio.h>
int main(void) {
    
    int a, start, finish;
    printf("Enter start year: ");
    scanf("%d", &start);
    printf("Enter finish year: ");
    scanf("%d", &finish);
    a=start;
    printf("The leap years between %d and %d are: ",start,finish);
    while(a<finish+1) {
        if((a%4==0&&a%100!=0)||a%400==0) {
            printf("%d ",a);   
        }
        a=a+1;
    }
    printf("\n");
    return 0;
}
