#include <stdio.h>

int main (void) {    
  int a,b,c,d,e,f,g,h,i,k,p,l,m,year,emonth,edate;
  printf("Enter Year: ");
  scanf("%d",&year);


    a=year%19;
    b=year/100;
    c=year%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=(19*a+b-d-g+15)%30;
    i=c/4;
    k=c%4;
    l=(32+2*e+2*i-h-k)%7;
    m=(a+11*h+22*l)/451;
    emonth=(h+l-7*m+114)/31;
    p=(h+l-7*m+114)%31;
    edate=p+1;
    if (emonth==3) printf("Easter is March %d in %d.\n",edate,year);
    if (emonth==4) printf("Easter is April %d in %d.\n",edate,year);
  
return 0;
}

