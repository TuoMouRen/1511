#include<stdio.h>
int main(void){
	int a,b,c;
    printf("Enter integer: ");
	scanf("%d",&a);
	printf("Enter integer: ");
	scanf("%d",&b);
	printf("Enter integer: ");
	scanf("%d",&c);

	printf("The integers in order are: %d %d %d\n",a*((b>=c&&c>a)||(c>b&&b>=a))+b*((a>=c&&c>b)||(c>=a&&a>b))+c*((a>=b&&b>=c)||(b>a&&a>=c)),a*((b>a&&a>=c)||(c>=a&&a>b))+b*((a>=b&&b>=c)||(c>b&&b>=a))+c*((a>c&&c>b)||(b>=c&&c>a)),a*((a>=b&&b>=c)||(a>=c&&c>b))+b*((b>a&&a>=c)||(b>=c&&c>a))+c*((c>b&&b>=a)||(c>a&&a>b)));
	  

	return 0;
}

