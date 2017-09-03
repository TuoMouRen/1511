#include <stdio.h>

int main (void) {    
  int a,b,c;
  printf("Enter your age: ");
  scanf("%d",&a);
  b=a/2+7;
  c=(a-7)*2;
  
  if(a>14) {
     printf("your dating range is %d to %d years old.\n",b,c);
  }
  else{
     printf("You are too young to be dating.\n");
  }
  return 0;
}
