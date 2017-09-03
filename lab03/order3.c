#include<stdio.h>
int main(void){
	int a,b,c;
    printf("Enter integer: ");
	scanf("%d",&a);
	printf("Enter integer: ");
	scanf("%d",&b);
	printf("Enter integer: ");
	scanf("%d",&c);

	if (a>=b&&b>=c){
	    printf("The integers in order are: %d %d %d\n",c,b,a);
    }   else if (a>=c&&c>b){
	    printf("The integers in order are: %d %d %d\n",b,c,a);
    }	else if (b>a&&a>=c){
		printf("The integers in order are: %d %d %d\n",c,a,b);
    }	else if (b>=c&&c>a){
		printf("The integers in order are: %d %d %d\n",a,c,b);
    }	else if (c>b&&b>=a){
		printf("The integers in order are: %d %d %d\n",a,b,c);
   	}	else if (c>=a&&a>b){
	    printf("The integers in order are: %d %d %d\n",b,a,c);
    }



	return 0;
}

